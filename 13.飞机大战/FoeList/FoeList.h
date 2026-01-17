#pragma once
#include<list>
using namespace std;
#include"Foe.h"
#include"../Observer/Observer.h"


class FoeList:public Observer {
public:
	list<Foe*> m_lstFoe;
	list<Foe*> m_lstBoomFoe;

public:
	FoeList();
	~FoeList();
	void showAll();
	void moveAll();
	virtual void notifyshow();


};