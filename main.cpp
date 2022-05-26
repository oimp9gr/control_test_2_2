#include <QApplication>

#include <QObject>

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>

constexpr int Height = 600;
constexpr int Width = 600;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene(0,0, 600, 600);

    QGraphicsRectItem * rect = new QGraphicsRectItem(0,0,50,50);

    scene->addItem(rect);

    QTimer * timer = new QTimer;

    QObject::connect(timer, &QTimer::timeout, [rect]() {
        rect->moveBy(10,10);
    });

    timer->start(1000);

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
    return a.exec();
}


