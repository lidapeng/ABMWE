#include "FireSimulator.h"
#include <fstream>
#include <sstream>
#include <QtGui>
using namespace std;

FireSimulator::FireSimulator(void)
{
	//initialize the raster data to NULL
	pArray = NULL;
	pFireData = NULL;
	pScene = NULL;
	pView = NULL;
}


FireSimulator::~FireSimulator(void)
{
	if (pArray)
	{
		for(int i =0;i<101;i++)
		{
			delete [] pArray[i];
		}
		delete [] pArray;
	}
	//release the memory for fire data

	if (pFireData)
	{
		for (int j = 0; j<101;j++)
		{
			delete [] pFireData[j];
		}
		delete [] pFireData;
	}
}

void FireSimulator::run()
{
	for(int k = 1; k<2000; k++)
	{
		this->msleep(1);
		for (int i = 0;i<101;i++ )
		//for (int i = 0;i<192;i++ )
		{
			for (int j = 0;j<101;j++)
			//for (int j = 0;j<144;j++)
			{
				QMutex	mutex;
				mutex.lock();
				if (pArray[i][j] == k)
				{
					pFireData[i][j] = 1;
				}
				mutex.unlock();
	/*			if (pScene!=NULL)
				{
					pScene->invalidate();
				}*/
				//if (pView!=NULL)
				//{
				//	pView->update();
				//}
				//qDebug()<<i<<" "<<j;
				emit valueChanged(pFireData);
			}
		}
		//emit dataChanged(int**);

	}
}

void FireSimulator::stop()
{

}

void FireSimulator::setScence(MainWindowScene * s)
{
	pScene = s;
}

void FireSimulator::loadIgnitionData(QString& fileName)
{
	if (pArray == NULL)
	{
		pArray = new int*[101];
		for (int i = 0;i<101;i++)
		{
			pArray[i] = new int[101];
		}
		//pArray = new int*[192];
		//for (int i = 0;i<192;i++)
		//{
		//	pArray[i] = new int[144];
		//}
	}

	if (pFireData ==NULL)
	{
		pFireData = new int*[101];
		for(int i = 0;i<101;i++)
		{
			pFireData[i] = new int[101];
		}
	}
	for (int i = 0;i<101;i++)
	{
		for(int j = 0;j<101;j++)
		{
			pFireData[i][j] = 0;
		}
	}


	ifstream pFile("D:\\Project\\firesim\\Debug\\test1.txt");
	//ifstream pFile("D:\\Project\\firesim\\Debug\\outputa.txt");
	//ifstream pFile("D:\\Project\\Triggers\\WildfireSimulation\\outputa.txt");
	int row, col;
	string line;
	if (pFile.is_open())
	{
		row = 0;
		while(!pFile.eof())
		{
			getline(pFile,line);
			row++;
			if (row >= 7)
			{
				col = 0;
				stringstream ss(line);
				while(ss>>pArray[row-7][col])
				{
					col++;
				}
			}
		}
		pFile.close();

	}
}

int** FireSimulator::getFireData()
{

	return pFireData;
}

void FireSimulator::setView(MainWindowView * v)
{
	if (v!=NULL)
	{
		pView = v;
	}
}