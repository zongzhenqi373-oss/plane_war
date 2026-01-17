#pragma once
#include "Item.h"

class BulletItem : public Item {
public:
    void init() override;
    void show() override;
    bool isHitPlayer(Player* player) override;
};
