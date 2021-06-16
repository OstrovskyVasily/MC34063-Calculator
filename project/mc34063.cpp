#include "mc34063.h"
#include "ui_mc34063.h"
#include <QtMath>

mc34063::mc34063(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mc34063)
{
    ui->setupUi(this);

    on_actionStep_Up_triggered();

    on_checkBox_clicked(false);
    on_checkBox_result_clicked(false);

    ui->scrollArea_info->setVisible(false);

    QIcon winIcon(":/res/MC34063.ico");
    this->setWindowIcon(winIcon);
}

mc34063::~mc34063()
{
    delete ui;
}


void mc34063::on_pushButton_Calc_clicked()
{
    double Vin = ui->doubleSpinBox_Vin->value(); //V
    double Vout = ui->doubleSpinBox_Vout->value();
    double Iout = ui->doubleSpinBox_Iout->value() * qPow(10, -3); //mA
    double R1 = ui->doubleSpinBox_R1->value() * qPow(10, 3); //kOhm
    double VF = ui->doubleSpinBox_VF->value(); //V
    double Vsat = ui->doubleSpinBox_Vsat->value(); //V
    double Vripple = ui->doubleSpinBox_Vripple->value()* qPow(10, -3); //mV
    double fmin = ui->doubleSpinBox_fmin->value()* qPow(10, 3); //kHz
    double ton_del_toff;
    double ton_plus_toff;
    double ton;
    double toff;
    double CT;
    double Ipk;
    double Rsc;
    double Lmin;
    double C0;
    double R2;


    if(ui->actionStep_Up->isChecked())
    {

        ton_del_toff = (Vout + VF - Vin) / (Vin - Vsat);

        ton_plus_toff = 1 / fmin;

        toff = ton_plus_toff / (ton_del_toff + 1);

        ton = ton_plus_toff - toff;

        CT = 4.0 * qPow(10, -5) * ton;

        Ipk = 2 * Iout * (ton_del_toff + 1);

        Rsc = 0.3 * Ipk;

        Lmin = ((Vin - Vsat) / Ipk) * ton;

        C0 = (9 * Iout * ton) / Vripple;

        R2 = ((qAbs(Vout) / 1.25) - 1) * R1;

        ui->label_result_ton_del_toff->setText(QString::number(floor(ton_del_toff * 100)/100));
        ui->label_result_ton_plus_toff->setText(QString::number(floor(ton_plus_toff * qPow(10, 8))/100)); //us
        ui->label_result_toff->setText(QString::number(floor(toff* qPow(10, 8))/100)); //us
        ui->label_result_ton->setText(QString::number(floor(ton * qPow(10, 8))/100)); //us
        ui->label_result_Ipk->setText(QString::number(floor(Ipk * qPow(10, 5))/100)); //mA
        ui->label_result_CT->setText(QString::number(floor(CT* qPow(10, 14))/100)); //pF
        ui->label_result_C0->setText(QString::number(floor(C0* qPow(10, 8))/100)); //uF
        ui->label_result_Rsc->setText(QString::number(floor(Rsc*1000)/1000)); //Ohm
        ui->label_result_Lmin->setText(QString::number(floor(Lmin * qPow(10, 8))/100)); //uH
        ui->label_result_R2->setText(QString::number(floor(R2* qPow(10, -1))/100)); //kOhm

    }

    if(ui->actionStep_Down->isChecked())
    {

        ton_del_toff = (Vout + VF) / (Vin - Vsat- Vout);

        ton_plus_toff = 1 / fmin;

        toff = ton_plus_toff / (ton_del_toff + 1);

        ton = ton_plus_toff - toff;

        CT = 4.0 * qPow(10, -5) * ton;

        Ipk = 2 * Iout;

        Rsc = 0.3 * Ipk;

        Lmin = ((Vin - Vsat - Vout) / Ipk) * ton;

        C0 = (Ipk * ton_plus_toff) / (Vripple * 8);

        R2 = ((qAbs(Vout) / 1.25) - 1) * R1;

        ui->label_result_ton_del_toff->setText(QString::number(floor(ton_del_toff * 100)/100));
        ui->label_result_ton_plus_toff->setText(QString::number(floor(ton_plus_toff * qPow(10, 8))/100)); //us
        ui->label_result_toff->setText(QString::number(floor(toff* qPow(10, 8))/100)); //us
        ui->label_result_ton->setText(QString::number(floor(ton * qPow(10, 8))/100)); //us
        ui->label_result_Ipk->setText(QString::number(floor(Ipk * qPow(10, 5))/100)); //mA
        ui->label_result_CT->setText(QString::number(floor(CT* qPow(10, 14))/100)); //pF
        ui->label_result_C0->setText(QString::number(floor(C0* qPow(10, 8))/100)); //uF
        ui->label_result_Rsc->setText(QString::number(floor(Rsc*1000)/1000)); //Ohm
        ui->label_result_Lmin->setText(QString::number(floor(Lmin * qPow(10, 8))/100)); //uH
        ui->label_result_R2->setText(QString::number(floor(R2* qPow(10, -1))/100)); //kOhm
    }

    if(ui->actionInverting->isChecked())
    {

        ton_del_toff = (qAbs(Vout) + VF) / (Vin - Vsat);

        ton_plus_toff = 1 / fmin;

        toff = ton_plus_toff / (ton_del_toff + 1);

        ton = ton_plus_toff - toff;

        CT = 4.0 * qPow(10, -5) * ton;

        Ipk = 2 * Iout * (ton_del_toff + 1);

        Rsc = 0.3 * Ipk;

        Lmin = ((Vin - Vsat) / Ipk) * ton;

        C0 = (9 * Iout * ton) / Vripple;

        R2 = ((qAbs(Vout) / 1.25) - 1) * R1;

        ui->label_result_ton_del_toff->setText(QString::number(floor(ton_del_toff * 100)/100));
        ui->label_result_ton_plus_toff->setText(QString::number(floor(ton_plus_toff * qPow(10, 8))/100)); //us
        ui->label_result_toff->setText(QString::number(floor(toff* qPow(10, 8))/100)); //us
        ui->label_result_ton->setText(QString::number(floor(ton * qPow(10, 8))/100)); //us
        ui->label_result_Ipk->setText(QString::number(floor(Ipk * qPow(10, 5))/100)); //mA
        ui->label_result_CT->setText(QString::number(floor(CT* qPow(10, 14))/100)); //pF
        ui->label_result_C0->setText(QString::number(floor(C0* qPow(10, 8))/100)); //uF
        ui->label_result_Rsc->setText(QString::number(floor(Rsc*1000)/1000)); //Ohm
        ui->label_result_Lmin->setText(QString::number(floor(Lmin * qPow(10, 8))/100)); //uH
        ui->label_result_R2->setText(QString::number(floor(R2* qPow(10, -1))/100)); //kOhm
    }

}

