#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "task1.hpp"

std::string hash(std::string value){ //функция хэширования
    unsigned int hash = 0;
    for(int i = 0; i < value.size();++i){
        hash = hash * 19 + value[i]; //метод хэширования (имеющийся хэш умножается на 19, к нему добавляется номер i-го сивмола в ASCII)
    }
    std::string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string result;
    while(hash > 0){
        result.push_back(alphabet[hash % 62]); //Добавление в строку символа, находящегося в ASCII по индексу, равному остатку от деления на 62 (Размер алфавита)
        hash /= 62;
    }
    return result;
}

void enrolled(std::string filepath){ 
    std::ifstream file(filepath); //Открытие файла, создание потока ввода
    std::string line; 
    while(std::getline(file, line)){ //перебор строк в файле
        if(people.find(hash(line)) == people.end()){ //если найденной строки нет в словаре, people.find() вернет итератор на people.end()
            people[hash(line)] = line; //Записываем в словарь
        }
        else duples++; //записываем в дубликаты
    }
}

void unenrolled(std::string surname){
    if(people.find(hash(surname)) == people.end()){ //если найденной строки нет в словаре, people.find() вернет итератор на people.end()
        people[hash(surname)] = surname; //Записываем в словарь
    }
    else duples++; //записываем в дубликаты
    
}


void print(std::unordered_map<std::string, std::string> people, int duples){ //функция вывода
    std::cout << "Duplicates: " << duples << std::endl; 
    std::cout << "voters: " << people.size() << std::endl;
    for(auto element : people){
        std::cout << element.second << std::endl;
    }
}
