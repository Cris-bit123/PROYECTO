//
// Created by Emiliano on 21/11/2025.
//

#ifndef PROYECTO_CELEMENTOS_H
#define PROYECTO_CELEMENTOS_H

#include "Definicion.h"


#include <vector>

class CElementos {
public:
    virtual ~CElementos(){}
    virtual char getSimbolo() = 0;
    virtual void visibilidad() = 0;
    virtual bool completo(int f, int c, char _letra, vector<vector<CElementos*>> &m){return false;}
    virtual void setSimbolo(char _simbolo){}
};


#endif //PROYECTO_CELEMENTOS_H