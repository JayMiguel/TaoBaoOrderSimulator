#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QPushButton>

class COrderWidget : public QWidget
{
	Q_OBJECT
public:
	COrderWidget(QWidget* parent = nullptr);
	~COrderWidget();

private slots:
	void onAddClicked();
	void onRemoveClicked();

private:
	QVBoxLayout* m_layout;
	QTableView* m_table;
	QStandardItemModel* m_model;

	QPushButton* m_addBtn;
	QPushButton* m_removeBtn;
};

