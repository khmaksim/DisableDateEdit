#include <QEvent>
#include <QCheckBox>
#include <QLineEdit>
#include "moddateedit.h"
#include <QDebug>

ModDateEdit::ModDateEdit(QWidget *parent) : QDateEdit(parent)
{
    checkBox = new QCheckBox(this);
    int topLeft = (sizeHint().height() - checkBox->sizeHint().height()) / 2;
    checkBox->setGeometry(QRect(topLeft, topLeft, 16, 16));
    checkBox->setFixedSize(16, 16);
    checkBox->setChecked(true);
    checkBox->installEventFilter(this);

    int left, top, right, bottom;
    lineEdit()->getTextMargins(&left, &top, &right, &bottom);
    left += checkBox->geometry().right() - lineEdit()->geometry().left();
    lineEdit()->setTextMargins(left, top, right, bottom);

    setMinimumSize(sizeHint().width() + checkBox->width(), sizeHint().height());

    connect(checkBox, SIGNAL(toggled(bool)), this, SLOT(setEnabled(bool)));
}

bool ModDateEdit::eventFilter(QObject *object, QEvent *event)
{
    if(object == checkBox && event->type() == QEvent::MouseButtonPress)
    {
        if(!checkBox->checkState())
        {
            checkBox->setChecked(true);
            return true;
        }
        else
        {
            QPalette paletta = checkBox->palette();
            paletta.setColor(QPalette::Window, Qt::white);
            paletta.setColor(QPalette::Shadow, paletta.shadow().color());
            checkBox->setPalette(paletta);
            return true;
        }
    }
    return false;
}

bool ModDateEdit::isState()
{
    return checkBox->isTristate();
}

void ModDateEdit::showEvent(QShowEvent *event)
{
    resize(sizeHint().width() + checkBox->width(), sizeHint().height());
}
