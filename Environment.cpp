#include "Environment.h"


CEnvironment::CEnvironment(void)
{
	m_nRows = 0;
	m_nCols = 0;
	m_xll = 0.0;
	m_yll = 0.0;
	m_cellsize = 0.0;
}


CEnvironment::~CEnvironment(void)
{
}


// constructor
CEnvironment::CEnvironment(int rows, int cols, double xll, double yll, double cellsize)
{
	m_nRows = rows;
	m_nCols = cols;
	m_xll = xll;
	m_yll = yll;
	m_cellsize = cellsize;
}
