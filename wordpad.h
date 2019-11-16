#ifndef WORDPAD_H
#define WORDPAD_H

#include <QMainWindow>

namespace Ui {
class WordPad;
}

class WordPad : public QMainWindow
{
    Q_OBJECT

public:
    explicit WordPad(QWidget *parent = nullptr);
    ~WordPad();

private:
    Ui::WordPad *ui;
};

#endif // WORDPAD_H
