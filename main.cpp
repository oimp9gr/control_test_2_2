#include <QApplication>

#include <QObject>

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include <QTimer>


constexpr int SceneHeight = 500;
constexpr int SceneWidth = 500;


void box_flying() {

    QGraphicsScene * scene = new QGraphicsScene(0,0,SceneWidth, SceneHeight);

    QGraphicsRectItem * rect = new QGraphicsRectItem(0,0,50,50);

    scene->addItem(rect);

    QTimer * timer = new QTimer;

    QObject::connect(timer, &QTimer::timeout, [rect]() {

        rect->moveBy(10,10);

    });

    timer->start(150);

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    box_flying();
    return a.exec();
}

