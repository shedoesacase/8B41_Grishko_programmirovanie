#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "task3.hpp"

std::string solution(std::string input){
    std::vector<int> x;
    std::vector<int> free;
    std::string carry = "";
    int carryint;
    for(int i = 0; i < input.size() && input[i] != '='; i++) { //цикл прохода по левой части
        if(input[i] == '-') { //случай для минуса
            carry.clear();
            i++;
    
            while (i < input.size() && input[i] != '+' && input[i] != '-' && input[i] != 'x' && input[i] != '=') { //собираем все цифры
                carry.push_back(input[i]);
                i++;
            }
    
            if (!carry.empty()) {//переделываем в инт
                carryint = std::stoi(carry) * (-1); 
            }

            else carryint = -1;

            if(i < input.size() && input[i] == 'x'){
                x.push_back(carryint); //добавляем в вектор, если следующий элемент - икс
                i++;
            }
            else free.push_back(carryint);
    
            i--; //корректируем индекс
        }
        else if (input[i] == '+'){ //случай для плюса
            carry.clear();
            i++;
    
            while (i < input.size() && input[i] != '+' && input[i] != '-' && input[i] != 'x' && input[i] != '=') { //собираем все цифры
                carry.push_back(input[i]);
                i++;
            }
    
            if (!carry.empty()) {//переделываем в инт
                carryint = std::stoi(carry); 
            }
            else carryint = 1;

            if(input[i] == 'x'){
                x.push_back(carryint); //добавляем в вектор, если следующий элемент - икс
                i++;
            }
            else free.push_back(carryint);
    
            i--;
        }
        else if (isdigit(input[i])){ //случай, если первое значение в строке - цифра
            carry.clear();
    
            while (i < input.size() && input[i] != '+' && input[i] != '-' && input[i] != 'x' && input[i] != '=') { //собираем все цифры
                carry.push_back(input[i]);
                i++;
            }
    
            if (!carry.empty()) {//переделываем в инт
                carryint = std::stoi(carry); 
            }

            else carryint = 1;

            if(input[i] == 'x'){
                x.push_back(carryint); //добавляем в вектор, если следующий элемент - икс
                i++;
            }
            else free.push_back(carryint);
    
            i--;
        }
        else if (input[i] == 'x') {
            x.push_back(1); // Коэффициент 1 для x в начале строки
        }
    }
    
    int ravno = input.find('=');

    for(int i = ravno + 1; i < input.size(); i++) { //цикл прохода по правой части
        if(input[i] == '-') { //случай для минуса
            carry.clear();
            i++;
    
            while (i < input.size() && input[i] != '+' && input[i] != '-' && input[i] != 'x' && input[i] != '=') { //собираем все цифры
                carry.push_back(input[i]);
                i++;
            }
    
            if (!carry.empty()) {//переделываем в инт
                carryint = std::stoi(carry) * (-1); 
            }

            else carryint = -1;

            // Инвертируем знак для правой части
            carryint *= -1;

            if(i < input.size() && input[i] == 'x'){
                x.push_back(carryint); //добавляем в вектор, если следующий элемент - икс
                i++;
            }
            else free.push_back(carryint);
    
            i--; //корректируем индекс
        }
        else if (input[i] == '+'){ //случай для плюса
            carry.clear();
            i++;
    
            while (i < input.size() && input[i] != '+' && input[i] != '-' && input[i] != 'x' && input[i] != '=') { //собираем все цифры
                carry.push_back(input[i]);
                i++;
            }
    
            if (!carry.empty()) {//переделываем в инт
                carryint = std::stoi(carry); 
            }
            else carryint = 1;

            // Инвертируем знак для правой части
            carryint *= -1;
            
            if(input[i] == 'x'){
                x.push_back(carryint); //добавляем в вектор, если следующий элемент - икс
                i++;
            }
            else free.push_back(carryint);
    
            i--;
        }
        else if (isdigit(input[i])){ //случай, если первое значение в строке - цифра
            carry.clear();
    
            while (i < input.size() && input[i] != '+' && input[i] != '-' && input[i] != 'x' && input[i] != '=') { //собираем все цифры
                carry.push_back(input[i]);
                i++;
            }
    
            if (!carry.empty()) {//переделываем в инт
                carryint = std::stoi(carry); 
            }

            else carryint = 1;

            // Инвертируем знак для правой части
            carryint *= -1;

            if(input[i] == 'x'){
                x.push_back(carryint); //добавляем в вектор, если следующий элемент - икс
            i++;
            }
            else free.push_back(carryint);
    
            i--;
        }
        else if (input[i] == 'x') {
            x.push_back(-1); // Коэффициент 1 для x в начале строки
        }
    }

    int sumfree = 0;
    for(int i = 0; i < free.size(); i++){
        sumfree += free[i];
    }
    
    int sumx = 0;
    for(int i = 0; i < x.size(); i++){
        sumx += x[i];
    }

    if (sumx == 0) {
        if (sumfree == 0) {
           return "Infinite";
        } else {
            return "NO";
        }
    }
    else {
        int answer = -(sumfree/sumx);
        std::string result = "x="+std::to_string(answer);
        return result;
    }
}