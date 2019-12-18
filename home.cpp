#include "home.h"
#include "ui_home.h"


Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    setWindowTitle(tr("Utility Master"));
    setStyleSheet("background-image: url(resources/images/Utilities.png);");
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

void Home::on_calculator_clicked()
{
    calculator = new Calculator(this);
    calculator->show();
}

void Home::on_wordpad_clicked()
{
    wordpad = new WordPad(this);
    wordpad->show();
}

void Home::on_mediaplayer_clicked()
{
    mediaplayer = new MediaPlayer(this);
    mediaplayer->show();
}


void Home::on_paint_clicked()
{
    paint = new Paint();
    paint->show();
}
