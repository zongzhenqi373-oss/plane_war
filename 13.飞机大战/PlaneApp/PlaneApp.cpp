#include"PlaneApp.h"
#include"../FoeList/FoeBig.h"
#include"../FoeList/FoeMid.h"
#include"../FoeList/FoeSma.h"
#include"../FacFoe/FacFoe.h"


WND_PARAM(600+15, 800+15, 550, 10, L"飞机大战")
CREATE_OBJECT(PlaneApp)

PlaneApp::PlaneApp():m_score(0),m_player(Player::CreatePlayer()), m_bulletPower(1), m_shieldCount(0),m_levelTipHwnd(nullptr),
						m_levelTipStart(0), m_showingLevelTip(LEVEL_TIPS_NO){}
PlaneApp::~PlaneApp() {}
void PlaneApp::On_Init() {
	m_back.init();
	setTimer();  //程序初始化时，设定的定时器
	m_player.init();

	//播放背景音乐（循环）
	PlaySound(L"./res/playerBk.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	pushObserver(&m_back);
	pushObserver(&m_player);
	pushObserver(&m_gunList);
	pushObserver(&m_foelist);
}
void PlaneApp::On_Paint() {
	//通知所有观察者更新显示
	 for (Observer* pb : m_lstObserver)
	{
		pb->notifyshow();
	}
	//m_back.show();
	//m_player.show();
	//m_gunList.showAll();
	//m_foelist.showAll();
	showScore();

	for (Item* item : m_itemList) {
		item->show();
	}

	showItem();
}
void PlaneApp::On_Close() {}
void PlaneApp::InitMsgMap() {
	INIT_MSGMAP(WM_KEYDOWN, EX_KEY, PlaneApp)
	INIT_MSGMAP(WM_TIMER, EX_WINDOW, PlaneApp)
}
void PlaneApp::On_WM_KEYDOWN(int key) {
	//m_player.move(key);

	if (key == VK_SPACE)  //如果按下空格键，发射炮弹
	{
		Gun* pGun = m_player.SendGun();
		m_gunList.m_lstGun.push_back(pGun);    //链表尾添加一个炮弹

		// 播放子弹音效，多音源可叠加
		PlaySound(L"./res/boost.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
	}
}
void PlaneApp::On_WM_TIMER(WPARAM w,/*携带定时器的id*/ LPARAM l) {
	if (w == 1)//如果定时器id是1，那就执行背景移动
	{
		m_back.move();
	}
	else if (w == 2)
	{
		//判断是否按下方向键
		if (::GetAsyncKeyState(VK_UP))  //如果返回真，则方向按下了
		{
			m_player.move(VK_UP);
		}
		
		if (::GetAsyncKeyState(VK_DOWN))  //如果返回真，则方向按下了
		{
			m_player.move(VK_DOWN);
		}

		if (::GetAsyncKeyState(VK_LEFT))  //如果返回真，则方向按下了
		{
			m_player.move(VK_LEFT);
		}

		if (::GetAsyncKeyState(VK_RIGHT))  //如果返回真，则方向按下了
		{
			m_player.move(VK_RIGHT);
		}
	}
	else if (w == 3)
	{
		m_gunList.moveAll();
	}
	else if (w == 4)
	{
		m_foelist.moveAll();
	}
	else if (w == 5)
	{
		int LastLevel = m_level.getCurrentLevel();   //获取当前的关卡值，记录为上一时刻关卡值
		m_level.updateLevel(m_score);                //根据当前分数更新关卡
		int NextLevel = m_level.getCurrentLevel();   //获取更新过的当前关卡值，记录为下一时刻的关卡值

		if (NextLevel != LastLevel)
		{
			showLevelTip(NextLevel);                 //两个关卡值不相等，那么需要弹出弹窗，提示进入下一关
		}

		const Level::LevelConfig& cfg = m_level.getCurrentLevelConfig();   //只能读取，不能修改

		int n = Foe::rd() % 100;
		Foe* pfoe = nullptr;
		if (n < cfg.smallFoeRate) {
			pfoe = pffoe.createFoe("sma");   //工厂模式创建敌人飞机
		}
		else if (n < cfg.smallFoeRate + cfg.midFoeRate) {
			pfoe = pffoe.createFoe("mid");
		}
		else if (n < cfg.smallFoeRate + cfg.midFoeRate + cfg.bigFoeRate) {
			pfoe = pffoe.createFoe("big");
		}
		if (pfoe)
		{
			pfoe->init();
			m_foelist.m_lstFoe.push_back(pfoe);
		}

		// 根据关卡动态调整敌机生成频率
		::KillTimer(m_hwnd, 5);
		::SetTimer(m_hwnd, 5, cfg.foeSpawnFreq, nullptr);
	}
	else if (w == 6)
	{
		//判断是否爆炸
		bool isBoom = false;

		//最外层是遍历敌人飞机,迭代器遍历
		list<Foe*>::iterator itFoe = m_foelist.m_lstFoe.begin();
		while (itFoe != m_foelist.m_lstFoe.end())
		{
			if ((*itFoe)->isHitPlayer(&m_player))   //如果撞击了玩家飞机
			{
				if (--m_player.m_blood <= 0)
				{
					//窗口停止，停止所有定时器
					killTimer();

					//弹出提示框
					::MessageBox(m_hwnd, L"GameOver~", L"提示", MB_OK);

					//发送退出消息
					::PostMessage(m_hwnd, WM_CLOSE/*窗口关闭*/, 0, 0);
					return;
				}
				else     //如果有血量，撞击之后回到初始位置
				{
					m_player.init();
					m_player.notifyshow();
				}
			}
			
			list<Gun*>::iterator itGun = m_gunList.m_lstGun.begin();
			while (itGun != m_gunList.m_lstGun.end())
			{
				if ((*itGun)->isHitFoe(*itFoe))  //如果炮弹打中敌人飞机
				{
					//删除炮弹
					delete (*itGun);

					//删除炮弹节点
					itGun = m_gunList.m_lstGun.erase(itGun);
					if (((*itFoe)->m_blood -= m_bulletPower) <= 0)   //减血之后爆炸
					{
						//先将这个爆炸的飞机节点添加到爆炸链表
						m_foelist.m_lstBoomFoe.push_back((*itFoe));

						//按照飞机的大小进行加分
						AddScore(*itFoe);

						// 播放爆炸音效，多音源可叠加
						PlaySound(L"./res/boom.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);

						//删除正常链表中的节点
						itFoe = m_foelist.m_lstFoe.erase(itFoe);

						isBoom = true;

						//++m_score;
						//m_score += 5;

						break; 
					}
					continue;
				}
				++itGun;
			}
			if (isBoom)
			{
				isBoom = false;
			}
			else
			{
				++itFoe;
			}
		}
	}
	else if (w == 7)
	{
		list<Foe*>::iterator itBFoe = m_foelist.m_lstBoomFoe.begin();
		while (itBFoe != m_foelist.m_lstBoomFoe.end())
		{
			if ((*itBFoe))
			{
				if (--(*itBFoe)->m_showid < 0)
				{
					//删除飞机
					delete (*itBFoe);
					//删除节点
					itBFoe = m_foelist.m_lstBoomFoe.erase(itBFoe);
					continue;
				}
			}

			++itBFoe;
		}
	}
	else if (w == 8)
	{
		if (m_showingLevelTip && m_levelTipHwnd) {
			DestroyWindow(m_levelTipHwnd);
			m_levelTipHwnd = nullptr;
			m_showingLevelTip = LEVEL_TIPS_NO;
		}
	}
	else if (w == 9)
	{
		for (auto it = m_itemList.begin(); it != m_itemList.end();) {
			(*it)->move(3);

			if ((*it)->isOutOfScreen()) {
				delete* it;
				it = m_itemList.erase(it);
				continue;
			}

			// 检测玩家是否吃到道具
			if ((*it)->isHitPlayer(&m_player)) {
				if (dynamic_cast<ShieldItem*>(*it)) {
					m_shieldCount++;
					m_player.m_blood++;
					m_shieldBuffEnd = GetTickCount() + 10000;  // 10 秒有效期
				}
				else if (dynamic_cast<BulletItem*>(*it)) {
					if (m_bulletPower < 4)
						m_bulletPower++;
					m_bulletBuffEnd = GetTickCount() + 10000;  // 10 秒有效期
				}
				delete* it;
				it = m_itemList.erase(it);
				continue;
			}
			++it;
		}

		// 检查护盾是否过期
		if (m_shieldBuffEnd > 0 && GetTickCount() > m_shieldBuffEnd) {
			m_shieldCount = 0;        // 护盾失效
			if (m_player.m_blood > 1) // 如果之前加了护盾血量，回退
				m_player.m_blood--;
			m_shieldBuffEnd = 0;      // 清空定时
		}

		// 检查子弹增强是否过期
		if (m_bulletBuffEnd > 0 && GetTickCount() > m_bulletBuffEnd) {
			m_bulletPower = 1;        // 恢复原始威力
			m_bulletBuffEnd = 0;
		}


	}
	else if (w == 10)
	{
		int Level = m_level.getCurrentLevel();

		// 根据关卡生成道具
		Item* item = nullptr;
		int n = Foe::rd() % 100;
		if (Level >= 2 && n < 50) {
			if (Level == 2) {
				item = m_itemFactory.createItem("shield");
			}
			else if (Level >= 3) {
				if (n < 20)
					item = m_itemFactory.createItem("shield");
				else
					item = m_itemFactory.createItem("bullet");
			}
			if (item) {
				item->init();
				m_itemList.push_back(item);
			}
		}

	}
}
void PlaneApp::setTimer() {
	//设定定时器的系统函数，全局函数
	//背景移动
	::SetTimer(/*窗口句柄:用来标识窗口的*/m_hwnd,/*定时器id*/1,/*定时器触发频率，ms为单位*/60,nullptr/*不用设定回调函数*/);
	//定时监测飞机玩家的移动，检测是否按下方向键
	::SetTimer(/*窗口句柄:用来标识窗口的*/m_hwnd,/*定时器id*/2,/*定时器触发频率，ms为单位*/20, nullptr/*不用设定回调函数*/);
	//控制炮弹移动的定时器
	::SetTimer(/*窗口句柄:用来标识窗口的*/m_hwnd,/*定时器id*/3,/*定时器触发频率，ms为单位*/30, nullptr/*不用设定回调函数*/);
	//控制敌人飞机移动频率
	::SetTimer(/*窗口句柄:用来标识窗口的*/m_hwnd,/*定时器id*/4,/*定时器触发频率，ms为单位*/30, nullptr/*不用设定回调函数*/);
	//定时创建敌人飞机
	::SetTimer(/*窗口句柄:用来标识窗口的*/m_hwnd,/*定时器id*/5,/*定时器触发频率，ms为单位*/2000, nullptr/*不用设定回调函数*/);
	//定时检测是否碰撞
	::SetTimer(/*窗口句柄:用来标识窗口的*/m_hwnd,/*定时器id*/6,/*定时器触发频率，ms为单位*/10, nullptr/*不用设定回调函数*/);
	//定时切换爆炸飞机效果
	::SetTimer(/*窗口句柄:用来标识窗口的*/m_hwnd,/*定时器id*/7,/*定时器触发频率，ms为单位*/200, nullptr/*不用设定回调函数*/);
	//定时自动关闭关卡提示弹窗
	::SetTimer(m_hwnd, 8, 1500, nullptr);
	//定时检测道具
	::SetTimer(m_hwnd, 9, 10, nullptr);
	//定时创建道具
	::SetTimer(m_hwnd, 10, 3000, nullptr);


}
void PlaneApp::killTimer() {
	::KillTimer(m_hwnd, 1);
	::KillTimer(m_hwnd, 2);
	::KillTimer(m_hwnd, 3);
	::KillTimer(m_hwnd, 4);
	::KillTimer(m_hwnd, 5);
	::KillTimer(m_hwnd, 6);
	::KillTimer(m_hwnd, 7);
	::KillTimer(m_hwnd, 8);
	::KillTimer(m_hwnd, 9);
	::KillTimer(m_hwnd, 10);


}

#include<string>
using namespace std;

void PlaneApp::showScore() {
	wstring sc = L"分数为：" + to_wstring(m_score) +
		         L"关卡：" + to_wstring(m_level.getCurrentLevel());
	
	RECT rect{0,0,200,100};
	//在指定的矩形框内显示文本，水平垂直居中显示
	::drawtext(sc.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	::settextcolor(RGB(0, 0, 0));
}

void PlaneApp::pushObserver(Observer* pb) {
	m_lstObserver.push_back(pb);  //链表尾添加
}

void PlaneApp::popObserver(Observer* pb) {
	list<Observer*>::iterator it = m_lstObserver.begin();
	while (it != m_lstObserver.end())
	{
		if ((*it) == pb)   //找到了，删除,只是删除节点
		{
			it = m_lstObserver.erase(it);
			break;
		}
		++it;
	}

}

void PlaneApp::showLevelTip(int level)
{
	// 防止重复弹窗
	if (m_showingLevelTip)
		return;

	// 创建一个无边框、置顶的小弹窗
	wstring msg = L"进入第 " + to_wstring(level) + L" 关！";

	m_levelTipHwnd = CreateWindowEx(
		WS_EX_TOPMOST | WS_EX_TOOLWINDOW,      // 置顶且不在任务栏显示
		L"STATIC",                            // 使用 STATIC 控件
		msg.c_str(),                          // 提示文本
		WS_POPUP | SS_CENTER | SS_CENTERIMAGE, // 无边框，居中
		0, 0, 300, 100,                       // 大小会在后面调整
		m_hwnd,                               // 父窗口
		nullptr,
		GetModuleHandle(nullptr),
		nullptr
	);

	if (m_levelTipHwnd) {
		// 获取父窗口尺寸，居中显示
		RECT rcParent;
		GetClientRect(m_hwnd, &rcParent);

		int x = rcParent.left + rcParent.right+150;
		int y = rcParent.top + (rcParent.bottom - rcParent.top) / 2;

		SetWindowPos(m_levelTipHwnd, HWND_TOPMOST, x, y, 300, 100, SWP_SHOWWINDOW);

		// 设置背景色
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 200));
		SetClassLongPtr(m_levelTipHwnd, GCLP_HBRBACKGROUND, (LONG_PTR)hBrush);
		InvalidateRect(m_levelTipHwnd, nullptr, TRUE);

		// 记录状态
		m_levelTipStart = GetTickCount();
		m_showingLevelTip = LEVEL_TIPS_YES;
	}

}

void PlaneApp::AddScore(Foe* foe)
{
	int flag = foe->getSize();
	if (flag == FOEBIG_FLAG)
	{
		m_score += 4;
	}
	else if (flag == FOEMID_FLAG)
	{
		m_score += 2;
	}
	else if (flag == FOESMA_FLAG)
	{
		m_score += 1;
	}
}

void PlaneApp::showItem()
{
	wstring sc = L"当前血量：" + to_wstring(m_player.m_blood) +
		L"当前火力：" + to_wstring(m_bulletPower);

	RECT rect{ 800,1400,200,100 };
	//在指定的矩形框内显示文本，水平垂直居中显示
	::drawtext(sc.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	::settextcolor(RGB(0, 0, 0));
}

