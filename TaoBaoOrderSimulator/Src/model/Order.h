#pragma once
#include "RedPack.h"
#include <algorithm>
class Order
{
public:
	Order(double& total);
	~Order();

	double m_total;
	QVector<RedPack*> m_vRedPack;
};

