#include "imgpreviewwin.h"
#include <QObject>

ImgPreviewWin::ImgPreviewWin(QWidget *parent):QWidget (parent)
{
//    createSingeImgShow();

}

void ImgPreviewWin::createSingeImgShow()
{
    QLabel *imgName = new QLabel(tr("imgname"));
    QLabel *imgShow = new QLabel("imgshow");
    QVBoxLayout *imgNameShowLayout = new QVBoxLayout();
    QGroupBox *groupBx=new QGroupBox(tr("groupbx"),this);

    qreal width=this->width();
    qreal height=this->height();

    imgNameShowLayout->addWidget(imgName);
    imgNameShowLayout->addWidget(imgShow);
    groupBx->setLayout(imgNameShowLayout);


}

void CreateImageShow::createSingeImgShow()
{
    QLabel *imgName = new QLabel("imgname");
    QLabel *imgShow = new QLabel("imgshow");
    QHBoxLayout *imgNameShow = new QHBoxLayout();
}
