#include <iostream>
#include "main.h"


int main() {
    std::vector<int> output;
    int chastnoe = 0;
    int n = 0;
    int input1 = 0, input2 = 0;
    std::cout << "What action do you want to perform?" << std::endl << "1. Factorial" << std::endl << "2. 2^n" << std::endl << "3. 2^n + 2^m" << std::endl << "4. 2^n - 2^m" << std::endl << "5. n-th fibonacci number" << std::endl << "6. n/m" << std::endl;
    std::cin >> n;
    switch (n) {
        case 1: {
            std::cin >> input1;
            output = fact(input1);
            break;
        }
        case 2: {
            std::cin >> input1;
            output = power(input1);
            break;
        }
        case 3: {
            std::cin >> input1 >> input2;
            std::vector<int> res1 = power(input1);
            std::vector<int> res2 = power(input2);
            output = sum(res1, res2);
            break;
        }
        case 4: {
            std::cin >> input1 >> input2;
            std::vector<int> res1 = power(input1);
            std::vector<int> res2 = power(input2);
            output = minus(res1, res2);
            break;
        }
        case 5: {
            std::cin >> input1;
            output = fibonacci(input1);
            break;
        }
        case 6: {
            std::cin >> input1 >> input2;
            chastnoe = delenie(input1, input2);
            std::cout << chastnoe;
            break;
        }
        case 7: {
            std::cin >> input1 >> input2;
            chastnoe = delenie(input1, input2);
            std::cout << chastnoe;
            break;
        }

        default: {
            std::cout << "not found";
            return 1;
        }
    }
    for(auto it = output.rbegin(); it != output.rend(); ++it) { //rbegin - функция, возвращающая итератор, указывающий на последний элемент в обратном векторе, rend - последний элемент в обратном векторе
        std::cout << *it;
    }
    return 0;
}