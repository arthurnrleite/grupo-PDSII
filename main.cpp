#include <iostream>
#include "matematica.h"
#include <math.h>

using std::cout;
using std::endl;


int main() {
    float angulo;
    std::cout<< "escreva um angulo em radianos";
    std::cin>> angulo;

    
    float senoAngulo= seno (angulo);
    double cosAngulo= cosseno (angulo);
    double tanAngulo= tangente (angulo);
    cout << "Seno: " <<senoAngulo << std::endl;
    cout << "Cosseno: " <<cosAngulo << std::endl;
    cout << "Tangente: " <<tanAngulo << std::endl;
    return 0;
}