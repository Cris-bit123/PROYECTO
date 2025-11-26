//
// Created by mauri on 23-11-2025.
//

#ifndef PROYECTO_CCAJA_H
#define PROYECTO_CCAJA_H

#include "Definicion.h"
#include "CElementos.h"

class CCaja: public CElementos {
private:
    bool dibujar = false;
    char dueno = 'X';
public:
    CCaja(){}
    virtual ~CCaja(){}
    char getSimbolo() override{if(dibujar == true){dueno = 'A';} return dueno;}
};


#endif //PROYECTO_CCAJA_H