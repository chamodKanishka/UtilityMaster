#include "wordpad.h"
#include "ui_wordpad.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
//#include <QPrinter>
//#include <QPrintDialog>
#include <QCloseEvent>

WordPad::WordPad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordPad)
{
    ui->setupUi(this);
}

WordPad::~WordPad()
{
    delete ui;
}

void WordPad::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
      QFile file(file_name);
      file_path_ = file_name;
      if(!file.open(QFile::ReadOnly | QFile::Text)) {
          QMessageBox::warning(this,"..","File Not Open !!");
          return;
        }
      QTextStream in(&file);
      QString text = in.readAll();
      ui->textEdit->setText(text);
      file.close();
}

//Create New File Function
void WordPad::on_actionNew_triggered()
{
    if(QMessageBox::question(this,"Confirm","Do you want to save this file ?")==QMessageBox::Yes){
        QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
          QFile file(file_name);
          file_path_ = file_name;
          if(!file.open(QFile::WriteOnly | QFile::Text)) {
              QMessageBox::warning(this,"..","Error Occured !!");
              return;
            }
          QTextStream out(&file);
          QString text = ui->textEdit->toPlainText();
          out << text;
          file.flush();
          file.close();

            file_path_ = "";
            ui->textEdit->setText("");
    }else{

        file_path_ = "";
        ui->textEdit->setText("");

    }

}

//Save Function
void WordPad::on_actionSave_triggered()
{
    QFile file(file_path_);
     if(!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this,"..","File Not Save !!");
         return;
       }
     QTextStream out(&file);
     QString text = ui->textEdit->toPlainText();
     out << text;
     file.flush();
     file.close();
}

//Save As Function
void WordPad::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
      QFile file(file_name);
      file_path_ = file_name;
      if(!file.open(QFile::WriteOnly | QFile::Text)) {
          QMessageBox::warning(this,"..","Error Occured !!");
          return;
        }
      QTextStream out(&file);
      QString text = ui->textEdit->toPlainText();
      out << text;
      file.flush();
      file.close();
}

//Print Document Function
void WordPad::on_actionPrint_triggered()
{
//    QPrinter printer;
//    printer.setPrinterName("Printer Name");

//    QPrintDialog pDialog(&printer, this);

//    if(pDialog.exec() == QDialog::Rejected){
//        QMessageBox::warning(this, "Warning", "Printer is not connected !");
//        return;
//    }

//    ui->textEdit->print(&printer);
}

//Text Cut Function
void WordPad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

//Text Copy Function
void WordPad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

//Text Paste Function
void WordPad::on_actionPaste_triggered()
{
        ui->textEdit->paste();
}

//Redo Function
void WordPad::on_actionRedo_triggered()
{
        ui->textEdit->redo();
}

//Undo Function
void WordPad::on_actionUndo_triggered()
{
        ui->textEdit->undo();
}

//Font Style Change Function
void WordPad::on_actionFont_Style_triggered()
{
    bool ok;
      QFont font = QFontDialog::getFont(&ok, this);
      if (ok) {
          ui->textEdit->setFont(font);
        } else return;

}

//Font Color Change Function
void WordPad::on_actionFont_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
      if(color.isValid()) {
          ui->textEdit->setTextColor(color);
        }
}

//Font BG Color Change Function
void WordPad::on_actionBackground_color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
      if(color.isValid()) {
          ui->textEdit->setTextBackgroundColor(color);
        }
}

//Text Center
void WordPad::on_actionCenter_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);

}

//Text Right
void WordPad::on_actionRight_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);

}

//Text Left
void WordPad::on_actionLeft_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

//Text Underline
void WordPad::on_actionUnderline_triggered()
{
    if(ui->actionUnderline->isChecked()){
        ui->textEdit->setFontUnderline(true);
    }else{
        ui->textEdit->setFontUnderline(false);
    }
}

//About Application
void WordPad::on_actionAbout_This_triggered()
{
    QString about_text;
      about_text  = "Developer : Chathuranga Nanayakkara\n";
      about_text += "Module   : C++ With QT\n";
      about_text += "University of Plymouth \n";
      about_text += "(C)2019 Wordpad Master \n";

      QMessageBox::about(this,"About Notepad",about_text);
}

// User tried to close the app
void WordPad::closeEvent(QCloseEvent *event)
{
  if(QMessageBox::question(this,"Confirm","Do you want to close this application ?")==QMessageBox::No){
      event->ignore();
  }
}

