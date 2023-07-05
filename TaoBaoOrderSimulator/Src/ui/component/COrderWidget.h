#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItem>
#include <QStandardItemModel>

#include "RoundButton.h"
#include "COrderDialog.h"
#include "Order.h"

class COrderWidget : public QWidget
{
	Q_OBJECT
public:
	COrderWidget(QWidget* parent = nullptr);
	~COrderWidget();

private slots:
	void onAddClicked();
	void onRemoveClicked();
	void onAddOrder(double total);

private:
	QVBoxLayout* m_layout;
	QTableView* m_table;
	QStandardItemModel* m_model;

	RoundButton* m_addBtn;
	RoundButton* m_removeBtn;

	COrderDialog* m_dialog;

	QVector<std::shared_ptr<Order>> m_vOrder;
};

