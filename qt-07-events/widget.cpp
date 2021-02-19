#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Mouse Position");
    this->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void QWidget::mouseMoveEvent(QMouseEvent *event)
{
    int xPos = event->pos().x();
    int yPos = event->pos().y();
    findChild<QLineEdit *>("xLineEdit")->setText(QString::number(xPos));
    findChild<QLineEdit *>("yLineEdit")->setText(QString::number(yPos));
}
