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

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    int Next_number(int number);

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    double Solve(int typ, int a, int b);

    int Solve_first();

    void on_pushButton_16_clicked();

private:
    Ui::Kalkulacka *ui;
};

#endif // KALKULACKA_H
