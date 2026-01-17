#include"GunList.h"
#include"../Config/Config.h"


GunList::GunList() {}
GunList::~GunList() {
	//list<Gun*>m_lstGun;
	for (Gun* p : m_lstGun)
	{
		if (p)
		{
			delete p;
		}
	}

}
void GunList::showAll() {
	for (Gun* p : m_lstGun)
	{
		if (p)
		{
			p->show();
		}
	}
}
void GunList::moveAll() {
	//迭代器 iterator, 配合链表来说，主要作用就是遍历，属于链表中的
	list<Gun*>::iterator it = m_lstGun.begin();//取链表的头节点，begin返回链表的头节点
	while (it!=m_lstGun.end())  //取链表的尾节点，end返回链表的尾节点
	{
		if (*it)  //炮弹不为空，则移动
		{
			(*it)->move();

			//判断是否出界
			if ((*it)->m_y <= -GUNNER_H)
			{
				//先删除炮弹本身
				delete (*it);

				//再删除节点，删除的是迭代器it指向的那个节点
				//如果什么也不做，it指向的节点删除后，it会失效（无法使用了）
				//习惯接一下返回值，返回的是删除节点的下一个节点
				it = m_lstGun.erase(it);
				continue;
			}
		}

		++it;
	}


}

void GunList::notifyshow()
{
	showAll();
}

