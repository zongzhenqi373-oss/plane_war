#include"Back.h"

Back::Back():m_x(0),m_y(0){}
Back::~Back(){}

void Back::init()
{
	::loadimage(&m_img, L"./res/back.jpg"); //图片路径是相对于工程所在文件路径来说的，   ./  代表同级目录
	m_x = 0;
	m_y = -BACK_H;  //去白边原理
}
void Back::show()
{
	::putimage(m_x, m_y, &m_img);

}
void Back::move()
{
	m_y += BACK_MOVE_STEP;
	if (m_y >= 0)   //移动的临界值
	{
		m_y = -BACK_H;  //瞬间回到最初的位置
	}

}

void Back::notifyshow()
{
	show();    //调用自己的show方法，刷新
}