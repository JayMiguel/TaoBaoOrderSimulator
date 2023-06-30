#pragma once
#include <QObject>
#include <QStandardItem>

class RedPack : public QObject
{
	Q_OBJECT
public:
	explicit RedPack(double money);
	RedPack(const int& id, const double& total, const double& surplus);
	~RedPack();

	RedPack* split(double& money);

	static bool compare(const RedPack& pack1, const RedPack& pack2) {
		return pack1.m_surplus > pack2.m_surplus;
	}

	bool operator<(const RedPack& other) const {
		// 在这里定义自定义的比较规则
		return m_surplus < other.m_surplus;
	}

private:
	int generateId();

public:
	static int curId;

	int m_id;
	double m_total;
	double m_surplus;

	QStandardItem* m_itemNum;
	QStandardItem* m_itemTotal;
	QStandardItem* m_itemSurplus;
};

extern QVector<RedPack*> vecRedPack;
