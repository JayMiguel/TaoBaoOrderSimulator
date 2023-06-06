#pragma once
#pragma execution_character_set("utf-8")
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QPushButton>
#include <QMessageBox>

class CRedPackDlg : public QDialog
{
	Q_OBJECT
public:
	CRedPackDlg(QWidget* parent = nullptr);
	~CRedPackDlg();
	
signals:
	void addRedPack(const double);

public slots:
	int exec();

private slots:
	void onBtnClicked();

private:
	QHBoxLayout* m_layout;
	QLabel* m_label;
	QLineEdit* m_valueLine;
	QPushButton* m_okBtn;
};

