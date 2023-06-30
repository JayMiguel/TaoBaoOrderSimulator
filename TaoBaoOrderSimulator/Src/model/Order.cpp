#include "Order.h"

Order::Order(double& total)
{
	m_total = total;

	while (total != 0)
	{
		auto maxRedPack = std::max_element(vecRedPack.begin(), vecRedPack.end());
		RedPack* redPack = (*maxRedPack)->split(total);
		m_vRedPack.push_back(redPack);
	}
}

Order::~Order()
{

}