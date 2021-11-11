//
// Created by Pineda on 11/9/2021.
//
#ifndef CARGAELECTRICA_GRUPO_H
#define CARGAELECTRICA_GRUPO_H

#include <string>

using namespace std;

class Grupo {
private:
    string nombre;
    float pka;
    int carga;

public:
    Grupo(string, float, int);
    Grupo();

    int getCharge();
    float getpK();

};


#endif //CARGAELECTRICA_GRUPO_H