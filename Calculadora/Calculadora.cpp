/*
 * Author: Raul Pineda
 * pinedaurbinaraul@gmail.com
 * Sept 15,2021
 */

#include <iostream>
int main() {
    int numOne = 1, numTwo = 1, total = 1;
    char operation;
    std::cout << "Este programa hace operaciones basicas entre dos numeros.\n";

    std::cout << "Primer numero: \n";
    std::cin >> numOne;
    std::cout << "Operacion\n";
    std::cin >> operation;
    std::cout << "Segundo numero: \n";
    std::cin >> numTwo;
    if (operation == '+') {total = numOne + numTwo;}
    if (operation == '-') {total = numOne - numTwo;}
    if (operation == '/') {total = numOne / numTwo;}
    if (operation == '%') {total = numOne % numTwo;}
    if (operation == '*') {total = numOne * numTwo;}

    std::cout << "Resultado: " << total << std::endl;
    return 0;
}
