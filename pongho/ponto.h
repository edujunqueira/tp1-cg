#ifndef _PONTO_CLASS
#define _PONTO_CLASS

class ponto
{

private:

    // coordenadas do ponto
    float x, y;

public:

    // constructor
    ponto(float fx, float fy){x=fx; y=fy;}

    // getters e setters
    float getX(){return x;}
    float getY(){return y;}
    void setX(float newX){x = newX;}
    void setY(float newY){y = newY;}
    void setPonto(float newX, float newY){x=newX; y=newY;}
};

#endif /*_PONTO_CLASS*/
