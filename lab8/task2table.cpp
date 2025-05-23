#include "task2.hpp"
#include <string>
#include <vector>
#include <iostream>

size_t hash(std::string value){ //функция хэширования
    size_t hash = 0;
    for(size_t i = 0; i < value.size();++i){
        hash = hash * 31 + value[i]; //метод хэширования (имеющийся хэш умножается на 31, к нему добавляется номер i-го сивмола в ASCII)
    }
    return hash;
}

 HashTable::HashTable(){ //дефолтный конструктор
    size = 10;
    elements.resize(size);
}

 HashTable::HashTable(int size){ //недефолтный конструктор
    elements.resize(size);
}

HashTable::~HashTable() {
    elements.clear();
    numbers = 0;
}

void HashTable::enter(const std::string& name, int price){ //функция добавления в таблицу
    size_t hsh = hash(name);
    size_t index = hsh % elements.size(); //Нахождения индекса в таблице остатком от деления
    for(Item &item : elements[index]){ //Проверка элементов, сидящих по этому индексу
        if(item.name == name){ //Если нашли, то обновляем цену
            item.price = price;
            return;
        }
    }
    elements[index].push_back({name, price}); //Если не нашли, то добавляем в таблицу
    numbers++; //Добавляем к количеству
}

int HashTable::search(const std::string& name){
    size_t hsh = hash(name);
    int index = hsh % elements.size();
    for(Item &item : elements[index]){ //Проверка элементов, сидящих по этому индексу
        if(item.name == name){ //Если нашли
            return item.price;
        }
    }
    return -1;
}

bool HashTable::remove(const std::string& name){
    size_t hsh = hash(name);
    int index = hsh % elements.size();
    auto& bucket = elements[index]; //ссылка на корзину

    for(auto it = bucket.begin(); it != bucket.end(); ++it){
        if(it->name == name){
            bucket.erase(it);
            numbers--;
            std::cout << name << " removed";
            return true;
        }
    }
    return false;
}

void HashTable::print() { //Функция для вывода
    for(size_t i = 0; i < elements.size(); ++i) {
        std::cout << "Bucket " << i << ":\n";
        for(auto& item : elements[i]) {
            std::cout << "  " << item.name << " - " << item.price << " руб.\n";
        }
    }
}

int HashTable::table_size(){ //Возврат размера
    return numbers;
}

bool HashTable::is_empty(){
    if(numbers == 0) return true;
    else return false;
}
