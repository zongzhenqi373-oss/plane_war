#pragma once
#include<easyx.h>
#include"../Player/Player.h"
#include"../FoeList/Foe.h"
class Gun {
public:
	IMAGE m_img;
	int m_x;
	int m_y;
public:
	Gun();
	~Gun();
	void init(Player* player);
	void show();
	void move();
	bool isHitFoe(Foe* pfoe);



};