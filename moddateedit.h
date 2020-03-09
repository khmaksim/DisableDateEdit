#ifndef MODDATEEDIT_H
#define MODDATEEDIT_H

#include <QDateTimeEdit>

class QCheckBox;
class ModDateEdit : public QDateEdit
{
    Q_OBJECT

    public:
        explicit ModDateEdit(QWidget *parent = 0);

    protected:
        virtual bool eventFilter(QObject *, QEvent *);
        virtual void showEvent(QShowEvent *);

    private:
        QCheckBox *checkBox;
        bool isState();
};

#endif // MODDATEEDIT_H
