#pragma once
#pragma execution_character_set("utf-8")

#include <memory>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QPushButton>

#include "CRedPackDlg.h"

class RedPack
{
public:
	explicit RedPack(const double& money);
	~RedPack();

private:
	int id;
	double max;
	double surplus;
};

class CRedPackWidget : public QWidget
{
	Q_OBJECT
public:
	CRedPackWidget(QWidget* parent = nullptr);
	~CRedPackWidget();

private slots:
	void onAddClicked();
	void onRemoveClicked();
	void onAddRedPack(const double money);

private:
	QVBoxLayout* m_layout;
	QTableView* m_table;
	QStandardItemModel* m_model;

	QPushButton* m_addBtn;
	QPushButton* m_removeBtn;

	CRedPackDlg* m_dlg;

	QVector<std::shared_ptr<RedPack>> m_vRedPack;
};

