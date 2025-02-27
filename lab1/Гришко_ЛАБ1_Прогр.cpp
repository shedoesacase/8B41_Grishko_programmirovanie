#include <iostream>

void switchstatus (bool *states, short num) {
    states[num - 1] = !states[num - 1];
}

bool activestatus (bool *states, short num){
    return states[num - 1];
}

int countactivestatus(bool *states){
    int count = 0;
    for(int i = 0; i < 5; i++){
        if(states[i])
        count++;
    }
    return count;
}

bool isdetected (bool *states){
    if(states[0]&&states[1]&&states[2]&&states[3])
        return false;
    else return true;
}

int main(int, char**) {
    bool states[5] = {false};
    switchstatus(states, 3);
    bool status = activestatus(states, 3);
    short active_statuses = countactivestatus(states);
    bool detected = isdetected(states);

    switchstatus (states, 1);
    switchstatus (states, 2);
    switchstatus (states, 4);
    detected = isdetected(states);
}
