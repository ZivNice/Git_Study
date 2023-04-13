#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDockWidget>
#include<QLabel>
#include<QMdiArea>
#include<QApplication>
#include<imgpreviewwin.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initWindow();

    QMdiArea *mdiArea;

};

#endif // MAINWINDOW_H
