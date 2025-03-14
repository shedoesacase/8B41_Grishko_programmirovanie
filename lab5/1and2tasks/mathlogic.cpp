#include <iostream>
#include <vector>
#include "main.h"

std::vector<int> sum(std::vector<int> res1, std::vector<int> res2){// функция для сложения
    std::vector<int> sum_result;
    int carry = 0;
    long long i = 0; // Индекс для прохода по разрядам

    while (i < res1.size() || i < res2.size() || carry) {
        int digit1 = (i < res1.size()) ? res1[i] : 0; // Цифра из первого числа
        int digit2 = (i < res2.size()) ? res2[i] : 0; // Цифра из второго числа

        int sum = digit1 + digit2 + carry; // Сумма цифр и переноса
        sum_result.push_back(sum % 10); // Записываем последнюю цифру суммы
        carry = sum / 10; // Вычисляем новый перенос

        i++; // Переходим к следующему разряду
    }
    return sum_result;
}


std::vector<int> power(int input) {
    std::vector<int> num = { 1 };
    int carry = 0; //переменная переноса
    int index = 0; //Переменная, отвечающая за цифру разряда
    for(int j = 1; j <= input; j++){
        for(int i = 0; i < num.size(); i++) {
            index = num[i] * 2 + carry; //Умножаем текущую цифру на 2 и добавляем перенос
            num[i] = index % 10; //оставляем только 1 последнюю цифру
            carry = index / 10; //обновление переноса
        }

        //В случае, если остался перенос, добавляем его в вектор
        while (carry) {
            num.push_back(carry % 10); //добавляем последнюю цифру переноса
            carry /= 10; //убираем добавленную цифру из переноса
        }
    }
    return num;
}


std::vector<int> minus(const std::vector<int>& num1, const std::vector<int>& num2) { // Функция для вычитания
    std::vector<int> result; // Вектор для хранения результата
    int borrow = 0; // Переменная для хранения занятого числа
    long long i = 0; // Индекс для прохода по разрядам

    // Поразрядное вычитание
    while (i < num1.size() || i < num2.size()) {
        int digit1 = (i < num1.size()) ? num1[i] : 0; // Цифра из первого числа
        int digit2 = (i < num2.size()) ? num2[i] : 0; // Цифра из второго числа

        int diff = digit1 - digit2 - borrow; // Разность цифр и занятого числа
        if (diff < 0) {
            diff += 10; // Занимаем 10 из следующего разряда
            borrow = 1; // Устанавливаем занятое число
        } else {
            borrow = 0; // Сбрасываем занятое число
        }

        result.push_back(diff); // Записываем результат вычитания
        i++; // Переходим к следующему разряду
    }

    // Удаляем нули в конце вектора
    while (result.size() > 1 && result.back() == 0) { //Проверка на то, больше ли размер вектора 1 символа и является ли последний символ нулем
        result.pop_back();
    }

    return result;
}

std::vector<int> fibonacci(int n) { //Функция для вычисления n-го числа Фибоначчи
    if (n == 0) return {0}; // 
    if (n == 1) return {1}; // 
    std::vector<int> fib_prev = {0}; // 
    std::vector<int> fib_curr = {1}; // 

    for (int i = 2; i <= n; i++) {
        std::vector<int> fib_next = sum(fib_prev, fib_curr);
        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    return fib_curr;
}

std::vector<int> fact(int input) {
    std::vector<int> fact = { 1 };
    int carry = 0; //переменная переноса
    int index = 0; //Переменная, отвечающая за цифру разряда
    for(int j = 2; j <= input; j++){
        for(int i = 0; i < fact.size(); i++) {
            index = fact[i] * j + carry; //Умножаем текущую цифру на j и добавляем перенос
            fact[i] = index % 10; //оставляем только 1 последнюю цифру
            carry = index / 10; //обновление переноса
        }

        //В случае, если остался перенос, добавляем его в вектор
        while (carry) {
            fact.push_back(carry % 10); //добавляем последнюю цифру переноса
            carry /= 10; //убираем добавленную цифру из переноса
        }
    }
    return fact;
}

int delenie(int chislitel, int znamenatel){
    if(znamenatel == 0){
        return (chislitel > 0) ? INT_MAX : INT_MIN; 
    }

    int sign = ((chislitel > 0) ^ (znamenatel > 0)) ? -1 : 1; //xor для определения знака. Если они одинаковые - sign = 0.

    int modChislitel = std::abs(chislitel);
    int modZnametatel = std::abs(znamenatel);

    if(modChislitel<modZnametatel){  //округление до нуля
        return 0;
    }

    int chastnoe= 0;
    while(modChislitel>=modZnametatel){
        int temp = modZnametatel; //переменная для удвоения
        int carry = 1;  //степень двойки

        // Ищем максимальную степень двойки, на которую можно умножить делитель
        while((temp<<1) <= modChislitel){
            temp <<= 1; //временная переменная, которая будет хранить текущее значение делителя, умноженное на степень двойки
            carry <<= 1; //степень двойки, на которую умножается делитель
        }
        modChislitel += (~temp + 1); //сложение с дополнительным кодом числа ( по сути вычитание)
        chastnoe += carry;
    }
    return (sign == 1) ? chastnoe : 0+(~chastnoe+1);
}