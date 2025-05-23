#ifndef TASK1_HPP
#define TASK1_HPP

#include <string>
#include<unordered_map>

extern std::unordered_map<std::string, std::string> people; //словарь для хранения хэш таблицы
extern int duples; //дубликаты


std::string hash(std::string value);
void enrolled(std::string filepath);
void unenrolled(std::string surname);
void print(std::unordered_map<std::string, std::string> people, int duples);

#endif