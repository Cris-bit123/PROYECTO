//
// Created by mauri on 23-11-2025.
//

#ifndef PROYECTO_CTABLERO_H
#define PROYECTO_CTABLERO_H

#include "Definicion.h"
#include "CElementos.h"
#include "CCaja.h"
#include "CPunto.h"
#include "CLinea.h"

class CTablero {
private:
    int tipoTablero;
    int tableroInterno;
    vector<vector<CElementos*>> tablero;
    char jugador;

public:
    CTablero(){}
    virtual ~CTablero();
    void crearTablero();
    void mostrar();
    void IniciarJuego();
    void partida();
    void movimiento(int x1,int y1,int x2,int y2);
    void limpiarTablero();
    bool revisarTablero();
    bool terminado();
};


#endif //PROYECTO_CTABLERO_H
