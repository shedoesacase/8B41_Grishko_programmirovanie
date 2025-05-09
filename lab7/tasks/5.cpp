#include <iostream>

int main(){
    int x0 = 1, y0 = 1;
    //std::cin >> fx >> fy;

}

bool ifravno(int fx){ //Проверка на то, можем ли мы дойти от конечной координаты до еденицы
    if(fx % 2 == 0 && fx != 1){
        ifravno(fx); //Если мы можем разделить без остатка на 2 и не равно 1, делим еще раз до того, пока не дойдем
    }
    else if (fx == 1){
        return true;
    }
    else return false;
}

bool ifreal(int fx, int fy){
    
    while(fx > 1 && fy > 1){ //Идти будем в обратном направлении
        if(fx == fy && fx % 2 != 0) return false; //Если обе координаты равны и нечетные, мы никак не достигнем начала
        else return ifravno(fx);
        }
    }


//Все переделать через рекурсию, щас неправильно написано