void mc34063::on_actionStep_Up_triggered()
{

    ui->label_shema->setPixmap(QPixmap(":/res/img/StepUp.png"));
    ui->label_shema->setScaledContents(true);
    ui->label_Name->setText("Step-Up");

    ui->doubleSpinBox_Vin->setValue(4);
    ui->dial_Vin->setValue(4);
    ui->doubleSpinBox_Vout->setMinimum(4);
    ui->doubleSpinBox_Vout->setMaximum(40);
    ui->doubleSpinBox_Vout->setValue(12);
    ui->dial_Vout->setMinimum(4);
    ui->dial_Vout->setMaximum(40);
    ui->dial_Vout->setValue(12);
    ui->doubleSpinBox_Vripple->setMaximum(6000);
    ui->dial_Vripple->setMaximum(600);
    ui->doubleSpinBox_Vripple->setValue(100);
    ui->dial_Vripple->setValue(10);
    ui->doubleSpinBox_Iout->setMaximum(216);
    ui->doubleSpinBox_Iout->setValue(216);
    ui->dial_Iout->setMaximum(216);
    ui->dial_Iout->setValue(216);

    ui->doubleSpinBox_Vsat->setMaximum(1.3);
    ui->dial_Vsat->setMaximum(130);

    ui->label_formula_ton_del_toff->setPixmap(QPixmap(":/res/img/ton_del_toff_Up.PNG"));
    ui->label_formula_ton_plus_toff->setPixmap(QPixmap(":/res/img/ton_plus_toff.PNG"));
    ui->label_formula_toff->setPixmap(QPixmap(":/res/img/toff.PNG"));
    ui->label_formula_ton->setPixmap(QPixmap(":/res/img/ton.PNG"));
    ui->label_formula_CT->setPixmap(QPixmap(":/res/img/CT.PNG"));
    ui->label_formula_Ipk->setPixmap(QPixmap(":/res/img/Ipk_Up_inv.PNG"));
    ui->label_formula_Rsc->setPixmap(QPixmap(":/res/img/Rsc.PNG"));
    ui->label_formula_Lmin->setPixmap(QPixmap(":/res/img/Lmin_Up_Inv.PNG"));
    ui->label_formula_C0->setPixmap(QPixmap(":/res/img/C0_Up_Inv.PNG"));
    ui->label_formula_R2->setPixmap(QPixmap(":/res/img/R2.PNG"));

    ui->actionStep_Up->setChecked(true);
    ui->actionStep_Down->setChecked(false);
    ui->actionInverting->setChecked(false);

    on_pushButton_Calc_clicked();
}

