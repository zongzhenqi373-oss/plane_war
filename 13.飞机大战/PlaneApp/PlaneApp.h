#pragma once
#include"../CGameFrame/CGameFrame.h"  //  ../表示相对于当前文件的路径
#include"../Back/Back.h"
#include"../Player/Player.h"
#include"../GunList/GunList.h"
#include"../FoeList/FoeList.h"
#include"../FacFoe/FacFoe.h"
#include"../Level/Level.h"
#include <mmsystem.h>   // Windows 多媒体
#pragma comment(lib, "winmm.lib") // 链接库
#include "../Item/Item.h"
#include "../ItemFactory/ItemFactory.h"



class PlaneApp:public CGameFrame {
public:
	Back m_back;
	Player &m_player;
	GunList m_gunList;
	FoeList m_foelist; 
	FacFoe pffoe;
	int m_score;

	HWND m_levelTipHwnd;    // 弹窗的句柄
	DWORD m_levelTipStart;        // 弹窗开始时间
	int m_showingLevelTip;   // 是否正在显示关卡提示

	//观察者链表
	list<Observer*>m_lstObserver;

	Level m_level; // 新增关卡管理器

	//新增道具
	list<Item*> m_itemList;      // 道具链表
	ItemFactory m_itemFactory;        // 道具工厂
	int m_bulletPower;            // 子弹威力
	int m_shieldCount;            // 护盾层数

	DWORD m_bulletBuffEnd;    // 子弹增强结束时间
	DWORD m_shieldBuffEnd;    // 护盾效果结束时间

public:
	PlaneApp();
	~PlaneApp();
	virtual void On_Init();
	virtual void On_Paint();
	virtual void On_Close();
	virtual void InitMsgMap();
	void On_WM_KEYDOWN(int);
	void On_WM_TIMER(WPARAM, LPARAM);
	void setTimer();
	void killTimer();
	void showScore();
	void pushObserver(Observer* pb);
	void popObserver(Observer* pb);
	void showLevelTip(int );
	void AddScore(Foe*);
	void showItem();

};