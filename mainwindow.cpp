#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("CrazyBubbles");
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
    if(timer!=nullptr){
        delete  timer;
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    map=initMap;
    QPainter p(&map);
    draw_all_bubbles(p);

    if(!timer->isActive()){
        p.setPen(Qt::red);
        for(int i=0;i<bubbles.size();i++){
            p.drawLine(bubbles[i].pos(),bubbles[i].pos()+20*bubbles[i].v());
            p.drawText(bubbles[i].pos(),QString::number(bubbles[i].v().x())+","+QString::number(bubbles[i].v().y()));
        }
        p.setPen(Qt::black);
    }

    painter.drawPixmap(O,map);
    painter.drawRect(QRect(O,O+QPoint(map.width(),map.height())));

    double allE=0;
    for(int i=0;i<bubbles.size();i++){
        allE+=bubbles[i].energy();
    }
    painter.drawText(O,"total energy="+QString::number(allE));
}

void MainWindow::init()
{
    O=QPoint(40,40);
    initMap=QPixmap(MX,MY);
    initMap.fill(Qt::white);
    map=initMap;
    field = QPointF(0,0);

    init_bubbles();

    //safety_check
    for(int i=0;i<bubbles.size()-1;i++){
        double x=bubbles[i].pos().x();
        double y=bubbles[i].pos().y();
        int r = bubbles[i].r();
        if(x<r||y<r||x+r>MX||y+r>MY){
            QMessageBox::critical(this, "错误", "小球超出边界！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        for(int j=i+1;j<bubbles.size();j++){
            if(isBordered(bubbles[i],bubbles[j])){
                QMessageBox::critical(this, "错误", "初始小球相交！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                return;
            }
        }
    }

    ts=10;
    timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timeout()));
    //timer->start(ts);
}

void MainWindow::init_bubbles()
{
    add_bubble(QPoint(100,100),40,QPoint(-1,-1));
    add_bubble(QPoint(500,400),40,QPoint(1,1));
    add_bubble(QPoint(300,200),20,QPoint(-1,1));
    add_bubble(QPoint(600,500),80,QPoint(3,2));
    add_bubble(QPoint(700,120),60,QPoint(5,0));
    add_bubble(QPoint(200,200),50,QPoint(6,8));
}

void MainWindow::on_timeout()
{
    update_bubbles();
    update();
}

void MainWindow::add_bubble(QPointF pos, int r, QPointF v)
{
    bubbles.append(Bubble(pos,r,v));
}

void MainWindow::draw_one_bubble(Bubble b, QPainter& p)
{
    p.setBrush(QColor(b.energy()));
    p.drawEllipse(b.pos(),b.r(),b.r());
    p.drawText(b.pos()+QPoint(10,10),QString::number(b.energy()));
    p.setBrush(Qt::white);
}

void MainWindow::draw_all_bubbles(QPainter & p)
{
    for(int i=0;i<bubbles.size();i++){
        draw_one_bubble(bubbles[i],p);
    }
}

void MainWindow::update_bubbles()
{
    int conti=true;
    for(int i=0;i<bubbles.size();i++){
        bubbles[i].update_pos(MX,MY,field);
    }
    while(conti){
        if(!handle_collisions()){
            conti=false;
        }
    }
}

bool MainWindow::handle_collisions()
{
    int ret=false;
    for(int i=0;i<bubbles.size()-1;i++){
        for(int j=i+1;j<bubbles.size();j++){
            if(isBordered(bubbles[i],bubbles[j])){

                bubbles[i].backward();
                bubbles[j].backward();

                int m1=bubbles[i].mass();
                int m2=bubbles[j].mass();

                QPointF v1=bubbles[i].v();
                QPointF v2=bubbles[j].v();

                QPointF newV1=((m1-m2)*v1+2*m2*v2)/(m1+m2);
                QPointF newV2=((m2-m1)*v2+2*m1*v1)/(m1+m2);

                bubbles[i].setV(newV1);
                bubbles[j].setV(newV2);

                bubbles[i].update_pos(MX,MY,field);
                bubbles[j].update_pos(MX,MY,field);

                ret = true;
            }
        }
    }
    return  ret;
}

bool MainWindow::isBordered(Bubble b1, Bubble b2)
{
    QPointF vec=b1.pos()-b2.pos();
    if(vec.x()*vec.x()+vec.y()*vec.y()<(b1.r()+b2.r())*(b1.r()+b2.r())){
        return true;
    }
    return false;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Space:{
        if(timer->isActive()){
            timer->stop();
            ui->label->setText("Press Space to start");
            update();
        }
        else{
            ui->label->setText("Press Space to pause and show velocity");
            timer->start(ts);
        }
        break;
    }
    default:
        break;
    }

}

//更新的附加内容：载入快照
void MainWindow::on_pushButton_clicked()
{   //先暂停
    if(timer->isActive()){
        timer->stop();
        ui->label->setText("Press Space to start");
        update();
    }
    //读文件
    QFile file;
    QString f = QFileDialog::getOpenFileName(this, QString("选择文件"), QString(""),QString("TEXT(*.txt)"));
    file.setFileName(f);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        double x,y,vx,vy;
        int r;
        in>>x>>y;
        //重置场
        field = QPointF(x,y);
        //重置球球
        bubbles.clear();
        while(!in.atEnd()){
            in>>x>>y>>r>>vx>>vy;
            add_bubble(QPointF(x,y),r,QPointF(vx,vy));
        }
        file.close();
    }
    //safety_check
    for(int i=0;i<bubbles.size()-1;i++){
        double x=bubbles[i].pos().x();
        double y=bubbles[i].pos().y();
        int r = bubbles[i].r();
        if(x<r||y<r||x+r>MX||y+r>MY){
            QMessageBox::critical(this, "错误", "小球超出边界！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        for(int j=i+1;j<bubbles.size();j++){
            if(isBordered(bubbles[i],bubbles[j])){
                QMessageBox::critical(this, "错误", "初始小球相交！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                return;
            }
        }
    }
}
