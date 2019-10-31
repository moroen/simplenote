#include <QApplication>
#include <QLabel>
#include <QWidget>

#include "mainwindow.h"


int main(int argc, char *argv[ ])
{

QApplication app(argc, argv);
/*
QWidget widget;

Ui::MainWindow ui;
ui.setupUi(&widget);

widget.show();
*/
MainWindow mainWindow;
mainWindow.show();

return app.exec();

}
