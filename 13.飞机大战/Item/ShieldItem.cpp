#include"ShieldItem.h" 
#include"../Config/Config.h" 
#include<Windows.h>


void ShieldItem::init() { 
	::loadimage(&m_img, L"./res/shield.jpg"); 
	m_x = rd() % (BACK_W - SHIELD_W); 
	m_y = -SHIELD_H;
} 

void ShieldItem::show() { 
	::putimage(m_x, m_y, &m_img, SRCCOPY);
} 

bool ShieldItem::isHitPlayer(Player* player)
{
    int x1 = player->m_x;
    int y1 = player->m_y;
    int x2 = player->m_x + PLAYER_W;
    int y2 = player->m_y + PLAYER_H;
    int x3 = m_x + SHIELD_W;
    int x4 = m_y + SHIELD_H;

    // 如果没有重叠，返回 false
    if (x2 <= m_x || x3 <= x1 || y2 <= m_y || x4 <= y1) return false;
    // 否则有重叠
    return true;
}