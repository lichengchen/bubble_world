#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QVector>
#include <QTimer>
#include <QKeyEvent>

#include "bubble.h"

#define MX 800
#define MY 600

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();
    void init_bubbles();
    void add_bubble(QPointF pos, int r, QPointF v);
    void draw_one_bubble(Bubble b, QPainter& p);
    void draw_all_bubbles(QPainter & p);
    void update_bubbles();
    bool handle_collisions();
    bool isBordered(Bubble b1,Bubble b2);

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_timeout();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap map;    //矩形区域
    QPixmap initMap;
    QPoint O;   //原点
    QPointF field;   //场
    QVector<Bubble> bubbles;
    QTimer *timer;
    int ts; //time slot
};

#endif // MAINWINDOW_H
