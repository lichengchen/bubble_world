#ifndef BUBBLE_H
#define BUBBLE_H

#include <QPoint>

class Bubble
{
public:
    Bubble();
    Bubble(QPointF _pos,int _r, QPointF _v);

    QPointF pos(){return bpos;}
    int r(){return br;}
    QPointF v(){return bv;}
    int mass(){return br*br;}
    double energy();

    void backward();
    void update_pos(int MX,int MY, QPointF field);
    void setV(QPointF _v){bv=_v;}

private:
    QPointF bpos; //  位置
    int br;      //半径
    QPointF bv;   //速度
};

#endif // BUBBLE_H
