#pragma once
#include <QObject>
class CEnvironment :
	public QObject
{
protected:
	double m_xll;
	double m_yll;
	double m_cellsize;
	int m_nRows;
	int m_nCols;

public:
	CEnvironment(void);
	~CEnvironment(void);

	// constructor
	CEnvironment(int rows, int cols, double xll, double yll, double cellsize);
};

