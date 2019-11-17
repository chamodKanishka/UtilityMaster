#include "mediaplayer.h"
#include "ui_mediaplayer.h"

MediaPlayer::MediaPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MediaPlayer)
{
    ui->setupUi(this);
    setWindowTitle(tr("Mediaplayer Master"));
}

MediaPlayer::~MediaPlayer()
{
    delete ui;
}
