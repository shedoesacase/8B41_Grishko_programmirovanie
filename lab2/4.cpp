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

std::vector<int> minus(const std::vector<int>& num1, const std::vector<int>& num2) { // Функция для вычитания
    std::vector<int> result; // Вектор для хранения результата
    int borrow = 0; // Переменная для хранения занятого числа
    long long i = 0; // Индекс для прохода по разрядам

    // Поразрядное вычитание
    while (i < num1.size() || i < num2.size()) {
        int digit1 = (i < num1.size()) ? num1[i] : 0; // Цифра из первого числа
        int digit2 = (i < num2.size()) ? num2[i] : 0; // Цифра из второго числа

        int diff = digit1 - digit2 - borrow; // Разность цифр и занятого числа
        if (diff < 0) {
            diff += 10; // Занимаем 10 из следующего разряда
            borrow = 1; // Устанавливаем занятое число
        } else {
            borrow = 0; // Сбрасываем занятое число
        }

        result.push_back(diff); // Записываем результат вычитания
        i++; // Переходим к следующему разряду
    }

    // Удаляем нули в конце вектора
    while (result.size() > 1 && result.back() == 0) { //Проверка на то, больше ли размер вектора 1 символа и является ли последний символ нулем
        result.pop_back();
    }

    return result;
}


int main(){
    int input_1 = 0, input_2 = 0;
    std::cin >> input_1 >> input_2;
    std::vector<int> res1 = power(input_1);
    std::vector<int> res2 = power(input_2);
    std::vector<int> output = minus(res1, res2);
    for(auto it = output.rbegin(); it != output.rend(); ++it) { //rbegin - функция, возвращающая итератор, указывающий на последний элемент в обратном векторе, rend - последний элемент в обратном векторе
        std::cout << *it;
    }
}