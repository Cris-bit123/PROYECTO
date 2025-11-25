//
// Created by mauri on 23-11-2025.
//

#include "CTablero.h"


CTablero::CTablero(int _tipo) {
    tipoTablero = _tipo;
    tableroInterno = 2*_tipo-1;
    crearTablero();
}

void CTablero::crearTablero() {
    for (int i = 0; i < tableroInterno; i++) {
        vector<CElementos*> fila;
        for (int j = 0; j < tableroInterno; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    fila.push_back(new CPunto());
                }else {
                    fila.push_back(new CLinea());
                }
            }else {
                if (j % 2 == 0) {
                    fila.push_back(new CLinea());
                }else {
                    fila.push_back(new CCaja());
                }
            }
        }
        tablero.push_back(fila);
    }
}

CTablero::~CTablero() {
    for (auto& fila: tablero) {
        for (auto& item : fila) {
            delete item;
        }
    }
}

void CTablero::mostrar() {
    cout << "Tablero de " << tipoTablero << "x" << tipoTablero << " (Matriz interna " << tableroInterno << "x" << tableroInterno << "):\n\n";
    for (int i = 0; i < tableroInterno; i++) {
        for (int j = 0; j < tableroInterno; j++) {
            cout << " " << tablero[i][j]->getSimbolo() << " ";
        }
        cout << endl;
    }

}

void CTablero::revisarTablero() {
}
