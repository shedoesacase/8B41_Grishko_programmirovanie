#include <string>
#include <algorithm> 
#include <cctype>
#include <iostream>
#include <stack>

int primer(std::string input) {
    
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    
    std::stack<std::pair<int, int>> stack; //стек для правильной обработки скобок
    int current_num = 0; //текущее значение
    int current_res = 0; //результат
    int sign = 1; //знак
    for(char c : input){
        if(isdigit(c)){
            current_num = current_num * 10 + (c - '0'); //Тут мы обрабатываем все число, а не цифры по отдельности
        }
        else {
            current_res += current_num * sign; //Прибавляем к текущему результату текущее значение и знак
            current_num = 0; 
        }
        if(c == '-'){
            sign = -1; // обновляем знак
        }
        else if(c == '+'){
            sign = 1;
        }
        else if(c == '('){
            stack.push({current_res, sign}); //Добавляем в стек пару результат и знак
            current_res = 0;
            sign = 1;
        }
        else if(c == ')'){        
            auto [prev_res, prev_sign] = stack.top(); //достаем элемент из стека
            stack.pop(); //удаляем верхний элемент из стека

            current_res = prev_res + prev_sign * current_res; //добавляем к текущему результату внутри скобок предыдущий, сохраненный в стеке
        }
    }

    current_res += current_num * sign; //Добавляем последние вычисления    
    return current_res;
}