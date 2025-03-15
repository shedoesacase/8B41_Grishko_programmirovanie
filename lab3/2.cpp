#include <iostream>
#include <string>

bool is_palindrom(std::string new_str){ //функция для проверки слова на палиндром
    std::string old_str = "";

    for(int i = 0; i < new_str.length(); i++){ //цикл, убирающий пробел в строке
        if(new_str[i] == ' '){
            new_str.erase(i, 1);
        }
    }

    old_str = new_str;

    char temp = ' ';
    for (int i = 0; i < new_str.length()/2; i++){ //цикл, разворачивающий строку
        temp = new_str[i];
        new_str[i] = new_str[new_str.length() - i - 1];
        new_str[new_str.length() - i - 1] = temp;
         
    }

    if(old_str == new_str) //сравнение строк
        return true;
    else
        return false;
}

int main(){
    std::string str = "race fast safe car";
    std::cout << is_palindrom(str);
    return 0;
}
