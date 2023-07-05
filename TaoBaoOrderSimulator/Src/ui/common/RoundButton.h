#pragma once
#include <QPushButton>
#include <QPainter>
#include <QStyleOptionButton>
class RoundButton : public QPushButton
{
	Q_OBJECT

public:
	RoundButton(const QString& text = nullptr, QWidget* parent = nullptr);
	~RoundButton();

protected:
	void paintEvent(QPaintEvent* event) override;
};

