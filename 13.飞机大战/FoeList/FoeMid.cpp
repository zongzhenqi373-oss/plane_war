#include"FoeMid.h"
#include"../Config/Config.h"


void FoeMid::init() {
	::loadimage(&m_img, L"./res/foemid.jpg");
	m_x = rd() % (BACK_W - FOEMID_W);
	m_y = -FOEMID_W;
	m_blood = 3;
	m_showid = 3;
}
void FoeMid::show() {
	::putimage(m_x, m_y, FOEMID_W, FOEMID_H, &m_img,
		FOEMID_W, FOEMID_H * (3 - m_showid), SRCPAINT);

	::putimage(m_x, m_y, FOEMID_W, FOEMID_H, &m_img,
		0, FOEMID_H * (3 - m_showid), SRCAND);

}
bool FoeMid::isHitPlayer(Player* player) {
	int x1 = player->m_x + PLAYER_W / 2;
	int y1 = player->m_y;

	if (m_x <= x1 && x1 <= (m_x + FOEMID_W) &&
		m_y <= y1 && y1 <= (m_y + FOEMID_H))
	{
		return true;
	}

	int x2 = player->m_x;
	int y2 = player->m_y + PLAYER_H / 2;

	if (m_x <= x2 && x2 <= (m_x + FOEMID_W) &&
		m_y <= y2 && y2 <= (m_y + FOEMID_H))
	{
		return true;
	}

	int x3 = player->m_x + PLAYER_W;
	int y3 = y2;

	if (m_x <= x3 && x3 <= (m_x + FOEMID_W) &&
		m_y <= y3 && y3 <= (m_y + FOEMID_H))
	{
		return true;
	}


	return false;

}

int FoeMid::getSize()
{
	return FOEMID_FLAG;
}