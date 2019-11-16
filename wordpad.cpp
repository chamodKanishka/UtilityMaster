#include "wordpad.h"
#include "ui_wordpad.h"

WordPad::WordPad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordPad)
{
    ui->setupUi(this);
}

WordPad::~WordPad()
{
    delete ui;
}
