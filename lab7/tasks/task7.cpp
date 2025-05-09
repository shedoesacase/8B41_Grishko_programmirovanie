#include <bitset>
#include <iostream>

int count(int current, int prev_bit, int n){ //Рекурсивная функция, которая генерирует числа
    if(current > n) return 0; //Базовый случай
    int counter = 1; //счетчик

    if(current != 0){
        counter += count(current << 1, 0, n); //Первый рекурсивный случай: добавление нуля к числу
    }
    if(prev_bit != 1){ //Рекурсивный случай 2: добавление 1 к текущему числу, но только если предыдущий бит не был 1
        int next = (current << 1) | 1;
        if(next <= n){
            counter += count(next, 1, n);
        }
    }
    return counter;
}

int rec(int n){ //Функция обертка для вызова рекурсии
    if (n == 0) return 1;
    return count(0, 0, n); 
}

int begin(int n){
    return rec(n);
}