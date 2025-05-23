#ifndef TASK2_HPP
#define TASK2_HPP

#include <vector>
#include <string>

struct Item{
    std::string name; //имя предмета
    int price; //цена предмета
};

class HashTable { //класс таблицы
    private:
    int size; //размер
    int numbers = 0; //Количество в таблице
    std::vector<std::vector<Item>> elements; //вектор векторов, в котором хранится предмет


    public:
    HashTable(); //дефолтный конструктор
    HashTable(int size); //недефолтный конструктор
    ~HashTable(); //деструктор
    void print(); //функция вывода
    void enter(const std::string& name, int price); //Функция добавления предмета в таблицу
    int search(const std::string& name); //функция поиска
    bool remove(const std::string& name); //функция удаления элемента
    int table_size(); //функция возврата размера таблицы
    bool is_empty(); //функция проверки на пустую таблицу
};

#endif