void mc34063::on_actionStep_Down_triggered()
{
    ui->label_shema->setPixmap(QPixmap(":/res/img/StepDown.png"));
    ui->label_shema->setScaledContents(true);
    ui->label_Name->setText("Step-Down");

    ui->doubleSpinBox_Vin->setValue(12);
    ui->dial_Vin->setValue(12);
    ui->doubleSpinBox_Vout->setMinimum(0);
    ui->doubleSpinBox_Vout->setMaximum(12);
    ui->doubleSpinBox_Vout->setValue(4);
    ui->dial_Vout->setMinimum(0);
    ui->dial_Vout->setMaximum(12);
    ui->dial_Vout->setValue(4);
    ui->doubleSpinBox_Vripple->setMaximum(2000);
    ui->dial_Vripple->setMaximum(200);
    ui->doubleSpinBox_Vripple->setValue(100);
    ui->dial_Vripple->setValue(10);
    ui->doubleSpinBox_Iout->setMaximum(750);
    ui->doubleSpinBox_Iout->setValue(750);
    ui->dial_Iout->setMaximum(750);
    ui->dial_Iout->setValue(750);

    ui->doubleSpinBox_Vsat->setMaximum(0.7);
    ui->dial_Vsat->setMaximum(70);

    ui->label_formula_ton_del_toff->setPixmap(QPixmap(":/res/img/ton_del_toff_Down.PNG"));
    ui->label_formula_ton_plus_toff->setPixmap(QPixmap(":/res/img/ton_plus_toff.PNG"));
    ui->label_formula_toff->setPixmap(QPixmap(":/res/img/toff.PNG"));
    ui->label_formula_ton->setPixmap(QPixmap(":/res/img/ton.PNG"));
    ui->label_formula_CT->setPixmap(QPixmap(":/res/img/CT.PNG"));
    ui->label_formula_Ipk->setPixmap(QPixmap(":/res/img/Ipk_Down.PNG"));
    ui->label_formula_Rsc->setPixmap(QPixmap(":/res/img/Rsc.PNG"));
    ui->label_formula_Lmin->setPixmap(QPixmap(":/res/img/C0_Down.PNG"));
    ui->label_formula_C0->setPixmap(QPixmap(":/res/img/Lmin_Down.PNG"));
    ui->label_formula_R2->setPixmap(QPixmap(":/res/img/R2.PNG"));

    ui->actionStep_Up->setChecked(false);
    ui->actionStep_Down->setChecked(true);
    ui->actionInverting->setChecked(false);

    on_pushButton_Calc_clicked();
}

