#ifndef MCDLINEEDIT_H
#define MCDLINEEDIT_H

#include <QLineEdit>

class MCDLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  MCDLineEdit(QWidget *parent = 0);
  ~MCDLineEdit();

signals:
  void focussed(MCDLineEdit* edit);

protected:
  virtual void focusInEvent(QFocusEvent *e);
  virtual void focusOutEvent(QFocusEvent *e);
};

#endif // MCDLINEEDIT_H
