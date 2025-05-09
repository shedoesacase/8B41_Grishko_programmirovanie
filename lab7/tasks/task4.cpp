#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

int toMinutes(std::string& time){ //Функция для перевода в минуты
    int colon = time.find(':');
    int hours = std::stoi(time.substr(0, colon)); //разбиение на подстроки, тут до :
    int min = std::stoi(time.substr(colon + 1)); // после :
    return hours * 60 + min;
    }

int diff(std::string& first, std::string& second){ //функция для нахождения разницы
    int min1 = toMinutes(first); //переводим в минуты
    int min2 = toMinutes(second); //переводим в минуты

    int diff = abs(min1 - min2); //прямая разница
    int calc_diff = 1440 - diff; //разница при переходе через сутки

    return std::min(diff, calc_diff); //Находим минимальную
}

int timediff(std::vector<std::string> input, int a, int b){
    //std::vector<std::string> input = {"10:10", "12:23", "23:55", "00:23" };
    //int a = 3, b = 2;

    std::string firsttime = input[a], secondtime = input[b];
    
    int difference = diff(firsttime, secondtime);
    
    return difference;
}
