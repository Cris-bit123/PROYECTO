//
// Created by mauri on 23-11-2025.
//

#ifndef PROYECTO_CLINEA_H
#define PROYECTO_CLINEA_H

#include "CElementos.h"
#include "Definicion.h"


class CLinea: public CElementos {
private:
    bool dibujar = false;
public:
    CLinea(){}
    virtual ~CLinea(){}
    char getSimbolo() override{if (dibujar == false){return ' ';}else{return '-';}}
};


#endif //PROYECTO_CLINEA_H