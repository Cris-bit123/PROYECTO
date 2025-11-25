#include "CLinea.h"
#include "CCaja.h"
#include "CPunto.h"
#include "CTablero.h"
#include "Definicion.h"

int main() {
    cout << "Hello World!\n";
    CLinea linea;
    CCaja caja;
    CPunto punto;

    cout << punto.getSimbolo() << "\n";
    cout << "'" << linea.getSimbolo() << "'\n";
    cout << "'" << caja.getSimbolo() << "'\n";

    CTablero tablero(6);
    tablero.mostrar();


    return 0;
}