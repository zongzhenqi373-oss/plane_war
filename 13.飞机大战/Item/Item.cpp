#include"Item.h"

Item::Item() :m_x(0), m_y(0){}
Item::~Item() {}


void Item::move(int step) {
	m_y += step;
}

random_device Item::rd;
