#include "kalkulacka.h"
#include "ui_kalkulacka.h"

Kalkulacka::Kalkulacka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kalkulacka)
{
    ui->setupUi(this);
}

Kalkulacka::~Kalkulacka()
{
    delete ui;
}
