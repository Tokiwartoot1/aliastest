#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(setWord()));

    QFile file("input.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);

        while (!stream.atEnd()) {
            QString s = stream.readLine();
            qDebug() << s;

            m_words.push_back(s);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setWord()
{
    if (m_words.isEmpty())
        return;

    int idx = qrand() % m_words.size();

    ui->label->setText(m_words[idx]);
}
