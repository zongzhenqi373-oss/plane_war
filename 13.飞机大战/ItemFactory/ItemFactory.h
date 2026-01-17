#pragma once
#include "../Item/ShieldItem.h"
#include "../Item/BulletItem.h"
#include"../Item/Item.h"
#include <string>
using namespace std;

class ItemFactory {
public:
    Item* createItem(const std::string& type);
};