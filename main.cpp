#include "mainwindow.h"
#include "SETTING.h"
#include <windows.h>

#include <QPair>

#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>

#include <QTimer>
#include <QMessageBox>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto * scene = new QGraphicsScene(0,0,VIEW_WIDTH,VIEW_HEIGHT);
        scene->setStickyFocus(true) ;

        auto * view = new QGraphicsView(scene);
        view->setFixedSize(scene->sceneRect().size().toSize());

        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        int OBJ_X = START_POS;
        int OBJ_Y = START_POS;

        QGraphicsRectItem *obj = new QGraphicsRectItem(OBJ_X, OBJ_Y, OBJ_SIZE, OBJ_SIZE);
        scene->addItem(obj);

        bool H = 0;
        bool W = 0;

        QTimer * timer = new QTimer;
        auto * spawnTimer = new QTimer();
            QObject::connect(spawnTimer,&QTimer::timeout,[&](){
                if(H == 0 && W == 0) OBJ_Y += OBJ_SPEED;
                else if(H == 1 && W == 0) OBJ_X += OBJ_SPEED;
                else if(H == 1 && W == 1) OBJ_Y -= OBJ_SPEED;
                else if(H == 0 && W == 1) OBJ_X -= OBJ_SPEED;

                if(OBJ_X == START_POS && OBJ_Y == END_POS) H = 1;
                else if(OBJ_X == END_POS && OBJ_Y == END_POS) W = 1;
                else if(OBJ_X == END_POS && OBJ_Y == START_POS) H = 0;
                else if(OBJ_X == START_POS && OBJ_Y == START_POS) W = 0;

                obj->setRect(OBJ_X, OBJ_Y, OBJ_SIZE, OBJ_SIZE);
            });

    spawnTimer->start(50);
    view->show();
    return a.exec();
}
