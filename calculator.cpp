#include "calculator.h"
#include "ui_calculator.h"

double calcValue = 0.0;
bool divTrigger = false;
bool mulTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    setWindowTitle(tr("Calculator Master"));

    ui->Display->setText(QString::number(calcValue));
    QPushButton *numButtons[10];
    for(int i =0; i <10; i++){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

        connect(ui->ButtonAdd, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
        connect(ui->ButtonSub, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
        connect(ui->ButtonMul, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
        connect(ui->ButtonDiv, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
        connect(ui->ButtonEqu, SIGNAL(released()), this,
                SLOT(EqualButtonPressed()));
        connect(ui->ButtonCh, SIGNAL(released()), this,
                SLOT(ChangeNumberSign()));
        connect(ui->ButtonCle, SIGNAL(released()), this,
                SLOT(ClearPressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->Display->setText(butVal);
    }

    else{
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void Calculator::MathButtonPressed(){
    divTrigger =false;
    mulTrigger =false;
    addTrigger =false;
    subTrigger =false;
    QString displayVal = ui->Display->text();
    calcValue = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal , "/", Qt::CaseSensitive) == 0){
        divTrigger = true;
    }
    else if(QString::compare(butVal , "X", Qt::CaseSensitive) == 0){
        mulTrigger = true;
    }
    else if(QString::compare(butVal , "+", Qt::CaseSensitive) == 0){
        addTrigger = true;
    }
    else{
        subTrigger = true;
    }

    ui->Display->setText("");

}

void Calculator::EqualButtonPressed(){
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(addTrigger || subTrigger || mulTrigger || divTrigger){
        if(addTrigger){
            solution = calcValue + dblDisplayVal;

        }
        else if(subTrigger){
            solution = calcValue - dblDisplayVal;

        }
        else if(mulTrigger){
            solution = calcValue * dblDisplayVal;

        }
        else{
            solution = calcValue / dblDisplayVal;
        }

    }

    ui->Display->setText(QString::number(solution));
}

void Calculator::ChangeNumberSign(){
    QString displayVal = ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal =  displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;
        ui->Display->setText(QString::number(dblDisplayValSign));
    }
}

void Calculator::ClearPressed()
{
//    ui->Display->setText("");
    currentFile.clear();
    ui->Display->setText(QString());
}

