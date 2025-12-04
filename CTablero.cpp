//
// Created by mauri on 23-11-2025.
//

#include "CTablero.h"


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
                    fila.push_back(new CLinea('v'));
                }else {
                    fila.push_back(new CCaja());
                }
            }
        }
        tablero.push_back(fila);
    }
}

CTablero::~CTablero() {
    limpiarTablero();
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

void CTablero::IniciarJuego() {
    int _tamanio;
    cout<<"D o t s & Boxes"<<endl;
    cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~"<<endl;
    do {
        cout<<"1 . T a b l e r o 6 x 6"<<endl;
        cout<<"2 . T a b l e r o 10 x 10"<<endl;
        cout<<"0 . S a l i r"<<endl;
        cout<<"Seleccione la opcion:"<<endl;
        cin>>_tamanio;
    }while (_tamanio < 0 || _tamanio > 2);
    switch (_tamanio) {
        case 0:cout<<"Se cancelo la creacion de una partida...";break;
        case 1: {
                tipoTablero = 6;
                tableroInterno = 11;
                jugador = 'A';
                crearTablero();
                partida();
            }break;
        case 2: {
                tipoTablero = 10;
                tableroInterno = 19;
                jugador = 'A';
                crearTablero();
                partida();
            }break;
    }
}

bool CTablero::revisarTablero() {
    bool nuevoscuadros=false;
    for (int i = 1; i < tableroInterno; i+=2) {
        for (int j = 1; j < tableroInterno; j+= 2) {
            if (tablero[i][j]->getSimbolo() == ' '){
                if (tablero[i][j]->completo(i, j, jugador, tablero)){
                    tablero[i][j]->setSimbolo(jugador);
                        nuevoscuadros = true;
                }
            }
        }
    }
    return nuevoscuadros;
}

void CTablero::partida() {
    int _x1, _y1, _x2, _y2;


    // movimiento(1,1,2,1);
    // movimiento(1,1,1,2);
    // movimiento(2,1,3,1);
    // movimiento(2,1,2,2);
    // movimiento(1,2,2,2);
    // movimiento(3,1,4,1);
    // movimiento(3,1,3,2);
    // movimiento(2,2,3,2);
    // movimiento(1,2,1,3);
    // movimiento(4,1,5,1);
    // movimiento(5,1,6,1);
    // movimiento(4,1,4,2);
    // movimiento(5,1,5,2);
    // movimiento(6,1,6,2);
    // movimiento(3,2,4,2);
    // movimiento(4,2,5,2);
    // movimiento(5,2,6,2);
    // movimiento(1,3,2,3);
    // movimiento(1,3,1,4);
    // movimiento(2,3,3,3);
    // movimiento(2,2,2,3);
    // movimiento(2,3,2,4);
    // movimiento(3,3,4,3);
    // movimiento(3,2,3,3);
    // movimiento(3,3,3,4);
    // movimiento(4,3,5,3);
    // movimiento(4,2,4,3);
    // movimiento(4,3,4,4);
    // movimiento(5,3,6,3);
    // movimiento(5,2,5,3);
    // movimiento(5,3,5,4);
    // movimiento(6,2,6,3);
    // movimiento(6,3,6,4);
    // movimiento(1,4,2,4);
    // movimiento(1,4,1,5);
    // movimiento(2,4,3,4);
    // movimiento(2,4,2,5);
    // movimiento(3,4,4,4);
    // movimiento(3,4,3,5);
    // movimiento(4,4,5,4);
    // movimiento(4,4,4,5);
    // movimiento(5,4,6,4);
    // movimiento(5,4,5,5);
    // movimiento(6,4,6,5);
    // movimiento(1,5,2,5);
    // movimiento(1,5,1,6);
    // movimiento(2,5,3,5);
    // movimiento(2,5,2,6);
    // movimiento(3,5,4,5);
    // movimiento(3,5,3,6);
    // movimiento(4,5,5,5);
    // movimiento(4,5,4,6);
    // movimiento(5,5,6,5);
    // movimiento(5,5,5,6);
    // movimiento(1,6,2,6);
    // movimiento(2,6,3,6);
    // movimiento(3,6,4,6);
    // movimiento(4,6,5,6);


    while (!terminado()) {
        cout<<"----------> Turno del jugador "<<jugador<<" <----------"<<endl;
        mostrar();
        cout<<endl;
        cout<<"Ingrese las coordenadas de la posicion 1 (x,y): ";cin>>_x1>>_y1;
        cout<<"Ingrese las coordenadas de la posicion 2 (x,y): ";cin>>_x2>>_y2;
        movimiento(_x1,_y1,_x2,_y2);
    }
}

void CTablero::movimiento(int x1,int y1,int x2,int y2) {
    int x_coord = (x1*2+x2*2)/2-2;
    int y_coord = (y1*2+y2*2)/2-2;
    if (x1>=1 && x2>=1 && y1>=1 && y2>=1 && x1<=tipoTablero && x2<=tipoTablero && y1<=tipoTablero && y2<=tipoTablero) {
        if (x1==x2 && y1==y2) {
            cout<<"XXXXXXXX----Las coordenadas son las mismas----XXXXXXXX"<<endl;

        }else if (abs(x1-x2) + abs(y1-y2)!=1) {
            cout<<"XXXXXXXX----Las coordenadas no son adyacentes----XXXXXXXX"<<endl;

        }else if (tablero[x_coord][y_coord]->getSimbolo() == '-' || tablero[x_coord][y_coord]->getSimbolo() == '|') {
            cout<<"XXXXXXXX---Ya hay una linea----XXXXXXXX"<<endl;

        }else{
            if (tablero[x_coord][y_coord]->getSimbolo() == ' ') {
                tablero[x_coord][y_coord]->visibilidad();
                bool hizoPunto=revisarTablero();
                if (!hizoPunto) {
                    if (jugador == 'A') {
                        jugador = 'B';
                    } else {
                        jugador = 'A';
                    }
                }else {
                    cout<<"**** "<<jugador<<" obtuvo un punto. Juega de Nuevo. ****"<<endl;
                }
            }
        }
    }
    else {
        cout<<"XXXXXXXX----Fuera del rango----XXXXXXXX"<<endl;
    }
}

bool CTablero::terminado() {
    int puntosA=0, puntosB=0;
    int nvacios=0;
    for (int i=0;i<tableroInterno;i++) {
        for (int j=0;j<tableroInterno;j++) {
            if (tablero[i][j]->getSimbolo() == ' ') {
                nvacios++;
            }else if (tablero[i][j]->getSimbolo() == 'A') {
                puntosA++;
            }else if (tablero[i][j]->getSimbolo() == 'B') {
                puntosB++;
            }
        }
    }
    if (nvacios==0){
        int deNuevo;
        mostrar();
        cout<<"-------------FIN DEL JUEGO---------------"<<endl;;
        cout<<"Ganador: ";
        if (puntosA>puntosB)
            cout<<"A"<<endl<<"Puntuacion: "<<puntosA<<endl;
        else
            cout<<"B"<<endl<<"Puntuacion: "<<puntosB<<endl<<endl;
        do {
            cout<<"Desea volver a jugar?"<<endl;
            cout<<"1. SI"<<endl;
            cout<<"0. NO"<<endl;
            cin>>deNuevo;
        }while (deNuevo != 1 && deNuevo != 0);
        if (deNuevo == 1) {
            limpiarTablero();
            IniciarJuego();
        }
        return true;
    }else

    return false;
}

void CTablero::limpiarTablero() {
    for (auto& fila: tablero) {
        for (auto& item : fila) {
            delete item;
        }
    }
    tablero.clear();
}
