#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>
#include <QMouseEvent>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mause pressed at : "<< event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
     qDebug() << "Mause released"  << event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Mause move"<< event->pos();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "Widget about to close";
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "Context menu event";

    QMenu *mMenu = new QMenu(this);

    mMenu->addAction(("addMenu1"));
    mMenu->addAction(("addMenu1"));

    mMenu -> popup(mapToGlobal(event->pos()));

    qDebug() << "Event reason : " << event->reason();
}

void Widget::enterEvent(QEvent *event)
{
    qDebug()<< "Enter event";
}

void Widget::leaveEvent(QEvent *event)
{
    qDebug()<< "Leave event";
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed: "<< event->key()<< " : " << event->text();
}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug() << "Paint event triggered";
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Widget resized, old size: " << event->oldSize();
    qDebug() << "Widget, new size: " << event->size();
}

