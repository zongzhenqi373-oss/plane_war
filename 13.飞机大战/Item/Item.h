#pragma once
#include<easyx.h>
#include"../Player/Player.h"
#include"../Config/Config.h"
#include<random>
using namespace std;

class Item {
public:
	IMAGE m_img;
	int m_x;
	int m_y;

	static random_device rd;   //声明一个真正随机数对象rd，对应的类是random_device
public:
	Item();
	virtual ~Item();
	virtual void init() = 0;
	virtual void show() = 0;
	virtual bool isHitPlayer(Player* player) = 0;
	void move(int step);
	bool isOutOfScreen() const {
		return m_y > BACK_H;
	}


};
