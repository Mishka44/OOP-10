// ООП-10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>
#include<list>
#include <deque>
#include <random>
#include<vector>
#include <cstdlib>




class Franction {
public:
    bool sigh;
    unsigned numerator;
    unsigned denominator;
    bool operator < (const Franction& other)const {
        if (this->sigh) {
            if (!other.sigh) {
                return 1;

            }
            else {
                // привести к общему знаменателю
                // вернуть то число, у которого больше чис
                return (this->numerator <
                    other.numerator) ? true : false; // ?- тернарный оператор (условие) ? первое значение : второе значение
            }
        }
        else {
            if (other.sigh) {
                return 0;
            }
            else {
                return (this->numerator < other.numerator) ? true : false;
            }
        }

    }

};
#include <type_traits>
namespace std {
    template<>
    struct hash<Franction> {
        std::size_t operator() (const Franction& obj)const {
            using std::size_t;
            using std::hash;
            return (( (hash <unsigned>()(obj.denominator)^
                (hash<unsigned>() (obj.numerator) << 1))^ //  <<1  -оператор битового сдвига 
                                                                 //  во избежание совпадений, сдвигаем результат каждого хеширования
                (hash <bool>() (obj.sigh) >> 1) ));
        }
    };
}

//___________(*^ _ ^*)_____________________________________________________________________________________________
// занятие от 16.11.2023 

// библиотека algorithm


int Get_num() {
    static std::random_device rd;
    std::uniform_int_distribution<int> distr(-10, 10);

    return distr(rd);
}
int Get_num2() {
    static std::random_device rd;
    std::uniform_int_distribution<int> distr(0, 20);

    return distr(rd);
}





int main()
{

   /* std::set <Franction> coll;
    coll.insert(Franction{ true, 1, 5 });*/

    //_______________________________________

    std::vector <int> arr(20); // -10, +10
    std::vector<int> arr2(20); // 0, 20
    


    std::generate(arr.begin(), arr.end(),Get_num);
    std::generate(arr2.begin(), arr2.end(), Get_num2);

    std::stable_sort(arr.begin(), arr.end());
    std::stable_sort(arr2.begin(), arr2.end());


    for (auto& i : arr)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    for (auto& i : arr2)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    std::vector<int> arr3;
    for (int i = 0; i < arr.size(); i++) {
        auto res = std::find(arr2.begin(), arr2.end(), arr[i]);
        if (res != arr2.end()) {
            arr3.push_back(*res);
            }
    }
    for (auto& i : arr3)
    {
        std::cout << i << ", ";
    }

    //std::fill(array.begin(), array.end(), 5);

    //std::generate(array.begin(), array.end(), Get_num);
    //std::shuffle(array.begin(), array.end(), std::random_device());

    //for (auto& i : array)
    //{
    //    std::cout << i << ", ";
    //}
    //std::cout << "\n";

    //std::stable_sort(array.begin(), array.end());
    //for (auto& i : array)
    //{
    //    std::cout << i << ", ";
    //}


    //std::cout << "\n";

    //auto res = std::find(array.begin(), array.end(), 5);

    //std::cout << "\n";
    ////std::rfind если не нашёл, то возвращает array.end()

    //if (res != array.end()) {
    //    std::cout << *res << "was found" << &(*res);
    //}
    //int arr[]{1, 4, 60, -17};
    //std::cout << std::max_element(&arr[0], arr+4);
    return 0;

}


