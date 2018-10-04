#include <iostream>
#include <cmath>
#include "point.h"

using namespace std;
/**
 * @brief Point::setX Este metodo apenas serve para inserir a coordenada x no ponto
 * @param _x
 */
void Point::setX(float _x){
    x = _x;
}
/**
 * @brief Point::getX Este metodo serve para recuperar o valor da coordenada x
 * @return
 */
float Point::getX(void){
    return x;
}
/**
 * @brief Point::setY Este metodo apenas serve para inserir a coordenada y no ponto
 * @param _y
 */
void Point::setY(float _y){
    y = _y;
}
/**
 * @brief Point::getY Este metodo serve para recuperar o valor da coordenada y
 * @return
 */
float Point::getY(void){
    return y;
}
/**
 * @brief Point::setXY Este metodo serva para inserir a coordenada x y e ao mesmo tempo
 * @param _x
 * @param _y
 */
void Point::setXY(float _x, float _y){
    x = _x;
    y = _y;
}

/**
 * @brief Point::add Metodo para soma vetorial
 * @param p1
 */
void Point::add(Point p1){
    x = x + p1.getX();
    y = y + p1.getY();
}
/**
 * @brief Point::sub Metodo para subtracao vetorial
 * @param p1
 */
void Point::sub(Point p1){
    x = x - p1.getX();
    y = y - p1.getY();
}
/**
 * @brief Point::norma Metodo para o calculo do modulo ou norma do vetor
 * @return
 */
float Point::norma(void){
    return sqrt(x*x+y*y);
}
/**
 * @brief Point::translada Metodo para transladar os pontos dado os parametros abaixo
 * @param a
 * @param b
 */
void Point::translada(float a, float b){
    x = x+a;
    y = y+b;
}
/**
 * @brief Point::imprime Metodo para imprimir os pontos da coordenada atual
 */
void Point::imprime(){
    cout << "Imprimindo o ponto: ( " << x << " , " << y << " ) " << endl;
}
