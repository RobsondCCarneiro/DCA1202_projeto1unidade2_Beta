#include "retangulo.h"
#include "point.h"

/**
 * @brief Retangulo::Retangulo
 * @details Este metodo apenas pede as duas coordenadas iniciais (o ponto inicial) do retangulo e
 * depois exige a altura e a largura que tera esse retangulo.
 * @param _x
 * @param _y
 * @param l
 * @param h
 */
Retangulo::Retangulo(float _x, float _y, float l, float h)
{
    //Aqui esta pontos os ponto em sentido anti-horario
    Point q[4];
    q[0].setXY(_x, _y);
    q[1].setXY(_x, _y-h);
    q[2].setXY(_x+l, _y-h);
    q[3].setXY(_x+l, _y);

    for(int i=0; i<4; i++){
        insereVertice(q[i]);
    }
}
