#include <cmath>
#include <iostream>
#include "poligono.h"

using namespace std;

#define PI 3.14159265

/**
 * @brief Poligono::Poligono inicializa todos os vertices com com (0, 0) e o numero de vertices igual a 0
 */
Poligono::Poligono(void)
{
    nVert=0;
    for(int i=0; i<100;i++){
        vert[i].setXY(0.0, 0.0);
    }
}
/**
 * @brief Poligono::insereVertice Este metodo serve para inserir
 * pontos no vetor que serviria para guardar pontos do poligono
 * @param p
 */
void Poligono::insereVertice(Point p){
    int TamAntigo = nVert;
    if(TamAntigo==100){
        cout << "Tamanho maximo de pontos atingido";
        return;
    }
    for (int i=0; i<TamAntigo; i++){
        if(vert[TamAntigo].getX() == p.getX() && vert[TamAntigo].getY() == p.getY()){
            cout << "Este ponto ja existe!";
            return;
        }
    }
    vert[nVert].setXY(p.getX(), p.getY());
    nVert++;
}
/**
 * @brief Poligono::qtdeVertice Retorno a quantidade de vertices que o usuario inseriu
 * @return
 */
int Poligono::qtdeVertice(){
    return nVert;
}

/**
 * @brief Poligono::areaPoligono Calculo da area do POLIGONO
 * @details eh utilizado o metodo SHOELANCE, ou seja eh multiplicado os pontos (x[i] * y[i+1])
 * somando-os e tambem ha subtracao para os pontos x[i-1]*y[i]. Assim o Metodo devolve a area do
 * poligono.
 * @return
 */
float Poligono::areaPoligono(){
    float area = 0.0, areaDiagPrinc=0.0, areaDiagSec=0.0;
    for(int i=0; i<nVert-2; i++){
        areaDiagPrinc+= vert[i].getX()*vert[i+1].getY();
    }
    areaDiagPrinc+=vert[nVert-1].getX()*vert[0].getY();
    for(int i=1; i<nVert; i++){
        areaDiagSec+= vert[i].getX()*vert[i-1].getY();
    }
    areaDiagSec+=vert[0].getX()*vert[nVert-1].getY();

    area = areaDiagPrinc - areaDiagSec;
    area = abs(area)/2;
    return area;
}
/**
 * @brief Poligono::transladaPoligono Metodo para transladar pontos
 * @details soma-se cada coordenadas com as coordenadas que o usuario deu
 * @param a
 * @param b
 */
void Poligono::transladaPoligono(float a, float b){
    for(int i=0; i<nVert; i++){
        vert[i].translada(a, b);
        cout << "O ponto depois de transladado eh: ( " << vert[i].getX() << " , " << vert[i].getY() << ")\n";
    }
}
/**
 * @brief Poligono::CentroMassa
 * @details Este metodo serve para calcular o centro de massa de qualquer poligono.
 * @return
 */
Point Poligono::CentroMassa(){
    float cmx=0.0, cmy=0.0;
    Point cm;
    //Calculando o centro de massa para depois rotacionar a figura em relacao ao centro de massa
    for(int i=0; i<nVert; i++){
        cmx+=vert[i].getX();
        cmy+=vert[i].getY();
    }
    cmx = cmx/nVert;
    cmy = cmy/nVert;
    cm.setXY(cmx, cmy);
    return cm;
}
/**
 * @brief Poligono::rotacionaPoligono Metodo para rotacionar Poligono
 * @details O angulo que eh dado pelo usuario esta em grau e o metodo converte-o para radiano,
 * tambem ele recebe o ponto do usuario que na tela principal tinha colocado o centro de massa direto,
 * ja que o professor pediu para o metodo receber o ponto.
 *
 * No item 1.2 do projeto foi pedido que: 'Rotacionar o polígono de θ graus no sentido anti-horário em
 * torno de um ponto (x0,y0) fornecido pelo usuário.'.
 * Porem no item 1.4 foi pedido 'Rotacione o Retângulo de +30º em relação ao seu centro de massa e
 * recalcule a sua área. Compare-a com a área calculada antes da transformação geométrica'.
 * Sendo assim, apenas coloquei para calcular o centro de massa, mas o valor de referencia que a funcao translada
 * ira usar eh o ponto que foi dado na funcao main.
 * @param theta
 * @param pRot
 */
void Poligono::rotacionaPoligono(float theta, Point pRot){
    float angRad = theta * 180.0 / PI;
    float novoX, novoY;
    Point cm;

    cm = CentroMassa();
    cout << "O centro de massa calculado eh: ( " << cm.getX() << " , " << cm.getY() << " )\n";

    //Transladando os pontos de acordo com o ponto dando pelo usuario, para ocorrer a rotacao em relacao a esses pontos
    for(int i=0; i<nVert; i++){
        vert[i].translada(-pRot.getX(), -pRot.getY());
    }
    cout << "Os pontos depois de rotacionado eh:\n";
    for(int i=0; i<nVert; i++){
        novoX = vert[i].getX()*cos(angRad) - vert[i].getY()*sin(angRad);
        novoY = vert[i].getX()*sin(angRad) + vert[i].getY()*cos(angRad);

        vert[i].setXY(novoX, novoY);
        //cout << "O ponto depois que rotacionado em relacao ao centro de gravidade ou Ponto informado pelo usuario:\n";
        //cout << "( " << vert[i].getX() << " , " << vert[i].getY() << " )\n";
    }

}
/**
 * @brief Poligono::imprimePoligono
 * @details Este metodo apenas imprime as coordenadas (xpos , ypos), nao tem grafico do plano cartesiano
 */
void Poligono::imprimePoligono(){
    if(nVert<3){
        cout<<"Erro! Poligono com numero de vertices invalido\n";
        return;
    }
    cout << "Imprimindo os pontos em anti-horario:" << endl;
    for(int i=0; i<nVert; i++){
        if(i<nVert){
            cout << " -> ";
        }
        vert[i].imprime();
    }
}
