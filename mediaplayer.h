#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMainWindow>

namespace Ui {
class MediaPlayer;
}

class MediaPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

private:
    Ui::MediaPlayer *ui;
};

#endif // MEDIAPLAYER_H
