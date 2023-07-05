#pragma once
#pragma execution_character_set("utf-8")
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

#include "CLineEdit.h"
#include "CPushButton.h"

class COrderDialog : public QDialog
{
	Q_OBJECT

public:
	COrderDialog(QWidget* parent = nullptr);
	~COrderDialog();

signals:
	void addOrder(double total);

public slots:
	int exec() override;
	void onBtnClicked();

private:
	QHBoxLayout* m_layout;
	QLabel* m_label;
	CLineEdit* m_valueLine;
	CPushButton* m_okBtn;
};

