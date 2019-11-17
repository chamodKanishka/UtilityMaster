#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

namespace Ui {
class MediaPlayer;
}

class MediaPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

protected:
    // Function used to close an event
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

private:
    Ui::MediaPlayer *ui;
    QMediaPlayer *player;
    QVideoWidget *vw;
    QProgressBar *bar;
    QSlider *slider;
};

#endif // MEDIAPLAYER_H
