// Aufgabe 1.3
#include <iostream>
#include <cmath>


int get_dividend() {
    int number = 1;
    for (int i = 1; i < 21; ++i) {
        if(number%i != 0) {
            number += 1;
            i = 1;
        }
        else {
            continue;
        }
    }
    std:: cout << number;
    return number;
}

int main() {

    get_dividend();
    return 0;
}