void mc34063::on_actionInverting_triggered()
{
    ui->label_shema->setPixmap(QPixmap(":/res/img/Inverting.png"));
    ui->label_shema->setScaledContents(true);
    ui->label_Name->setText("Voltage-Inverting");

    ui->doubleSpinBox_Vin->setValue(4);
    ui->dial_Vin->setValue(4);
    ui->doubleSpinBox_Vout->setMinimum(-40);
    ui->doubleSpinBox_Vout->setMaximum(0);
    ui->doubleSpinBox_Vout->setValue(-12);
    ui->dial_Vout->setMinimum(-40);
    ui->dial_Vout->setMaximum(0);
    ui->dial_Vout->setValue(-12);
    ui->doubleSpinBox_Vripple->setMaximum(6000);
    ui->dial_Vripple->setMaximum(600);
    ui->doubleSpinBox_Vripple->setValue(100);
    ui->dial_Vripple->setValue(10);
    ui->doubleSpinBox_Iout->setMaximum(163);
    ui->doubleSpinBox_Iout->setValue(163);
    ui->dial_Iout->setMaximum(163);
    ui->dial_Iout->setValue(163);
    ui->doubleSpinBox_Vsat->setMaximum(0.7);
    ui->dial_Vsat->setMaximum(70);

    ui->label_formula_ton_del_toff->setPixmap(QPixmap(":/res/img/ton_del_toff_Inv.PNG"));
    ui->label_formula_ton_plus_toff->setPixmap(QPixmap(":/res/img/ton_plus_toff.PNG"));
    ui->label_formula_toff->setPixmap(QPixmap(":/res/img/toff.PNG"));
    ui->label_formula_ton->setPixmap(QPixmap(":/res/img/ton.PNG"));
    ui->label_formula_CT->setPixmap(QPixmap(":/res/img/CT.PNG"));
    ui->label_formula_Ipk->setPixmap(QPixmap(":/res/img/Ipk_Up_inv.PNG"));
    ui->label_formula_Rsc->setPixmap(QPixmap(":/res/img/Rsc.PNG"));
    ui->label_formula_Lmin->setPixmap(QPixmap(":/res/img/Lmin_Up_Inv.PNG"));
    ui->label_formula_C0->setPixmap(QPixmap(":/res/img/C0_Up_Inv.PNG"));
    ui->label_formula_R2->setPixmap(QPixmap(":/res/img/R2.PNG"));

    ui->actionStep_Up->setChecked(false);
    ui->actionStep_Down->setChecked(false);
    ui->actionInverting->setChecked(true);

    on_pushButton_Calc_clicked();
}

void mc34063::on_action_Exit_triggered()
{
    QApplication::exit();
}


// ---------------- Vin --------------------------------------
void mc34063::on_doubleSpinBox_Vin_valueChanged(double arg1)
{
    ui->dial_Vin->setValue(arg1);
    Vin_Value(arg1);
}

void mc34063::on_dial_Vin_valueChanged(int value)
{
    ui->doubleSpinBox_Vin->setValue(value);
    Vin_Value(value);
}

