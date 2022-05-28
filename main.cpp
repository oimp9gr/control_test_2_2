#include <QApplication>

#include <QObject>

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include <QPen>
#include <QColor>
#include <QPixmap>
#include <QTimer>

// RGB (red green blue) can represent more 16 millions different colors
// (255, 0, 0) stands for red
// (0, 0, 255) stands for blue
const QPen redPen(QColor(255, 0, 0));
const QPen bluePen(QColor(0, 0, 255));

constexpr int SceneHeight = 500;
constexpr int SceneWidth = 500;


/*
 * Create a rectangle that moves every time the timer timeouts.
 */
void animation() {
    QGraphicsScene * scene = new QGraphicsScene(0,0,SceneWidth, SceneHeight);


    QGraphicsRectItem * rect = new QGraphicsRectItem(0,0,69,420);
    rect->setPen(bluePen);
    rect->setBrush(QBrush(Qt::GlobalColor::blue));

    scene->addItem(rect);

    QTimer * timer = new QTimer;

    // !!!important to copy the pointer, otherwise an error occurs
    QObject::connect(timer, &QTimer::timeout, [rect]() {
        // moveBy is equivalent to calling setPos(pos() + QPointF(dx, dy))
        rect->moveBy(10,10);
    });

    timer->start(150);

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
}

/*
 * Draw a pixmap that bounce back every time it hits a border
 * of a scene.
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    animation();
    return a.exec();
}

/*
 * Draw axes on the scene using the pen provided.
 */


