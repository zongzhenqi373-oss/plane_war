#include"ItemFactory.h"

Item* ItemFactory::createItem(const string& type) {
    if (type == "shield") {
        return new ShieldItem();
    }
    else if (type == "bullet") {
        return new BulletItem();
    }
    return nullptr;
}