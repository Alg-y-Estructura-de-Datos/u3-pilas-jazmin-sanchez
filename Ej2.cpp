/*Ejercicio N°2: Escribir una función Reemplazar que tenga como argumentos una pila con tipo de
 elemento int y dos valores int: viejo y nuevo de forma que, si el primer valor
 (viejo) aparece en algún lugar de la pila, sea reemplazado por el segundo (nuevo)..
*/
#include <iostream>
#include "Pila/Pila.h" // Incluye la biblioteca de la pila

using namespace std;

void Reemplazar(Pila<int>& pila, int viejo, int nuevo) {
    Pila<int> pilaAux;

    // Desapila los elementos y reemplaza los valores correspondientes
    while (!pila.esVacia()) {
        int valor = pila.pop();
        if (valor == viejo) {
            pilaAux.push(nuevo);
        } else {
            pilaAux.push(valor);
        }
    }

    // Vuelve a apilar los elementos en la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main() {
    Pila<int> pila;

    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(9);

    cout << "Pila antes del reemplazo: ";
    mostrarPila(pila);
    cout << endl;

    Reemplazar(pila, 3, 1);

    cout << "Pila despues del reemplazo: ";
    mostrarPila(pila);
    return 0;
}