void mc34063::Vin_Value(double i)
{
    double Vsat = ui->doubleSpinBox_Vsat->value();
    double VF = ui->doubleSpinBox_VF->value();
    double Vout = ui->doubleSpinBox_Vout->value();
    double Ioutmax;

    if(ui->actionStep_Up->isChecked())
    {
        ui->doubleSpinBox_Vout->setMinimum(i);
        ui->dial_Vout->setMinimum(i);

        Ioutmax = 750/((Vout + VF - i)/(i - Vsat) + 1);
    }
    if(ui->actionStep_Down->isChecked())
    {
        ui->doubleSpinBox_Vout->setMaximum(i);
        ui->dial_Vout->setMaximum(i);

        Ioutmax = 750;
    }
    if(ui->actionInverting->isChecked())
    {
        Ioutmax = 750/((qAbs(Vout) + VF)/(i - Vsat) + 1);
    }

    ui->doubleSpinBox_Vripple->setMaximum(qAbs(Vout*500));
    ui->dial_Vripple->setMaximum(qAbs(Vout*50));

    ui->doubleSpinBox_Iout->setMaximum(Ioutmax - 1);
    ui->doubleSpinBox_Iout->setValue(Ioutmax - 1);
    ui->dial_Iout->setMaximum(Ioutmax);
    ui->dial_Iout->setValue(Ioutmax);
}
//------------------------------------------------------------


// ---------------- Vout -------------------------------------
void mc34063::on_doubleSpinBox_Vout_valueChanged(double arg1)
{
    ui->dial_Vout->setValue(arg1);
    Vout_Value(arg1);
}

void mc34063::on_dial_Vout_valueChanged(int value)
{
    ui->doubleSpinBox_Vout->setValue(value);
    Vout_Value(value);
}

void mc34063::Vout_Value(double i)
{
    double Vin = ui->doubleSpinBox_Vin->value();
    double VF = ui->doubleSpinBox_VF->value();
    double Vsat = ui->doubleSpinBox_Vsat->value();
    double Ioutmax;

    if(ui->actionStep_Up->isChecked())
    {
        Ioutmax = 750/((i + VF - Vin)/(Vin - Vsat) + 1);
    }
    if(ui->actionStep_Down->isChecked())
    {
        Ioutmax = 750;
    }
    if(ui->actionInverting->isChecked())
    {
        Ioutmax = 750/((qAbs(i) + VF)/(Vin - Vsat) + 1);
    }

    ui->doubleSpinBox_Vripple->setMaximum(qAbs(i*500));
    ui->dial_Vripple->setMaximum(qAbs(i*50));

    ui->doubleSpinBox_Iout->setMaximum(Ioutmax - 1);
    ui->doubleSpinBox_Iout->setValue(Ioutmax - 1);
    ui->dial_Iout->setMaximum(Ioutmax);
    ui->dial_Iout->setValue(Ioutmax);
}
//------------------------------------------------------------


// ---------------- Iout --------------------------------------
void mc34063::on_doubleSpinBox_Iout_valueChanged(double arg1)
{
    ui->dial_Iout->setValue(arg1);
}

void mc34063::on_dial_Iout_valueChanged(int value)
{
    ui->doubleSpinBox_Iout->setValue(value);
}
//------------------------------------------------------------


// ---------------- R1 -------------------------------------
void mc34063::on_doubleSpinBox_R1_valueChanged(double arg1)
{
    ui->dial_R1->setValue(arg1);
}

void mc34063::on_dial_R1_valueChanged(int value)
{
    ui->doubleSpinBox_R1->setValue(value);
}
//----------------------------------------------------------


// ---------------- fmin -------------------------------------
void mc34063::on_doubleSpinBox_fmin_valueChanged(double arg1)
{
    ui->dial_fmin->setValue(arg1);
}

void mc34063::on_dial_fmin_valueChanged(int value)
{
    ui->doubleSpinBox_fmin->setValue(value);
}
//------------------------------------------------------------


// ---------------- Vripple ----------------------------------
void mc34063::on_doubleSpinBox_Vripple_valueChanged(double arg1)
{
    ui->dial_Vripple->setValue(arg1/10);
}

void mc34063::on_dial_Vripple_valueChanged(int value)
{
    ui->doubleSpinBox_Vripple->setValue(value*10);
}
//------------------------------------------------------------


// ---------------- Vsat -------------------------------------
void mc34063::on_doubleSpinBox_Vsat_valueChanged(double arg1)
{
    ui->dial_Vsat->setValue(arg1*100);
    Vsat_Value(arg1);
}

