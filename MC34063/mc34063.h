#ifndef MC34063_H
#define MC34063_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QScrollArea>
#include <QString>
#include <QLocale>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class mc34063; }
QT_END_NAMESPACE

class mc34063 : public QMainWindow
{
    Q_OBJECT

public:
    mc34063(QWidget *parent = nullptr);
    ~mc34063();

private slots:

    void on_pushButton_Calc_clicked();

    void on_actionStep_Up_triggered();

    void on_actionStep_Down_triggered();

    void on_actionInverting_triggered();

    void on_action_Exit_triggered();

    void on_doubleSpinBox_Vin_valueChanged(double arg1);

    void on_doubleSpinBox_Vout_valueChanged(double arg1);

    void on_doubleSpinBox_Iout_valueChanged(double arg1);

    void on_doubleSpinBox_R1_valueChanged(double arg1);

    void on_doubleSpinBox_fmin_valueChanged(double arg1);

    void on_doubleSpinBox_Vripple_valueChanged(double arg1);

    void on_doubleSpinBox_Vsat_valueChanged(double arg1);

    void on_doubleSpinBox_VF_valueChanged(double arg1);

    void VF_Value(double i);

    void Vsat_Value(double i);

    void Vin_Value(double i);

    void Vout_Value(double i);

    void on_checkBox_result_clicked(bool checked);

    void on_checkBox_clicked(bool checked);

    void on_dial_Vin_valueChanged(int value);

    void on_dial_Vout_valueChanged(int value);

    void on_dial_Iout_valueChanged(int value);

    void on_dial_R1_valueChanged(int value);

    void on_dial_fmin_valueChanged(int value);

    void on_dial_Vripple_valueChanged(int value);

    void on_dial_Vsat_valueChanged(int value);

    void on_dial_VF_valueChanged(int value);

private:
    Ui::mc34063 *ui;
};
#endif // MC34063_H
