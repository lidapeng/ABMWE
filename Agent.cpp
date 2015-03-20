#include "Agent.h"


CAgent::CAgent(void)
	: nID(0)
{
	nTStep = 0;
}


CAgent::~CAgent(void)
{
}

int CAgent::setAgentID(int id)
{
	nID = id;
	return nID;
}

int CAgent::getAgentID()
{
	return nID;
}
