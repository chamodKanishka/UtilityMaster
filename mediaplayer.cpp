#include "mediaplayer.h"
#include "ui_mediaplayer.h"

MediaPlayer::MediaPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MediaPlayer)
{
    ui->setupUi(this);
    setWindowTitle(tr("Mediaplayer Master"));

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);
}

MediaPlayer::~MediaPlayer()
{
    delete ui;
}

void MediaPlayer::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a file","","Video File(*.*)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();

    slider = new QSlider(this);
    bar = new QProgressBar(this);
    slider->setOrientation(Qt::Horizontal);

    ui->statusbar->addPermanentWidget(slider);
    ui->statusbar->addPermanentWidget(bar);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

}

//Play Media
void MediaPlayer::on_actionPlay_triggered()
{
    player->play();
    ui->statusbar->showMessage("Playing..");
}

//Pause Media
void MediaPlayer::on_actionPause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("Paused..");
}

//Stop Media
void MediaPlayer::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stopped..");
}

// User tried to close the app
void MediaPlayer::closeEvent(QCloseEvent *event)
{
      player->stop();
      hide();
}
