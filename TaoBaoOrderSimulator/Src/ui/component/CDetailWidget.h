#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItem>
#include <QStandardItemModel>

class CDetailWidget : public QWidget
{
	Q_OBJECT
public:
	CDetailWidget(QWidget* parent = nullptr);
	~CDetailWidget();

private:
	QVBoxLayout* m_layout;
	QTableView* m_table;
	QStandardItemModel* m_model;
};

