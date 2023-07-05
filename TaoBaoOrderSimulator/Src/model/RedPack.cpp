#include "RedPack.h"

QVector<RedPack*> vecRedPack;

int RedPack::curId = 0;

RedPack::RedPack(double money)
{
	m_id = this->generateId();
	m_total = money; 
	m_surplus = money;
}

RedPack::RedPack(const int& id, const double& total, const double& surplus)
{
	m_id = id;
	m_total = total;
	m_surplus = surplus;
}

RedPack::~RedPack()
{

}

int RedPack::generateId()
{
	return curId++;
}

RedPack* RedPack::split(double& money)
{
	RedPack* redPack;
	if (money >= m_surplus)
	{
		redPack = new RedPack(this->m_id, this->m_total, m_surplus);
		money -= m_surplus;
		m_surplus = 0;
		m_itemSurplus->setData(QString::number(m_surplus), Qt::DisplayRole);
	}
	else
	{
		redPack = new RedPack(this->m_id, this->m_total, money);
		m_surplus -= money;
		m_itemSurplus->setData(QString::number(m_surplus), Qt::DisplayRole);
		money = 0;
	}

	return redPack;
}