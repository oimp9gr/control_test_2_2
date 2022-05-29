#include "mainwindow.h"

#include <QApplication>
#include <QObject>

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPolygon>
#include<QPainter>
#include <QGraphicsScene>
#include<QPaintEvent>

#include <QPen>
#include <QColor>
#include <QTimer>

const QPen redPen(QColor(255, 0, 0));
const QPen yellowPen(QColor(255, 255, 0));

constexpr int SceneHeight = 500;
constexpr int SceneWidth = 500;


void figures(){
    QGraphicsScene * scene = new QGraphicsScene(0,0,SceneWidth, SceneHeight);

    QGraphicsRectItem * rect1 = new QGraphicsRectItem(0, 0, 60, 60);
    QGraphicsRectItem * rect2 = new QGraphicsRectItem(500, 0, 60,60);



    rect1->setBrush(QBrush(Qt::GlobalColor::red));
    rect2->setBrush(QBrush(Qt::GlobalColor::yellow));

    scene->addItem(rect1);
    scene->addItem(rect2);


    QTimer * timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [rect1, rect2]() {
        rect1->moveBy(20, 20);
        rect2->moveBy(-20,20);

});
      timer->start(100);

      QGraphicsView * view = new QGraphicsView(scene);
      view->show();
 }





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    figures();
    return a.exec();
}
