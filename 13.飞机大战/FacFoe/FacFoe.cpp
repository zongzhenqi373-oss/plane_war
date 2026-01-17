#include"FacFoe.h"
#include"../FoeList/FoeBig.h"
#include"../FoeList/FoeMid.h"
#include"../FoeList/FoeSma.h"


Foe* FacFoe::createFoe(const string& type)
{
	if (type == "sma")
	{
		return new FoeSma;

	}else if (type == "mid")
	{
		return new FoeMid;

	}else if (type == "big")
	{
		return new FoeBig;
	}
	return nullptr;
}