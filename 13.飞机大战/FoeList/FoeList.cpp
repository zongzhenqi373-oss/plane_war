#include"FoeList.h"
#include<typeinfo>
using namespace std;
#include"FoeBig.h"
#include"FoeMid.h"
#include"FoeSma.h"
#include"../Config/Config.h"

FoeList::FoeList(){}
FoeList::~FoeList() {
	for (Foe* &pFoe : m_lstFoe)
	{
		delete pFoe;
		pFoe = nullptr;
	}

	for (Foe* pBFoe : m_lstBoomFoe)
	{
		delete pBFoe;
	}

}
void FoeList::showAll() {
	for (Foe*& pFoe : m_lstFoe)
	{
		pFoe->show();
	}

	for (Foe* pBFoe : m_lstBoomFoe)
	{
		pBFoe->show();
	}
}
void FoeList::moveAll() {
	list<Foe*>::iterator it = m_lstFoe.begin();
	while (it != m_lstFoe.end())
	{
		if (*it)
		{
			//RTTI：运行时类型识别：
			//typeid(/*类型，表达式，变量*/)
			if (typeid(**it) == typeid(FoeSma))
			{
				(*it)->move(8);
			}else if (typeid(**it) == typeid(FoeMid))
			{
				(*it)->move(5);
			}else if (typeid(**it) == typeid(FoeBig))
			{
				(*it)->move(3);
			}

			//判断是否出界
			if ((*it)->m_y >= BACK_H)
			{
				//删除飞机本身
				delete (*it);

				//删除节点
				it = m_lstFoe.erase(it);
				continue;
			}
			
		}
		++it;
	}

}


void FoeList::notifyshow()
{
	showAll();
}