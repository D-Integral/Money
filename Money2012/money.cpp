//
//  money.cpp
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
#include "money.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
money::money() // Конструктор
{}

money::money(char s[MAX_SIZE]) // Конструктор
{strncpy(moneyString, s, MAX_SIZE);}

void money::get() // Получение числа
{
    cin.get(moneyString, MAX_SIZE);
}

void money::get(bool not_first) // Получение числа
{
    bool getControl;
    // При true необходимо поглотить предшествовавший ввод
    getControl = not_first; // При true ввод через cin уже не первый
    if (getControl == true)
    {cin.get();}
    cin.get(moneyString, MAX_SIZE);
}

void money::show() const // Вывод числа
{
    cout << moneyString;
}

////////////////////////////////////////////////////////////////////////////////
money::money(long double sum)
// Конструктор приведения числа long double в денежный формат
{
    char numbersString[MAX_NUMBERS];
    // Строка с числом, состоящим только из цифр и десятичной точки
    long double subtrahand = 100000000000000;
    bool neg = false;
    if (sum<0)
    {
        sum *= -1;
        neg = true;
    }
    int counter;
    int i; // Техническая переменная
    if (sum > 999999999999999.00)
    {sum = 999999999999999.00;}
    for (i = 0; i < 15; i++)
    {
        counter = 0;
        while ((sum >= 1)&&(sum >= subtrahand))
        {
            sum -= subtrahand;
            counter++;
        }
        numbersString[i] = static_cast<char>(counter+48);
        subtrahand /= 10;
    }
    numbersString[15] = '.';
    for (i = 16; i <= 17; i++)
    {
        counter = 0;
        while ((sum > 0)&&(sum >= subtrahand))
        {
            sum -= subtrahand;
            counter++;
        }
        numbersString[i] = static_cast<char>(counter+48);
        subtrahand /= 10;
    }
    numbersString[18] = '\0';
    int first_non_zero = 0; // Поиск первого ненулевого символа строки
    while ((numbersString[first_non_zero] == '0')&&(first_non_zero<14))
    {first_non_zero++;}
    int res_pos = 0; // Текущая позиция итоговой строки
    if (neg == true)
    {
        moneyString[res_pos++] = '-';
    }
    moneyString[res_pos++] = '$';
    for (i = first_non_zero; i < MAX_NUMBERS; i++)
        // Формирование итоговой строки
    {
        moneyString[res_pos++] = numbersString[i];
        if ((i == 2)||(i == 5)||(i == 8)||(i == 11))
        {
            moneyString[res_pos++] = ',';
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
long double money::to_long_double() const
// Приведение строки в денежном формате к типу long double
{
    char myString[MAX_SIZE];
    strcpy(myString, moneyString);
    unsigned long factSize; // Общее количество знаков в строке
    int factNumbers = 0; // Количество цифр плюс десятичная точка
    factSize = strlen(myString);
    char numbersString[MAX_NUMBERS];
    // Строка с числом, состоящим только из цифр и десятичной точки
    int i; // Техническая переменная
    for (i = 0; i < factSize; i++)
    {
        switch(myString[i])
        {
            case '0':
                numbersString[factNumbers++] = myString[i];
                break;
            case '1':
                numbersString[factNumbers++] = myString[i];
                break;
            case '2':
                numbersString[factNumbers++] = myString[i];
                break;
            case '3':
                numbersString[factNumbers++] = myString[i];
                break;
            case '4':
                numbersString[factNumbers++] = myString[i];
                break;
            case '5':
                numbersString[factNumbers++] = myString[i];
                break;
            case '6':
                numbersString[factNumbers++] = myString[i];
                break;
            case '7':
                numbersString[factNumbers++] = myString[i];
                break;
            case '8':
                numbersString[factNumbers++] = myString[i];
                break;
            case '9':
                numbersString[factNumbers++] = myString[i];
                break;
            case '.':
                numbersString[factNumbers++] = myString[i];
                break;
            case '-':
                numbersString[factNumbers++] = myString[i];
                break;
        }
    }
    numbersString[factNumbers] = '\0';
    return strtold(numbersString, NULL);
}
////////////////////////////////////////////////////////////////////////////////
money money::operator+(money m2) const
// Сложение двух чисел в денежном формате
{
    long double m1_ld, m2_ld, sum_ld;
    char m1_str[MAX_SIZE];
    strcpy(m1_str, moneyString);
    money m1(m1_str);
    m1_ld = m1.to_long_double();
    m2_ld = m2.to_long_double();
    sum_ld = m1_ld + m2_ld;
    // Приводим эти числа к типу long double, а затем складываем
    return money(sum_ld);
    // Переводим обратно в формат money и в нём возвращаем
}

////////////////////////////////////////////////////////////////////////////////
money money::operator-(money m2) const
// Вычитание одного числа в денежном формате из другого
{
    long double m1_ld, m2_ld, res_ld;
    char m1_str[MAX_SIZE];
    strcpy(m1_str, moneyString);
    money m1(m1_str);
    m1_ld = m1.to_long_double();
    m2_ld = m2.to_long_double();
    res_ld = m1_ld - m2_ld;
    // Приводим эти числа к типу long double, а затем производим вычитание
    return money(res_ld);
    // Переводим обратно в формат money и в нём возвращаем
}

////////////////////////////////////////////////////////////////////////////////
money money::operator/(long double divider) const
// Деление числа в денежном формате на вещественное число
{
    long double m_ld, res_ld;
    char m_str[MAX_SIZE];
    strcpy(m_str, moneyString);
    money m(m_str);
    m_ld = m.to_long_double();
    res_ld = m_ld / divider;
    // Приводим число в денежном формате к типу long double, а затем делим
    return money(res_ld);
    // Переводим обратно в формат money и в нём возвращаем
}

////////////////////////////////////////////////////////////////////////////////
money money::operator*(long double multiplyer) const
// Умножение числа в денежном формате на вещественное число
{
    long double m_ld, res_ld;
    char m_str[MAX_SIZE];
    strcpy(m_str, moneyString);
    money m(m_str);
    m_ld = m.to_long_double();
    res_ld = m_ld * multiplyer;
    // Приводим число в денежном формате к типу long double, а затем умножаем
    return money(res_ld);
    // Переводим обратно в формат money и в нём возвращаем
}

////////////////////////////////////////////////////////////////////////////////
long double operator/(money m1, money m2)
// Деление одного числа в денежном формате на другое,
// или деление числа long double на число в денежном формате
{
    long double m1_ld, m2_ld, res_ld;
    m1_ld = m1.to_long_double();
    m2_ld = m2.to_long_double();
    res_ld = m1_ld / m2_ld;
    // Приводим эти числа к типу long double, а затем делим
    return res_ld;
}

////////////////////////////////////////////////////////////////////////////////
money operator*(long double mp, money m)
// Деление одного числа в денежном формате на другое,
// или деление числа long double на число в денежном формате
{
    long double m_ld, res_ld;
    m_ld = m.to_long_double();
    res_ld = mp * m_ld;
    // Приводим эти числа к типу long double, а затем делим
    return money(res_ld);
}
