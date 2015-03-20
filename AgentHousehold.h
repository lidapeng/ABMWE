#pragma once
#include "agent.h"
class CAgentHousehold :
	public CAgent
{
private:
	int m_houseID; //household ID
	// number of vehicles
	int m_nVehicle;
	// longitude coordinate
	float m_longtitude;
	// latitude coordinate
	float m_latitude;
	// cell ID
	long m_cellID;
	/*variables concerning evacuation*/
	bool m_bEvac; // evacuate
	int m_nEvacTime; // evacuation time
	bool m_bOrderReceived; // order received
	int m_nRecOrderTime; // time when evacuation order is received

public:
	// set the number of vehicles 
	int setNumVehicle(int numVehicle);
	CAgentHousehold(void);
	CAgentHousehold(int houseID, float lon, float lat, int nVehicles);
	~CAgentHousehold(void);
	
	int getNumVehicle(); //get the number of vehicles
	void run(void);
};

