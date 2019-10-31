#include <QWidget>
#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QMessageLogger>
#include <QCloseEvent>
#include <QMessageBox>

#include <iostream>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
    QString text = load_text();
    plainTextEdit->setPlainText(text);
}

void MainWindow::test_clicked() {
     
 

    // std::cout << text.toUtf8().constData() << std::endl;
    // std::cout.flush();
}

QString MainWindow::get_path() {
    QString path;

    path = QCoreApplication::applicationDirPath() + QString("/store.txt");
    return path;
}

void MainWindow::save_text(QString text) {
    QString path;
    path = get_path();

    QFile file(path);

    if(!file.open(QIODevice::WriteOnly)){
        file.close();
    } else {
        QTextStream out(&file); out << text;
        file.close();
    }
};

QString MainWindow::load_text(void) {
    QString fileName = get_path();
    QFile file(fileName);

    file.open(QIODevice::Text | QIODevice::ReadOnly);
    QString content;
    while(!file.atEnd())
        content.append(file.readLine());

    file.close();

    return content;   
};

void MainWindow::closeEvent(QCloseEvent *event)
{
    QString text;
    text  = plainTextEdit->toPlainText();
    save_text(text);
};