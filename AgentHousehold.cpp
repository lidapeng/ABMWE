#include "AgentHousehold.h"


CAgentHousehold::CAgentHousehold(void)
	: m_nVehicle(0)
	, m_longtitude(0)
	, m_latitude(0)
{
	m_bEvac = false;	
}
CAgentHousehold::CAgentHousehold(int houseID, float lon, float lat, int nVehicles)
{
	m_houseID = houseID;
	m_longtitude = lon;
	m_latitude = lat;
	m_nVehicle = nVehicles;
}

CAgentHousehold::~CAgentHousehold(void)
{
}

int CAgentHousehold::getNumVehicle()
{
	return m_nVehicle;
}


// set the number of vehicles 
int CAgentHousehold::setNumVehicle(int numVehicle)
{
	m_nVehicle = numVehicle;
	
	return m_nVehicle;
}


void CAgentHousehold::run(void)
{

	nTStep++;
}
