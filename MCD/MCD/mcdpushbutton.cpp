#include "mcdpushbutton.h"

MCDPushButton::MCDPushButton(QWidget *parent)
    : QPushButton(parent)
{}

MCDPushButton::~MCDPushButton()
{}

void MCDPushButton::mousePressEvent(QMouseEvent *e) {
    QPushButton::mousePressEvent(e);
    emit(was_clicked(text()));
}
