#include "RoundButton.h"

RoundButton::RoundButton(const QString& text, QWidget* parent) : QPushButton(text, parent)
{
    this->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 1); }");
}

RoundButton::~RoundButton()
{

}

void RoundButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QStyleOptionButton option;
    initStyleOption(&option);

    // 绘制圆角矩形背景
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(option.palette.button());
    painter.drawRoundedRect(rect(), 10, 10);

    // 绘制按钮文本
    painter.setPen(option.palette.buttonText().color());
    painter.drawText(rect(), Qt::AlignCenter, option.text);
}