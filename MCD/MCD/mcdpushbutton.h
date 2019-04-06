#ifndef MCDPUSHBUTTON_H
#define MCDPUSHBUTTON_H

#include <QPushButton>

class MCDPushButton : public QPushButton
{
    Q_OBJECT

public:
    MCDPushButton(QWidget *parent = 0);
    ~MCDPushButton();

public slots:
    void mousePressEvent(QMouseEvent *e);

signals:
  void was_clicked(const QString& symbol);

};

#endif // MCDPUSHBUTTON_H
