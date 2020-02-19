#pragma once

#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
#include <string>

///Шаблон классa has_Begin_End
/*!
    Позволяет определить есть ли у типа переданного к качестве шаблонного параметра методы begin() и end()
*/
template<typename T>
class has_Begin_End
{   
        static char detect (...);   ///< Перегруженный метод, на принятие любых параметров и возвращении char

        template<typename U>
        static auto detect (U)->decltype(std::declval<U>().begin(), std::declval<U>().end(), void()); ///< Шаблон перегруженного метода на принятие типа, у которого есть методы begin() и end(), если есть, то инстанцируется функцией возращающей void

    public:
        static constexpr bool value = std::is_same<void, decltype(detect(std::declval<T>()))>::value;   ///< Если у проверяемого типа есть методы begin() и end() то value - true
};


///Шаблонн функции печати для контейнеров
/*!
   Шаблон инстанцируется если у переданного типа есть методы begin() и end(), наличие которых проверяет структура has_Begin_End
*/
template<typename T>
typename std::enable_if<has_Begin_End<T>::value, void>::type 
printIP (const T& t)
{
    for(auto ip_part = t.cbegin(); ip_part != t.cend(); ++ip_part)
            {
                if (ip_part != t.cbegin())
                {
                    std::cout << ".";
                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
}

///Шаблонн функции печати для интегральных типов
/*!
   Шаблон инстанцируется если переданный тип является интегральным
*/
template<typename T>
typename std::enable_if<std::is_integral<typename std::remove_reference<T>::type>::value, void>::type 
printIP (const T& t)
{   
    constexpr int s =sizeof(t);
    std::vector<int> vec;
    for (auto i = 0;i < s;++i)
    {
        vec.insert(vec.begin(),(t >> 8*i) & 0xFF);
    }
    printIP(vec);
}

///Перегрузка функции печати для строк
/*!
   При передачи функции в качестве аргумента типа std::string, ни один из предложенных шаблонов не подойдет(инстанцирования не будет), то выбор падает на рассмотрении конкретных реализаций, в частности на данную функцию с принимаемым аргументом типа std::string
*/
void printIP (const std::string& t)
{
    std::cout << t << std::endl;
}