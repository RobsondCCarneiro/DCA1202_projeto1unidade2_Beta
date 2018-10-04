#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

using namespace std;

int main()
{
   //Declarando a variavel R que pertence a classe Retangulo para formar um triangulo
   Retangulo R(0.0, 0.0, 4.0, 3.0);

   /*Declarando o ponto que sera o eixo de rotacao (nesse caso eh o Centro de Massa)
    * obs.: coloquei o centro de massa depois que transladou*/
   Point pcm;
   pcm.setXY(-1.0, 2.5);

   //Imprimindo a Quantidade de Vertices que a figura recebeu
   cout << "Quantidade de Vertices: " << R.qtdeVertice() << endl;

   //Imprimindo o poligono que nesse caso eh um retangulo
   R.imprimePoligono();

   //Imprimindo a area do poligono
   cout << "Area: " << R.areaPoligono() << "\n\n";

   //Transladando o poligono para depois vertificar a area
   R.transladaPoligono(-3.0, 4.0);
   cout << "Area depois que o poligono foi transladado: " << R.areaPoligono() << "\n\n";
   R.imprimePoligono();

   //Rotacionando o poligono para depois verificar a area
   R.rotacionaPoligono(30, pcm);
   cout << "Area depois que o poligono foi rotacionado: " << R.areaPoligono() << "\n\n";
   R.imprimePoligono();

    /*p.setX(x);
    p.setY(y);
    p.imprime();
    cout << "A norma do ponto eh: " << p.norma() << endl;

    p1.setX(1);
    p1.setY(2);
    p.add(p1);
    p.imprime();
    p.sub(p1);
    p.imprime();
    p.translada(3,5);
    p.imprime();*/

}
