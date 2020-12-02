#include "display.h"

void displayClear() {
    try {
        if(system("clear") != 0) throw -1;
    } catch(int e) {
        system("cls");
    }
}