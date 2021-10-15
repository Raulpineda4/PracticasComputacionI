/*
 * Author: Raul Pineda Urbina
 * pinedaurbinaraul@gmail.com
 * Oct 15, 2021
 */
#include <math.h>
#define PI 3.1415926536
#include "Punto.h"
using namespace std;
void Punto2D::SetPosicion(double a, double b) {
    x=a;
    y=b;
}

float Punto2D::Escalar(float temp1, float temp2) {
    x= x*temp1;
    y= y*temp2;
    return 0;
}

float Punto2D::RotarRespectoAlOrigen(float temp1) {
    temp1= temp1 * PI / 180;
    float xe=x;
    x= (x*cos(temp1))-(y*sin(temp1));
    y= (xe*sin(temp1))+(y*cos(temp1));
    return 0;
}


float Punto2D::Trasladar(float temp1, float temp2) {
    x=x+temp1;
    y=y+temp2;
    return 0;
}

float Punto2D::GetX() const {
    return x;
}
float Punto2D::GetY() const {
    return y;
}
