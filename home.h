#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include "notepad.h"
#include "paint.h"
#include "wordpad.h"
#include "calculator.h"
#include "mediaplayer.h"

namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_notepad_clicked();

    void on_paint_clicked();

    void on_calculator_clicked();

    void on_wordpad_clicked();

    void on_mediaplayer_clicked();

private:
    Ui::Home *ui;
    Notepad *notepad;
    Calculator *calculator;
    WordPad *wordpad;
    MediaPlayer *mediaplayer;
    Paint *paint;

};

#endif // HOME_H
