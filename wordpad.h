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

protected:
    // Function used to close an event
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionFont_Style_triggered();

    void on_actionFont_Color_triggered();

    void on_actionBackground_Color_triggered();

    void on_actionCenter_triggered();

    void on_actionRight_triggered();

    void on_actionLEft_triggered();

    void on_actionUnderline_triggered();

    void on_actionAbout_This_triggered();

private:
    Ui::WordPad *ui;
    QString file_path_;
};

#endif // WORDPAD_H
