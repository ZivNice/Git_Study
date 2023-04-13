#ifndef IMGPREVIEWWIN_H
#define IMGPREVIEWWIN_H
#include<QGridLayout>
#include<QScrollArea>
#include<QLabel>
#include<QGroupBox>
#include<QDebug>
#include<QHBoxLayout>
#include<QImage>
#include<QString>
#include <QObject>

class CreateImageShow
{
    public:

        void createSingeImgShow();
};
class ImgPreviewWin: public QWidget
{
public:
    ImgPreviewWin(QWidget *parent);
    void createSingeImgShow();
};

#endif // IMGPREVIEWWIN_H
