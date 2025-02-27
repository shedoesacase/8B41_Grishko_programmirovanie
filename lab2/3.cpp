#include <iostream>
#include <vector>

std::vector<int> power(int input) {
    std::vector<int> num = { 1 };
    int carry = 0; //переменная переноса
    int index = 0; //Переменная, отвечающая за цифру разряда
    for(int j = 1; j <= input; j++){
        for(int i = 0; i < num.size(); i++) {
            index = num[i] * 2 + carry; //Умножаем текущую цифру на 2 и добавляем перенос
            num[i] = index % 10; //оставляем только 1 последнюю цифру
            carry = index / 10; //обновление переноса
        }

        //В случае, если остался перенос, добавляем его в вектор
        while (carry) {
            num.push_back(carry % 10); //добавляем последнюю цифру переноса
            carry /= 10; //убираем добавленную цифру из переноса
        }
    }
    return num;
}

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

int main(){
    int input_1 = 0, input_2 = 0;
    std::cin >> input_1 >> input_2;
    std::vector<int> res1 = power(input_1);
    std::vector<int> res2 = power(input_2);
    std::vector<int> output = sum(res1, res2);
    for(auto it = output.rbegin(); it != output.rend(); ++it) { //rbegin - функция, возвращающая итератор, указывающий на последний элемент в обратном векторе, rend - последний элемент в обратном векторе
        std::cout << *it;
    }
    //int size = output.size();
    //std::cout << std::endl << size;
}