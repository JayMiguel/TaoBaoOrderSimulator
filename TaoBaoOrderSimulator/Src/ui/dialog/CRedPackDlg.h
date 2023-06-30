#pragma once
#pragma execution_character_set("utf-8")
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

#include "CLineEdit.h"
#include "CPushButton.h"

class CRedPackDlg : public QDialog
{
	Q_OBJECT
public:
	CRedPackDlg(QWidget* parent = nullptr);
	~CRedPackDlg();
	
signals:
	void addRedPack(double total);

public slots:
	int exec();

private slots:
	void onBtnClicked();

private:
	QHBoxLayout* m_layout;
	QLabel* m_label;
	CLineEdit* m_valueLine;
	CPushButton* m_okBtn;
};

