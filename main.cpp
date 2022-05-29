#include <QApplication>
#include <QMessageBox>
#include <QObject>

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

//Бвла идея с использованием градиента ,но потом решил не использовать
#include <QGradient>

#include <QColor>
#include <QTimer>

void Randcolor(QGraphicsRectItem& rect){
    static int counter = 0;
    switch (counter) {
    case 0:{
        rect.setBrush(Qt::red);
        counter++;
        break;
    }
    case 1:{
        rect.setBrush(Qt::blue);
        counter++;
        break;
    }
    case 2:{
        rect.setBrush(Qt::green);
        counter++;
        break;
    }
    case 3:{
        rect.setBrush(Qt::cyan);
        counter++;
        break;
    }
    case 4:{
        rect.setBrush(Qt::yellow);
        counter = 0;
        break;
    }
    }
}

const constexpr int SceneHeight = 500;
const constexpr int SceneWidth = 500;

void IlikeQT() {
    QGraphicsScene * scene = new QGraphicsScene(0,0,SceneWidth, SceneHeight);

    QGraphicsRectItem * rect = new QGraphicsRectItem(0,0,60,60);
    QGraphicsRectItem * rect1 = new QGraphicsRectItem(440,0,60,60);
    QGraphicsRectItem * rect2 = new QGraphicsRectItem(440,440,60,60);
    QGraphicsRectItem * rect3 = new QGraphicsRectItem(0,440,60,60);
    scene->addItem(rect);
    scene->addItem(rect1);
    scene->addItem(rect2);
    scene->addItem(rect3);
    QTimer * timer = new QTimer;

    QObject::connect(timer, &QTimer::timeout, [rect,rect1,rect2,rect3]() {
        static bool OMG = 1;
        if(OMG){
        rect->moveBy(10,10);
        rect1->moveBy(-10,10);
        rect3->moveBy(10,-10);
        rect2->moveBy(-10,-10);
        }
        if(!OMG){
        rect->moveBy(-10,-10);
        rect1->moveBy(10,-10);
        rect3->moveBy(-10,10);
        rect2->moveBy(10,10);
        }
        Randcolor(*rect);
        Randcolor(*rect1);
        Randcolor(*rect2);
        Randcolor(*rect3);
        if(rect3->pos().x() == 330){
            OMG = 0;
//            QMessageBox msgBox;
//            msgBox.setWindowTitle("GG");
//            msgBox.setText("Disco");
//            msgBox.exec();
//            QApplication::exit();
        }
        if(rect3->pos().x() == 230){
            OMG = 1;
        }
    });

    timer->start(200);

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IlikeQT();
    return a.exec();
}
