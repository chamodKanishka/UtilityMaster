#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QPrinter>
#include "notepad.h"

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

private:
    Ui::Home *ui;
    Notepad *notepad;
};

#endif // HOME_H
