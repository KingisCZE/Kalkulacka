#ifndef KALKULACKA_H
#define KALKULACKA_H

#include <QMainWindow>

namespace Ui {
class Kalkulacka;
}

class Kalkulacka : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kalkulacka(QWidget *parent = 0);
    ~Kalkulacka();

private:
    Ui::Kalkulacka *ui;
};

#endif // KALKULACKA_H
