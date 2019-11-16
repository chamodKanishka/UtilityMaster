#include "home.h"
#include "ui_home.h"


Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    setWindowTitle(tr("Utility Master"));
}

Home::~Home()
{
    delete ui;
}

void Home::on_notepad_clicked()
{
    notepad = new Notepad(this);
    notepad->show();

}
void Home::on_paint_clicked()
{

}

void Home::on_calculator_clicked()
{
    calculator = new Calculator(this);
    calculator->show();
}
