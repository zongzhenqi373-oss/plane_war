#pragma once
#include<easyx.h>
//#include"../GunList/Gun.h"
#include"../Observer/Observer.h"

class Gun;

class Player:public Observer {
public:
	IMAGE m_img;
	IMAGE m_maskimg;
	int m_x;
	int m_y;
	int m_blood;
	

public:
	void init();
	void show();
	void move(int direct);
	Gun* SendGun();

private:
	Player();
	Player(const Player&) = delete;
	~Player();

public:
	static Player& CreatePlayer();
	virtual void notifyshow();


};