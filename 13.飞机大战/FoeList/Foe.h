#pragma once
#include<easyx.h>
#include"../Player/Player.h"
#include"../Config/Config.h"
#include<random>
using namespace std;

class Foe {
public:
	IMAGE m_img;
	int m_x;
	int m_y;
	int m_blood;
	int m_showid;

	static random_device rd;   //声明一个真正随机数对象rd，对应的类是random_device
public:
	Foe();
	virtual ~Foe();
	virtual void init() = 0;
	virtual void show() = 0;
	void move(int step);
	virtual bool isHitPlayer(Player* player) = 0;
	virtual int getSize() = 0;


};