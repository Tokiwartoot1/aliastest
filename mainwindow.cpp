#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;
QVector <QString> v;
QString s;
string s2;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(setWord()));


QFile file ("input.txt");
if (file.open(QIODevice::ReadOnly))
{
    QTextStream stream(&file);

    while (!stream.atEnd())
    {
        s = stream.readLine();
        v.push_back(s);
        qDebug() << s;
    }
}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setWord()
{


    ui->label->setText(s);
}
