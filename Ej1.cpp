/* Escriba un programa que introduzca una palabra y utilice una pila para imprimir
 la misma palabra invertida.
 */
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

int main() {
    Pila<char> pila;
    char caracter;

    cout << "Ingrese una palabra o frase (termine con un punto): ";
    do {
        cin.get(caracter);
        if (caracter != '.') {
            pila.push(caracter);
        }
    } while (caracter != '.');

    cout << "Palabra o frase invertida: ";

    while (!pila.esVacia()) {
        cout << pila.pop();
    }

    cout << endl;

    return 0;
}