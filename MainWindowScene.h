#pragma once
#include<QGraphicsScene>

class MainWindowScene :
	public QGraphicsScene
{
public:
	MainWindowScene(void);
	~MainWindowScene(void);
	void setFire(int ** f);
	void drawFire();
protected:
	//void drawBackground(QPainter *painter, const QRectF &rect);
private:
	int ** pFire;

};

