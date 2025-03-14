#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <string>

std::vector<int> power(int input);
std::vector<int> sum(std::vector<int> res1, std::vector<int> res2);
std::vector<int> minus(const std::vector<int>& num1, const std::vector<int>& num2);
std::vector<int> fibonacci(int n);
std::vector<int> fact(int input);
int delenie(int chislitel, int znamenatel);
#endif