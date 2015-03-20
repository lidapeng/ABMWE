#include "mainwindowview.h"
#include <QtGui>

MainWindowView::MainWindowView(QWidget *parent)
	: QGraphicsView(parent)
{
	ui.setupUi(this);

	pFire = NULL;
}

MainWindowView::~MainWindowView()
{

}

void MainWindowView::setFire(int ** f)
{

	if (f!=NULL)
	{
		pFire = f;
	}
	
}


void MainWindowView::drawBackground(QPainter *painter, const QRectF &rect)
{
	QImage image(101,101,QImage::Format_RGB32) ;
	//QImage image(192,144,QImage::Format_RGB32) ;
	if (pFire == NULL)
	{
		return;
	}
	for (int i = 0;i<101;i++)
	//for (int i = 0;i<192;i++)
	{
		for (int j = 0; j<101;j++)
		//for (int j = 0; j<144;j++)
		{

			QRgb qValue = qRgb(255,0,0);
			if (pFire[i][j] == 1)
			{
				image.setPixel(i,j,qValue);
			}
			else
			{
				image.setPixel(i,j,qRgb(255,255,255));
			}
			//image.setPixel(i,j,pFire[i][j]);
			//image.setPixel(i,j,qValue);
		}
	}
	qDebug()<<"drawbackground()";
	painter->drawImage(rect,image);

}


// Paint Event Function
//void MainWindowView::paintEvent(QPaintEvent* event)
//{
//	//QPainter painter(this);
//	//QPen pen(Qt::red);
//	//pen.setWidth(2);
//	//painter.setPen(pen);
//
//	//painter.drawLine(0,0,100,100);
//}
