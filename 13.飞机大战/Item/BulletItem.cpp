#include "BulletItem.h"
#include"../Config/Config.h"

void BulletItem::init() {
    ::loadimage(&m_img, L"./res/bullt3.jpg");
    m_x = rand() % (BACK_W - BULLET_ITEM_W);
    m_y = -BULLET_ITEM_H;
}

void BulletItem::show() {
    ::putimage(m_x, m_y,&m_img,SRCCOPY);
}

bool BulletItem::isHitPlayer(Player* player) {
    int x1 = player->m_x;
    int y1 = player->m_y;
    int x2 = player->m_x + PLAYER_W;
    int y2 = player->m_y + PLAYER_H;
    int x3 = m_x + BULLET_ITEM_W;
    int y3 = m_y + BULLET_ITEM_H;

    if (x2 <= m_x || x3 <= x1 || y2 <= m_y || y3 <= y1) return false;
    return true;
}
