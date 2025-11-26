//
// Created by Emiliano on 21/11/2025.
//

#ifndef PROYECTO_CELEMENTOS_H
#define PROYECTO_CELEMENTOS_H

#include "Definicion.h"


#include <vector>

class CElementos {
protected:
    vector<CElementos*> tablero;
public:
    virtual ~CElementos(){}
    virtual char getSimbolo() = 0;
    virtual void visibilidad() = 0;
};


#endif //PROYECTO_CELEMENTOS_H