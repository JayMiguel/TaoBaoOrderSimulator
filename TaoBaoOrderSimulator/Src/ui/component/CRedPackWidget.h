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

#include "RoundButton.h"
#include "CRedPackDlg.h"
#include "RedPack.h"

class CRedPackWidget : public QWidget
{
	Q_OBJECT
public:
	CRedPackWidget(QWidget* parent = nullptr);
	~CRedPackWidget();

private slots:
	void onAddClicked();
	void onRemoveClicked();
	void onAddRedPack(double money);

private:
	QVBoxLayout* m_layout;
	QTableView* m_table;
	QStandardItemModel* m_model;

	RoundButton* m_addBtn;
	RoundButton* m_removeBtn;

	CRedPackDlg* m_dialog;
};

