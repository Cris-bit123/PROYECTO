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
    char dueno = ' ';
public:
    CCaja(){}
    virtual ~CCaja(){}
    char getSimbolo() override{return dueno;}
    bool completo(int f, int c, char _letra, vector<vector<CElementos*>> &m) override;
    void visibilidad() override{dibujar=true;}
    void setSimbolo(char _simbolo) override{dueno = _simbolo;}
};


#endif //PROYECTO_CCAJA_H
