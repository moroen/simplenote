#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//! [0]
#include "ui/ui_mainwindow.h"
#include <QCloseEvent>
//! [0]

//! [1]
class MainWindow : public QWidget, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    
protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void save_text(QString);
    QString load_text();
    QString get_path();

private slots:
    void test_clicked();

};
//! [1]

#endif