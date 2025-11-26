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
    char linea;
public:
    CLinea(){}
    CLinea(char _linea){if (_linea == 'h'){linea = '-';}else{linea = '|';}}
    virtual ~CLinea(){}
    char getSimbolo() override{if (dibujar == false){return ' ';}else{return linea;}}
    void visibilidad() override{dibujar=true;}
};


#endif //PROYECTO_CLINEA_H
