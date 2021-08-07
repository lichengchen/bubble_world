#include "bubble.h"
#include <QRect>

#include <QDebug>

Bubble::Bubble()
{
    bpos=QPointF(0,0);
    br=1;
    bv=QPointF(0,0);
}

Bubble::Bubble(QPointF _pos, int _r, QPointF _v):bpos(_pos),br(_r),bv(_v)
{

}

void Bubble::update_pos(int MX,int MY, QPointF field)
{
    //场
    bv=bv+field;
    //场结束
    bpos=bpos+bv;


    if(bpos.x()<br || bpos.x()>MX-br){
        bpos=bpos-bv;       //恢复位置
        bv.setX(-bv.x());   //更新速度
        update_pos(MX,MY,field);  //重新计算位置
    }

    if(bpos.y()<br || bpos.y()>MY-br){
        bpos=bpos-bv;
        bv.setY(-bv.y());
        update_pos(MX,MY,field);
    }
}

void Bubble::backward()
{
    bpos=bpos-bv;
}

double Bubble::energy()
{
    return mass()*(bv.x()*bv.x()+bv.y()*bv.y())*0.5;    //1/2mv2
}


/*原始算法  uodate_pos
 * bpos=bpos+bv;
    if(!QRect(QPoint(br,br),QPoint(MX-br,MY-br)).contains(bpos)){
        QPoint pre_bpos=bpos-bv;
        int vx=bv.x();
        int vy=bv.y();
        if(bpos.x()<br || bpos.x()>MX-br){
            vx=-vx;
        }

        if(bpos.y()<br || bpos.y()>MY-br){
            vy=-vy;
        }
        bpos=pre_bpos;  //"回退"

        //更新碰撞边缘后的速度与坐标
        bv=QPoint(vx,vy);
        update_pos(MX,MY);
    }
    */
