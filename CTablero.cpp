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
                    fila.push_back(new CLinea('h'));
                }
            }else {
                if (j % 2 == 0) {
                    fila.push_back(new CLinea('V'));
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
    cout << "    ";
    for (int j = 1; j <= tipoTablero; j++) {
        cout << j;
        if (j < 10) {
            cout << "     ";
        }else {
            cout << "  ";
        }
    }

    cout << endl;
    int filas = 1;
    for (int i = 0; i < tableroInterno; i++) {
        if (i % 2 == 0 && filas <= tipoTablero) {
            if (filas < 10) {
                cout <<" " << filas  << " ";
            }else {
                cout << filas << " ";
            }
            filas++;
        }else {
            cout << "   ";
        }

        for (int j = 0; j < tableroInterno; j++) {
            cout << " " << tablero[i][j]->getSimbolo() << " ";
        }
        cout << endl;
    }

}

void CTablero::revisarTablero() {
    for (int i = 1; i < tableroInterno; i+=2) {
        for (int j = 1; j < tableroInterno; j+= 2) {
            if (tablero[i][j]->getSimbolo() == ' '){
                if (tablero[i][j]->completo(i, j, jugador, tablero)){
                    tablero[i][j]->setSimbolo(jugador);
                }else {
                    if (jugador == 'A') {
                        jugador = 'B';
                    }else{
                        jugador = 'A';
                    }
                }
            }
        }
    }
}

bool CTablero::movimiento(int x1,int y1,int x2,int y2) {
    int x_coord = (x1*2+x2*2)/2-2;
    int y_coord = (y1*2+y2*2)/2-2;
    if (x1>=1 && x2>=1 && y1>=1 && y2>=1 && x1<=tipoTablero && x2<=tipoTablero && y1<=tipoTablero && y2<=tipoTablero) {
        if (x1==x2 && y1==y2) {
            cout<<"XXXXXXXX----Las coordenadas son las mismas----XXXXXXXX"<<endl;
            return false;
        }else if (abs(x1-x2) + abs(y1-y2)!=1) {
            cout<<"XXXXXXXX----Las coordenadas no son adyacentes----XXXXXXXX"<<endl;
            return false;
        }else if (tablero[x_coord][y_coord]->getSimbolo() == '-' || tablero[x_coord][y_coord]->getSimbolo() == '|') {
            cout<<"XXXXXXXX---Ya hay una linea----XXXXXXXX"<<endl;
            return false;
        }else{
            if (tablero[x_coord][y_coord]->getSimbolo() == ' ') {
                tablero[x_coord][y_coord]->visibilidad();
                revisarTablero();
                return true;
            }
        }
    }
    else {
        cout<<"XXXXXXXX----Fuera del rango----XXXXXXXX"<<endl;
        return false;
    }
    return false;
}
