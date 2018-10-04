#ifndef POLIGONO_H
#define POLIGONO_H
#include <cmath>
#include <iostream>
#include "point.h"

class Poligono{
private:
    Point vert[100];
    int nVert;
public:
    Poligono();
    void insereVertice(Point p);
    int qtdeVertice();
    float areaPoligono();
    void transladaPoligono(float a, float b);
    Point CentroMassa();
    void rotacionaPoligono(float theta, Point pRot);
    void imprimePoligono();
};

#endif // POLIGONO_H
