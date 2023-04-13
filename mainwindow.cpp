#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QtCore>
#include <QStorageInfo>
#include <QSettings>
#include <QDebug>
#define GB (1024*1024*1024)
#define _WIN32_DCOM
#include <iostream>
#include <comdef.h>
#include <Wbemidl.h>
#include <string>
#include <QThread>
#include <QObject>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
    QString memoryStr = getMemory();
//    qDebug() <<memoryStr;
    QLabel *titleLabel = new QLabel;//定义一个label
    titleLabel->setText(memoryStr);//label显示内容
    statusBar()->addWidget(titleLabel);//将label加到状态栏上
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    this->showMaximized();
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
    QMdiArea *test=new QMdiArea(mdiArea);
}
const QString MainWindow::getMemory()
{
    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof (statex);
    GlobalMemoryStatusEx(&statex);
    double m_totalMem = statex.ullTotalPhys  * 1.0/ GB;
    double m_freeMem = statex.ullAvailPhys * 1.0 / GB;

    double m_percent = m_freeMem/m_totalMem*100;
//    QString m_memDescribe = QString("可用 %1 GB / 共 %2 GB 占用率%3%" ).
//            arg(QString::asprintf("%.2f", m_freeMem)).arg(QString::asprintf("%.2f", m_totalMem)).arg(QString::asprintf("%.1f", m_percent));
    QString m_memDescribe = QString("CPU占用率%3%" ).arg(QString::asprintf("%.1f", m_percent));

    return m_memDescribe;
}

