#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QWidget>
#include <QString>

namespace Ui {
class childwindow;
}

class childwindow : public QWidget
{
    Q_OBJECT

public:
    explicit childwindow(QWidget *parent = 0, QString *filename = new QString);
    ~childwindow();

private:
    Ui::childwindow *ui;
};

#endif // CHILDWINDOW_H
