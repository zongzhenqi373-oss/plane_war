#include"Player.h"
#include"../Config/Config.h"
#include"../GunList/Gun.h"

Player::Player():m_x(0),m_y(0),m_blood(1) {}
Player::~Player() {}

void Player::init() {
	::loadimage(&m_img, L"./res/player.jpg");
	::loadimage(&m_maskimg, L"./res/player_mask.jpg");
	m_x = (BACK_W - PLAYER_W) / 2;
	m_y = BACK_H - PLAYER_H;

}
void Player::show() {
	//屏蔽图：位或操作
	::putimage(m_x, m_y, &m_maskimg, SRCPAINT);

	//原图，位于操作
	::putimage(m_x, m_y, &m_img, SRCAND);

}
void Player::move(int direct) {
	if (direct == VK_UP)
	{
		if (m_y - PLAYER_MOVE_STEP >= 0)
		{
			m_y -= PLAYER_MOVE_STEP;
		}
		else
		{
			m_y = 0;
		}

	}
	else if (direct == VK_DOWN)
	{
		if (m_y + PLAYER_MOVE_STEP <= BACK_H - PLAYER_H)
		{
			m_y += PLAYER_MOVE_STEP;
		}
		else
		{
			m_y = BACK_H - PLAYER_H;
		}
	}
	else if (direct == VK_LEFT)
	{
		if (m_x - PLAYER_MOVE_STEP >= 0)
		{
			m_x -= PLAYER_MOVE_STEP;
		}
		else
		{
			m_x = 0;
		}
	}
	else if (direct == VK_RIGHT)
	{
		if (m_x + PLAYER_MOVE_STEP <= BACK_W - PLAYER_W)
		{
			m_x += PLAYER_MOVE_STEP;
		}
		else
		{
			m_x = BACK_W - PLAYER_W;
		}
	}


}

//发射炮弹
Gun* Player::SendGun() {
	Gun*pGun = new Gun;  //创建并初始化
	pGun->init(this);
	return pGun;
}


Player& Player::CreatePlayer() {
	static Player player;
	return player;

}

void Player::notifyshow()
{
	show();
}