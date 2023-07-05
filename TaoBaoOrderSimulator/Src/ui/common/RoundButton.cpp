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

    // ����Բ�Ǿ��α���
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(option.palette.button());
    painter.drawRoundedRect(rect(), 10, 10);

    // ���ư�ť�ı�
    painter.setPen(option.palette.buttonText().color());
    painter.drawText(rect(), Qt::AlignCenter, option.text);
}