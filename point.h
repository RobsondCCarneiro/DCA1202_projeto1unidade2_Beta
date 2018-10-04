#ifndef POINT_H
#define POINT_H


class Point{
private:
    float x, y;
public:
    void setX(float _x);
    float getX(void);
    void setY(float _y);
    float getY(void);
    void setXY(float _x, float _y);
    void add(Point _p1);
    void sub(Point _p1);
    float norma(void);
    void translada(float a, float b);
    void imprime();
};

#endif // POINT_H
