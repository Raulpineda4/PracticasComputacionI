/*
 * Author: Raul Pineda Urbina
 * 15 oct 2021
 * Oct 15, 2021
 */

#ifndef PUNTO_PUNTO_H
#define PUNTO_PUNTO_H

class Punto2D{
public:
    float x, y;
    void SetPosicion(double a, double b);
    float Escalar(float temp1, float temp2);
    [[nodiscard]] float GetX() const, GetY() const;
    float RotarRespectoAlOrigen(float temp1);
    float Trasladar (float temp1, float temp2);
};
#endif //PUNTO_PUNTO_H
