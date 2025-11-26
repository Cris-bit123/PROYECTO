//
// Created by mauri on 23-11-2025.
//

#ifndef PROYECTO_CPUNTO_H
#define PROYECTO_CPUNTO_H

#include "Definicion.h"
#include "CElementos.h"

class CPunto: public CElementos {
private:
public:
    CPunto(){}
    virtual ~CPunto(){}
    char getSimbolo() override{return '+';};
    void visibilidad() override{dibujar=true;}
};


#endif //PROYECTO_CPUNTO_H
