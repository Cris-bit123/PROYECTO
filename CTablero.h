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
public:
    CTablero(){}
    CTablero(int _tipo);
    virtual ~CTablero();
    void crearTablero();
    void mostrar();
    void revisarTablero();
};


#endif //PROYECTO_CTABLERO_H