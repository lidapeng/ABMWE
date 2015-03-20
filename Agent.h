#pragma once
#include <QObject>

//struct GeographicLocation{
//	float longitude;
//	float latitude;
//}Location;

class CAgent:public
	QObject
{
public:
	CAgent(void);
	~CAgent(void);
	virtual void run(void)=NULL;
	int setAgentID(int id);
	int getAgentID();
protected:
	// agent ID
	int nID; // agent ID
	int nTStep; // time step
	
};

