#include <QWidget>
#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QMessageLogger>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSettings>

#include <iostream>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    QCoreApplication::setOrganizationName("moroen");
    QCoreApplication::setOrganizationDomain("moroen.com");
    QCoreApplication::setApplicationName("SimpleNote");

    QSettings settings;

    restoreGeometry(settings.value("MainWindow/geometry").toByteArray());

    QString text = settings.value("contents").toString();

    // QString text = load_text();
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

void MainWindow::save_settings() {
    /* 
    QString path;
    path = get_path();

    QFile file(path);

    if(!file.open(QIODevice::WriteOnly)){
        file.close();
    } else {
        QTextStream out(&file); out << text;
        file.close();
    }*/

    QSettings settings;
    QString text = plainTextEdit->toPlainText();
    settings.setValue("contents", text);
};


void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;

    settings.setValue("MainWindow/geometry", saveGeometry());
    // settings.setValue("windowState", saveState());
    save_settings();
};