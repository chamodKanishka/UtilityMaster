#include "home.h"
#include "ui_home.h"


Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
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