void mc34063::on_dial_Vsat_valueChanged(int value)
{
    double n = value;
    ui->doubleSpinBox_Vsat->setValue(n/100);
    Vsat_Value(n/100);
}

void mc34063::Vsat_Value(double i)
{
    double Vin = ui->doubleSpinBox_Vin->value();
    double VF = ui->doubleSpinBox_VF->value();
    double Vout = ui->doubleSpinBox_Vout->value();
    double Ioutmax;

    if(ui->actionStep_Up->isChecked())
    {
        Ioutmax = 750/((Vout + VF - Vin)/(Vin - i) + 1);
    }
    if(ui->actionStep_Down->isChecked())
    {
        Ioutmax = 750;
    }
    if(ui->actionInverting->isChecked())
    {
        Ioutmax = 750/((qAbs(Vout) + VF)/(Vin - i) + 1);
    }

    ui->doubleSpinBox_Iout->setMaximum(Ioutmax - 1);
    ui->doubleSpinBox_Iout->setValue(Ioutmax - 1);
    ui->dial_Iout->setMaximum(Ioutmax);
    ui->dial_Iout->setValue(Ioutmax);
}
//------------------------------------------------------------


// ---------------- VF ---------------------------------------
void mc34063::on_doubleSpinBox_VF_valueChanged(double arg1)
{
    ui->dial_VF->setValue(arg1*100);
    VF_Value(arg1);
}

void mc34063::on_dial_VF_valueChanged(int value)
{
    double n = value;
    ui->doubleSpinBox_VF->setValue(n/100);
    Vsat_Value(n/100);
}

void mc34063::VF_Value(double i)
{
    double Vin = ui->doubleSpinBox_Vin->value();
    double Vsat = ui->doubleSpinBox_Vsat->value();
    double Vout = ui->doubleSpinBox_Vout->value();
    double Ioutmax;

    if(ui->actionStep_Up->isChecked())
    {
        Ioutmax = 750/((Vout + i - Vin)/(Vin - Vsat) + 1);
    }
    if(ui->actionStep_Down->isChecked())
    {
        Ioutmax = 750;
    }
    if(ui->actionInverting->isChecked())
    {
        Ioutmax = 750/((qAbs(Vout) + i)/(Vin - Vsat) + 1);
    }

    ui->doubleSpinBox_Iout->setMaximum(Ioutmax - 1);
    ui->doubleSpinBox_Iout->setValue(Ioutmax - 1);
    ui->dial_Iout->setMaximum(Ioutmax);
    ui->dial_Iout->setValue(Ioutmax);
}
//------------------------------------------------------------


void mc34063::on_checkBox_result_clicked(bool checked)
{
    ui->label_name_toff->setVisible(checked);
    ui->label_name_ton->setVisible(checked);
    ui->label_name_ton_del_toff->setVisible(checked);
    ui->label_name_ton_plus_toff->setVisible(checked);

    ui->label_formula_toff->setVisible(checked);
    ui->label_formula_ton->setVisible(checked);
    ui->label_formula_ton_del_toff->setVisible(checked);
    ui->label_formula_ton_plus_toff->setVisible(checked);
    ui->label_formula_C0->setVisible(checked);
    ui->label_formula_CT->setVisible(checked);
    ui->label_formula_Ipk->setVisible(checked);
    ui->label_formula_Lmin->setVisible(checked);
    ui->label_formula_R2->setVisible(checked);
    ui->label_formula_Rsc->setVisible(checked);

    ui->label_result_toff->setVisible(checked);
    ui->label_result_ton->setVisible(checked);
    ui->label_result_ton_del_toff->setVisible(checked);
    ui->label_result_ton_plus_toff->setVisible(checked);

    ui->label_si_toff->setVisible(checked);
    ui->label_si_ton->setVisible(checked);
    ui->label_si_ton_plus_toff->setVisible(checked);
}

void mc34063::on_checkBox_clicked(bool checked)
{
    ui->scrollArea_info->setVisible(checked);
}

