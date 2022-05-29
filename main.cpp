#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene(0,0, 500, 500);
   QGraphicsEllipseItem * Ellipse = new QGraphicsEllipseItem(0,0,70,70);
   Ellipse->setBrush(QBrush(Qt::cyan));
    scene->addItem(Ellipse);

    QTimer * timer = new QTimer;

    QObject::connect(timer, &QTimer::timeout, [Ellipse]() {
        Ellipse->moveBy(2,2);
    });

    timer->start(30);

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
    return a.exec();
}



