#include "mcdlineedit.h"

MCDLineEdit::MCDLineEdit(QWidget *parent)
 : QLineEdit(parent)
{}

MCDLineEdit::~MCDLineEdit()
{}

void MCDLineEdit::focusInEvent(QFocusEvent *e)
{
  QLineEdit::focusInEvent(e);
  emit(focussed(this));
}

void MCDLineEdit::focusOutEvent(QFocusEvent *e)
{
  QLineEdit::focusOutEvent(e);
  // emit(focussed(false));
}
