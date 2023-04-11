#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    mdiArea = new QMdiArea();
    setCentralWidget(mdiArea);
    QDockWidget *dockLeft1=new QDockWidget(tr("左边窗口1"),this);
    addDockWidget(Qt::LeftDockWidgetArea,dockLeft1);
    QDockWidget *dockLeft2=new QDockWidget(tr("左边窗口2"),this);
    addDockWidget(Qt::LeftDockWidgetArea,dockLeft2);
    QDockWidget *dockRight1=new QDockWidget(tr("右边窗口1"),this);
    addDockWidget(Qt::RightDockWidgetArea,dockRight1);
    QDockWidget *dockRight2=new QDockWidget(tr("右边窗口2"),this);
    addDockWidget(Qt::RightDockWidgetArea,dockRight2);
    QDockWidget *dockBottom1=new QDockWidget(tr("底边窗口1"),this);
    addDockWidget(Qt::BottomDockWidgetArea,dockBottom1);
    QDockWidget *dockBottom2=new QDockWidget(tr("底边窗口2"),this);
    addDockWidget(Qt::BottomDockWidgetArea,dockBottom2);
}
