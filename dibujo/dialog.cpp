#include "dialog.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

Dialog::Dialog(QWidget *parent) :

QWidget(parent)
{
    defender.load("defender.png");
    setFixedSize(640, 480);
    this->setStyleSheet("background-color: #82CAFF;");
    this->update();

    //QPushButton *quitBtn = new QPushButton("Quit", this);
    //quitBtn->setGeometry(50, 40, 75, 30);
    //connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
    m_button = new QPushButton("Hola", this);
    m_button->setGeometry(500, 300, 80, 30);
    connect(m_button, SIGNAL(clicked()), this, SLOT(resetBtn()));

    lbl = new QLabel("Hola Chidori", this);
    lbl->setGeometry(500, 270, 100, 30);

    m_Text = new QTextEdit(this);
    m_Text->setGeometry(500, 340, 80, 60);
    m_Text->setStyleSheet("background-color: #FFFFFF;");
    //this->update();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
}

Dialog::~Dialog() {
    delete timer;
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);


    // add after the creation of the painter object
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);
    QBrush brush(Qt::yellow);

    painter.setPen (pen);
    painter.setBrush(brush);
    // add before the painter draws the ellipse


    //painter.drawEllipse(dx, dy, 100, 100);

    brush.setColor("#C36241");
    painter.setBrush(brush);
    pen.setWidth(1);

    QPolygon roof;
    roof.putPoints(0, 3, 250, 260, 290, 220, 330, 260);
    painter.drawPolygon(roof);

    brush.setColor("#835C3B");
    painter.setBrush(brush);

    QPolygon house;
    house.putPoints(0, 4, 260, 260, 260, 299, 320, 299, 320, 260);
    painter.drawPolygon(house);

    painter.drawPixmap(dx, dy, defender);
}

void Dialog::nextFrame() {
    // animate the defender
    dx += ds;
    dy += ds;

    update();
}

void Dialog::resetBtn() {
    // animate the defender
    //dx = 30;
    //dy = 30;
    ds=-ds;
    update();
}
