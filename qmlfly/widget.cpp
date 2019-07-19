#include "widget.h"
#include "ui_widget.h"
#include <QQuickWidget>
#include <QPixmap>
#include <QPalette>
#include <QColor>
#include <QQmlEngine>
#include <QQmlContext>
#include <QDate>
#include <QSettings>
#include <QDir>
#include <QTextStream>
#include <QDesktopWidget>
#include <QApplication>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //==================================================================================

    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);//窗口置顶，无边框

    this->setAttribute(Qt::WA_TranslucentBackground);

    this->setAutoFillBackground(true);//填充背景

    //================================================================================
    QPalette palette;

    QPixmap pixmap(":/image/toumingBg.png");

    palette.setBrush(QPalette::Window,QBrush(pixmap));//设置笔刷为背景图片

    this->setPalette(palette);

    this->setFixedSize(getDesktopWidth(),getDesktopHeight()-40);

    //================================================================================
    ui->quickWidget->setClearColor(QColor(Qt::transparent));    //qml 透明

    ui->quickWidget->engine()->rootContext()->setContextProperty("widget",this);

    ui->quickWidget->setSource(QUrl("qrc:/main.qml"));    

    loadData();

}

Widget::~Widget()
{
    delete ui->quickWidget; //特殊，需要手动析构
    delete ui;
}

void Widget::loadData()
{
    QString path = QDir::currentPath() + "/config.ini";

    QFile file(path);

    if(!file.open(QFile::ReadOnly)){
        return;
    }
    QTextStream stream(&file);

    QString line;
//    int num=0;
    QVariantList list;


    while (stream.readLineInto(&line)) {
//        num++;
//        qDebug()<<num<<line;
        list<<line;
    }
    file.close();

    emit readData(list);
}

int Widget::getDesktopWidth()
{
    return QApplication::desktop()->width();
}

int Widget::getDesktopHeight()
{
    return QApplication::desktop()->height();
}
