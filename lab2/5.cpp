#include <iostream>
#include <vector>



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


int main(){
    int input = 0;
    std::cin >> input;
    std::vector<int> output = fibonacci(input);
    for(auto it = output.rbegin(); it != output.rend(); ++it) { //rbegin - функция, возвращающая итератор, указывающий на последний элемент в обратном векторе, rend - последний элемент в обратном векторе
        std::cout << *it;
    }
}