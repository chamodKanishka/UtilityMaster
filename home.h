#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include "notepad.h"
#include "paint.h"
#include "wordpad.h"
#include "calculator.h"

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

private:
    Ui::Home *ui;
    Notepad *notepad;
    Paint *paint();
    Calculator *calculator;

};

#endif // HOME_H
