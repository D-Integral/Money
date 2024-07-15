//
//  main.cpp
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

int main(int argc, const char * argv[]) {
    money m_1, m_2; // Значения в денежном формате, введённые пользователем
    money m_res; // Результат операции в денежном формате
    long double ld_mp, ld_dv, ld_for_divide; // Множитель, делитель, делимое
    long double ld_res; // Результат операции в формате long double
    char answer; // Ответ пользователя
    bool not_first = false;
    do { // Получение денежных сумм от пользователя и их обработка
        cout << "Input the first money sum (in format $9,999.99): " << endl;
        m_1.get(not_first);
        not_first = true;
        cout << "Input the second money sum (in the same format): " << endl;
        m_2.get(not_first);
        cout << "Input the multiplyer (in format 1.35): " << endl;
        cin >> ld_mp;
        cout << "Input the divider (in the same format): " << endl;
        cin >> ld_dv;
        cout << "Input the long double sum for divide it: " << endl;
        cin >> ld_for_divide;
        m_res = m_1 + m_2;
        cout << endl;
        m_1.show();
        cout << " + ";
        m_2.show();
        cout << " = ";
        m_res.show();
        cout << endl << endl;
        m_res = m_1 - m_2;
        m_1.show();
        cout << " - ";
        m_2.show();
        cout << " = ";
        m_res.show();
        cout << endl << endl;
        ld_res = m_1 / m_2;
        m_1.show();
        cout << " / ";
        m_2.show();
        cout << " = ";
        cout << ld_res;
        cout << endl << endl;
        m_res = m_1 / ld_dv;
        m_1.show();
        cout << " / ";
        cout << ld_dv;
        cout << " = ";
        m_res.show();
        cout << endl << endl;
        m_res = m_2 / ld_dv;
        m_2.show();
        cout << " / ";
        cout << ld_dv;
        cout << " = ";
        m_res.show();
        cout << endl << endl;
        m_res = m_1 * ld_mp;
        m_1.show();
        cout << " * ";
        cout << ld_mp;
        cout << " = ";
        m_res.show();
        cout << endl << endl;
        m_res = m_2 * ld_mp;
        m_2.show();
        cout << " * ";
        cout << ld_mp;
        cout << " = ";
        m_res.show();
        cout << endl << endl;
        ld_res = ld_for_divide / m_1; // Делим long double на деньги
        cout << ld_for_divide << " / ";
        m_1.show();
        cout << " = " << ld_res;
        cout << endl << endl;
        ld_res = ld_for_divide / m_2; // Делим long double на деньги
        cout << ld_for_divide << " / ";
        m_2.show();
        cout << " = " << ld_res;
        cout << endl << endl;
        m_res = ld_mp * m_1; // Множим long double на деньги
        cout << ld_mp << " * ";
        m_1.show();
        cout << " = ";
        m_res.show();
        cout << endl << endl;
        m_res = ld_mp * m_2; // Множим long double на деньги
        cout << ld_mp << " * ";
        m_2.show();
        cout << " = ";
        m_res.show();
        cout << endl << endl;
        cout << "Else? (y/n) ";
        fflush(stdin);
        answer = getchar();
        cout << endl << endl;
    } while ((answer != 'n')&&(answer != 'N')); // Условие завершения цикла
    
    return 0;
}
