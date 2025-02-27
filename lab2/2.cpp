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

int main(){
    int input = 0;
    std::cin >> input;
    std::vector<int> output = power(input);
    for(auto it = output.rbegin(); it != output.rend(); ++it) { //rbegin - функция, возвращающая итератор, указывающий на последний элемент в обратном векторе, rend - последний элемент в обратном векторе
        std::cout << *it;
    }
    //int size = output.size();
    //std::cout << std::endl << size;
}