#include "task1.hpp"
#include <iostream>

std::unordered_map<std::string, std::string> people; //словарь для хранения хэш таблицы
int duples = 0; //дубликаты


int main(){
    std::string filepath = "surname.txt";
    enrolled(filepath);
    std::string input;
    while(true){
        std::cin >> input;
        if(input != "end") unenrolled(input);
        else break;
    }
    print(people, duples);
}
