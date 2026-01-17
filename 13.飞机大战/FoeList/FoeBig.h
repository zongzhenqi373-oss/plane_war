#pragma once
#include<easyx.h>
#include"../Player/Player.h"
#include"Foe.h"

class FoeBig:public Foe {
public:
	void init() override;      //override修饰虚函数，保证这个虚函数一定是重写父类的虚函数
	void show() override;
	bool isHitPlayer(Player* player) override;
	int getSize()override;


};