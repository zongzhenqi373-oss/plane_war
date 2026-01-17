#include"Gun.h"
#include"../Config/Config.h"

Gun::Gun():m_x(0),m_y(0){}
Gun::~Gun() {}

void Gun::init(Player* player){
	::loadimage(&m_img, L"./res/gunner.jpg");
	m_x = player->m_x + (PLAYER_W - GUNNER_W) / 2;
	m_y = player->m_y;
}
void Gun::show() {
	//屏蔽图位或
	::putimage(m_x, m_y/*显示到窗口的位置*/, GUNNER_W, GUNNER_H/*显示的宽度和高度*/, 
		&m_img, GUNNER_W, 0/*从图中哪个点开始显示*/, SRCPAINT);
	//原图显示位与
	::putimage(m_x, m_y/*显示到窗口的位置*/, GUNNER_W, GUNNER_H/*显示的宽度和高度*/, 
		&m_img, 0, 0/*从图中哪个点开始显示*/, SRCAND);

}
void Gun::move() {
	m_y -= GUN_MOVE_STEP;

}

#include<typeinfo>
using namespace std;
#include"../FoeList/FoeBig.h"
#include"../FoeList/FoeMid.h"
#include"../FoeList/FoeSma.h"

bool Gun::isHitFoe(Foe* pfoe)
{
	//炮弹中心的点
	int x = m_x + GUNNER_W / 2;
	int y = m_y + GUNNER_H / 2;

	//区分出来不同类型的敌人飞机
	if (typeid(*pfoe) == typeid(FoeSma))
	{
		if (pfoe->m_x <= x && x <= (pfoe->m_x + FOESMA_W) &&
			pfoe->m_y <= y && y <= (pfoe->m_y + FOESMA_H))
		{
			return true;
		}
	}else if (typeid(*pfoe) == typeid(FoeMid))
	{
		if (pfoe->m_x <= x && x <= (pfoe->m_x + FOEMID_W) &&
			pfoe->m_y <= y && y <= (pfoe->m_y + FOEMID_H))
		{
			return true;
		}
	}else if (typeid(*pfoe) == typeid(FoeBig))
	{
		if (pfoe->m_x <= x && x <= (pfoe->m_x + FOEBIG_W) &&
			pfoe->m_y <= y && y <= (pfoe->m_y + FOEBIG_H))
		{
			return true;
		}
	}
	return false;
}