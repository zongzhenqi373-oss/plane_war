#include"FoeBig.h"
#include"../Config/Config.h"


void FoeBig::init() {  
	::loadimage(&m_img, L"./res/foebig.jpg");
	m_x = rd() % (BACK_W - FOEBIG_W);
	m_y = -FOEBIG_W;
	m_blood = 5;
	m_showid = 4;
}
void FoeBig::show() {
	::putimage(m_x, m_y, FOEBIG_W, FOEBIG_H, &m_img, 
		FOEBIG_W, FOEBIG_H * (4 - m_showid), SRCPAINT);

	::putimage(m_x, m_y, FOEBIG_W, FOEBIG_H, &m_img,
		0, FOEBIG_H * (4 - m_showid), SRCAND);

}
bool FoeBig::isHitPlayer(Player* player) {
	int x1 = player->m_x + PLAYER_W / 2;
	int y1 = player->m_y;

	if (m_x <= x1 && x1 <= (m_x + FOEBIG_W) &&
		m_y <= y1 && y1 <= (m_y + FOEBIG_H))
	{
		return true;
	}

	int x2 = player->m_x;
	int y2 = player->m_y + PLAYER_H / 2;

	if (m_x <= x2 && x2 <= (m_x + FOEBIG_W) &&
		m_y <= y2 && y2 <= (m_y + FOEBIG_H))
	{
		return true;
	}

	int x3 = player->m_x + PLAYER_W;
	int y3 = y2;

	if (m_x <= x3 && x3 <= (m_x + FOEBIG_W) &&
		m_y <= y3 && y3 <= (m_y + FOEBIG_H))
	{
		return true;
	}

	return false;
}

int FoeBig::getSize()
{
	return FOEBIG_FLAG;
}