#include"Foe.h"

Foe::Foe():m_x(0),m_y(0),m_blood(0),m_showid(0){}
Foe::~Foe(){}


void Foe::move(int step){
	m_y += step;
}

random_device Foe::rd;