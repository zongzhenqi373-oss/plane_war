#pragma once
#include<list>
using namespace std;
#include"Gun.h"
#include"../Observer/Observer.h"


class GunList:public Observer {
public:
	list<Gun*> m_lstGun;
public:
	GunList();
	~GunList();
	void showAll();
	void moveAll();
	virtual void notifyshow();



};