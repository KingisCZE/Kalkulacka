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

double a; //První číslo výpočtu
double b; //Druhé číslo výpočtu
double c; //Výsledek

QString help1 = ""; //Pomocná proměnná pro výpis prvního čísla
QString help2 = ""; //Pomocná proměnná pro výpis druhého čísla

QString vystup = ""; //Řetězec znaké vypisující se na obrazovku

bool operation_set = false; //True, pokud byl zvolen typ operace
int operation_type; //Typ operace
bool operation_done = false; //True, pokud byla operace kompletně provedena
bool a_set = false; //True, pokud byla nastevena první proměnná výpočtu
bool b_set = false; //True, pokud byla nastevena druhá proměnná výpočtu

bool a_mod = false; //True, pokud byla první proměnná výpočtu nastavena jako záporná
bool b_mod = false; //True, pokud byla druhá proměnná výpočtu nastavena jako záporná

bool error = false; //True, pokud se ve výpočtu vyskytlo dělení nulou

bool ans_exists = false; //True, pokud je nastavena proměnná ans
double ans;

int Kalkulacka::Next_number(int number) //Funkce registrující vstup dalšího čísla
{
    if (!operation_done) {
        if (!operation_set) {
            help1 += QString::number(number);
            a = help1.toDouble();
            a_set = true;
        } else {
            help2 += QString::number(number);
            b = help2.toDouble();
            b_set = true;
        }
        vystup += QString::number(number);
        ui->vystup->setText(vystup);
    } else {
        Kalkulacka::on_pushButton_10_clicked();
        Kalkulacka::Next_number(number);
    }
    return 0;
}

double Kalkulacka::Solve(int typ, int a, int b) //Výpočetní funkce
{
    double c;
    switch (typ) {
    case 1:
        c = a + b;
        break;
    case 2:
        c = a - b;
        break;
    case 3:
        c = a * b;
        break;
    case 4:
        if (b != 0) {
            c = a / b;
        } else {
            error = true;
        }
        break;
    default:
        break;
    }
    return c;
}

int Kalkulacka::Solve_first()
{
    a = Kalkulacka::Solve(operation_type, a, b);
    help1 = QString::number(a);
    operation_set = false;
    help2 = "";
    b = 0;
    b_set = false;
    b_mod = false;
    operation_type = 0;
    return 0;
}

void Kalkulacka::on_pushButton_10_clicked() //Destructor všech proměnných po dokončení výpočtu
{
    help1 = "";
    help2 = "";
    vystup = "";
    a = 0;
    b = 0;
    c = 0;
    a_mod = false;
    b_mod = false;
    operation_set = false;
    operation_type = 0;
    operation_done = false;
    a_set = false;
    b_set = false;
    error = false;
    ui->vystup->setText(vystup);
}

void Kalkulacka::on_pushButton_1_clicked()
{
    Next_number(1);
}

void Kalkulacka::on_pushButton_2_clicked()
{
    Next_number(2);
}

void Kalkulacka::on_pushButton_3_clicked()
{
    Next_number(3);
}

void Kalkulacka::on_pushButton_4_clicked()
{
    Next_number(4);
}

void Kalkulacka::on_pushButton_5_clicked()
{
    Next_number(5);
}

void Kalkulacka::on_pushButton_6_clicked()
{
    Next_number(6);
}

void Kalkulacka::on_pushButton_7_clicked()
{
    Next_number(7);
}

void Kalkulacka::on_pushButton_8_clicked()
{
    Next_number(8);
}

void Kalkulacka::on_pushButton_9_clicked()
{
    Next_number(9);
}

void Kalkulacka::on_pushButton_11_clicked()
{
    Next_number(0);
}

void Kalkulacka::on_pushButton_clicked() //Nastaví typ operace na sčítání
{
    if (!operation_set and a_set) {
        operation_set = true;
        operation_type = 1;
        vystup += " + ";
        ui->vystup->setText(vystup);
    } else if (b_set and !operation_done) {
        if (b_mod) {
            vystup += ")";
        }
        Kalkulacka::Solve_first();
        Kalkulacka::on_pushButton_clicked();
    }
}

void Kalkulacka::on_pushButton_13_clicked() //Nastaví typ operace na odčítání, případně nastaví proměnné znaménko zápornosti
{
    if (!operation_set) {
        if (a_set) {
            operation_set = true;
            operation_type = 2;
            vystup += " - ";
            ui->vystup->setText(vystup);
        } else {
            if (!a_mod) {
                help1 += "-";
                a_mod = true;
                vystup += "-";
                ui->vystup->setText(vystup);
            }
        }
    } else {
        if (!b_set and !b_mod) {
            help2 += "-";
            b_mod = true;
            vystup += "(-";
            ui->vystup->setText(vystup);
        } else if (operation_done) {
            Kalkulacka::on_pushButton_10_clicked();
            Kalkulacka::on_pushButton_16_clicked();
            Kalkulacka::on_pushButton_13_clicked();
        } else if (b_set) {
            if (b_mod) {
                vystup += ")";
            }
            Kalkulacka::Solve_first();
            Kalkulacka::on_pushButton_13_clicked();
        }
    }
}

void Kalkulacka::on_pushButton_12_clicked() //Vyhodnocení úlohy
{
    if (!operation_done and operation_set and a_set and b_set) {

        c = Kalkulacka::Solve(operation_type, a, b);

        if (!error) {
            if (!b_mod) {
                vystup += " = " + QString::number(c);
                ui->vystup->setText(vystup);
                operation_done = true;
            } else {
                vystup += ") = " + QString::number(c);
                ui->vystup->setText(vystup);
                operation_done = true;
            }
            ans = c;
            ans_exists = true;
        } else {
            vystup += " = " + QString::fromUtf8("ERROR");
            ui->vystup->setText(vystup);
            operation_done = true;
        }
    }
}

void Kalkulacka::on_pushButton_14_clicked() //Nastaví typ operace na násobení
{
    if (!operation_set and a_set) {
        operation_set = true;
        operation_type = 3;
        if (a_mod) {
            vystup = "(" + vystup + ")";
        }
        vystup += " * ";
        ui->vystup->setText(vystup);
    } else if (b_set and !operation_done) {
        if (b_mod) {
            vystup += ")";
        }
        if (operation_type == 1 or operation_type == 2) {
            vystup = "(" + vystup + ")";
        }
        Kalkulacka::Solve_first();
        Kalkulacka::on_pushButton_14_clicked();
    }
}

void Kalkulacka::on_pushButton_15_clicked() //Nastaví typ operace na dělení
{
    if (!operation_set and a_set) {
        operation_set = true;
        operation_type = 4;
        if (a_mod) {
            vystup = "(" + vystup + ")";
        }
        vystup += " / ";
        ui->vystup->setText(vystup);
    } else if (b_set and !operation_done) {
        if (b_mod) {
            vystup += ")";
        }
        if (operation_type == 1 or operation_type == 2) {
            vystup = "(" + vystup + ")";
        }
        Kalkulacka::Solve_first();
        Kalkulacka::on_pushButton_15_clicked();
    }
}

void Kalkulacka::on_pushButton_16_clicked()
{
    if (ans_exists) {
        if (ans < 0) {
            vystup += "(";
            Next_number(ans);
            vystup += ")";
        } else {
            Next_number(ans);
        }
    }
}
