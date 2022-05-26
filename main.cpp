#include <QCoreApplication>
#include <QDebug>

#include <QObject>

#include <QtGui/QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include <QPen>
#include <QColor>
#include <QPixmap>
#include <QTimer>

const QPen redPen(QColor(255, 0, 0));
const QPen bluePen(QColor(0, 0, 255));

constexpr int SceneHeight = 500;
constexpr int SceneWidth = 500;



void animation() {
    QGraphicsScene *scene = new QGraphicsScene(0, 0, SceneWidth, SceneHeight);

    QGraphicsRectItem *rect = new QGraphicsRectItem(0, 0, 69, 420);
    rect->setPen(bluePen);
    rect->setBrush(QBrush(Qt::GlobalColor::blue));

    scene->addItem(rect);

    QTimer *timer = new QTimer;

    // !!!important to copy the pointer, otherwise an error occurs
    QObject::connect(timer, &QTimer::timeout, [rect]() {
        // moveBy is equivalent to calling setPos(pos() + QPointF(dx, dy))
        rect->moveBy(10, 10);
    });

    timer->start(150);

    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    animation();
    return a.exec();


}
