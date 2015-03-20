#include "MainWindowScene.h"
#include <QPainter>
#include <QtGui>
MainWindowScene::MainWindowScene(void)
{
	pFire = NULL;
}


MainWindowScene::~MainWindowScene(void)
{
}

void MainWindowScene::setFire(int ** f)
{

	pFire = f;
}

void MainWindowScene::drawFire()
{
	QPainter painter;
	
	QRectF rect = this->sceneRect();
	QImage image(101,101,QImage::Format_RGB32) ;

	if (pFire == NULL)
	{
		return;
	}
	for (int i = 0;i<101;i++)
	{
		for (int j = 0; j<101;j++)
		{

			QRgb qValue = qRgb(i,0,0);
			image.setPixel(i,j,pFire[i][j]);

		}
	}
	//qDebug()<<"drawbackground()";
	QPixmap pix(101,101);
	pix.convertFromImage(image);
	this->clear();
	this->addPixmap(pix);
	//painter.drawImage(rect,image);
}

static const int GRID_STEP = 30;  

inline qreal round(qreal val, int step) {  
	int tmp = int(val) + step /2;  
	tmp -= tmp % step;  
	return qreal(tmp);  
}  
/*void MainWindowScene::drawBackground(QPainter *painter, const QRectF &rect)  
{ */ 
	//int step = GRID_STEP;  
	//painter->setPen(QPen(QColor(200, 200, 255, 125)));  
	// draw horizontal grid  
/*	qreal start = round(rect.top(), step);  
	if (start > rect.top()) {  
		start -= step;  
	}  
	for (qreal y = start - step; y < rect.bottom(); ) {  
		y += step;  
		painter->drawLine(rect.left(), y, rect.right(), y);  
	} */ 
	// now draw vertical grid  
	//	start = round(rect.left(), step);  
	//if (start > rect.left()) {  
	//start -= step;  
	//}  
	//for (qreal x = start - step; x < rect.right(); ) {  
	//x += step;  
	//painter->drawLine(x, rect.top(), x, rect.bottom());  
	//}  
	//QImage image(101,101,QImage::Format_RGB32) ;
	//
	//if (pFire == NULL)
	//{
	//	return;
	//}
	//for (int i = 0;i<101;i++)
	//{
	//	for (int j = 0; j<101;j++)
	//	{

	//		QRgb qValue = qRgb(i,0,0);
	//		image.setPixel(i,j,pFire[i][j]);

	//	}
	//}
	//qDebug()<<"drawbackground()";
	//painter->drawImage(rect,image);
//	qDebug()<<"QGraphicsScene drawbackground()";
//}  