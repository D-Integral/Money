//
//  money.hpp
//  Money2012
//
//  Created by Dmytro Skorokhod on 10/03/2012.
//

// Роберт Лафоре: "Объектно-ориентированное программирование в C++"
// Глава 11, упражнение 6
// Класс money для работы с денежными значениями
#include <iostream>
#include <curses.h>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
class money
{
private:
    static const int MAX_NUMBERS = 19; // Максимум цифр в строке
    static const int MAX_SIZE = (MAX_NUMBERS+((MAX_NUMBERS-2)/3)+2);
    // Максимум знаков в строке
    char moneyString[MAX_SIZE];
    // Строка с числом в денежном формате
public:
    money(); // Конструктор
    explicit money(char s[MAX_SIZE]); // Конструктор
    money(long double sum);
    // Конструктор приведения числа long double в денежный формат
    void get(); // Получение числа
    void get(bool not_first); // Получение числа
    void show() const; // Вывод числа
    money operator+(money m2) const;
    // Сложение двух чисел в денежном формате
    money operator-(money m2) const;
    // Вычитание одного числа в денежном формате из другого
    money operator/(long double) const;
    // Деление числа в денежном формате на вещественное число
    money operator*(long double) const;
    // Умножение числа в денежном формате на вещественное число
    long double to_long_double() const;
    // Приведение строки в денежном формате к типу long double
    friend long double operator/(money m1, money m2);
    // Деление одного числа в денежном формате на другое,
    // или деление числа long double на число в денежном формате
    friend money operator*(long double mp, money m);
    // Умножение числа long double на деньги
};
