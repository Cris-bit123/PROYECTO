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
    CTablero tablero2(10);
    cout << endl;
    //tablero.movimiento(6,5,5,5);//vertical
    //tablero.mostrar();
    //tablero.movimiento(6,5,6,6);//horizontal
    //tablero.mostrar();
    tablero2.movimiento(10,9,10,10); //horizontal
    tablero2.movimiento(9,9,9,10);
    tablero2.movimiento(9,10,10,10);
    tablero2.movimiento(10,9,9,9); //vertical
    tablero2.mostrar();


    return 0;
}