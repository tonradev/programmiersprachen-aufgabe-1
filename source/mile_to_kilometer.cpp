// Aufgabe 1.15
#include <iostream>
#include <string>

double mile_to_kilometer(){
    std::cout << "Bitte geben Sie einen Wert in Meilen an.\n";
    double miles;
    std::cin >> miles;
    double kilometers = miles*1.60934;
    std::cout << miles << " Meilen entsprechen ca. " << kilometers << " Kilometern.\n";
    return kilometers;
}


int main() {
    mile_to_kilometer();
    return 0;
}
