#include <iostream>
#include <string>

std::string ipv4_edit(std::string ip){ //функция для замены точки на [.]
    int i = 0;
    while(i < ip.length()){
        if(ip[i] == '.'){
            ip.insert(i, "["); //На место i добавляется [, все остальные индексы сдвигаются на одно значение
            ip.insert(i+2, "]");//На место i+2 (Потому, что после [ идет точка, нам нужно поставить ] на место после точки) добавляется ], все остальные индексы сдвигаются на одно значение
            i = i + 4; //Пропуск [.]
        }
        else {
            i++;
        }
    }
    return ip;
}

int main(){
    std::string ip = "10.114.0.74";
    //std::cin >> ip;
    std::string ip_new;
    ip_new = ipv4_edit(ip);
    std::cout << ip_new;
    return 0;
}