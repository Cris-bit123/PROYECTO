//
// Created by mauri on 23-11-2025.
//

#include "CCaja.h"


bool CCaja::completo(int f, int c, char _letra, vector<vector<CElementos*>> &m) {
    if (m[f-1][c]->getSimbolo() == '-' &&
        m[f+1][c]->getSimbolo() == '-' &&
        m[f][c-1]->getSimbolo() == '|' &&
        m[f][c+1]->getSimbolo() == '|') {
        return true;
        }
    return false;
}



