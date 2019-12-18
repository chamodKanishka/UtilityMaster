#include "paint.h"
#include "ui_paint.h"
#include "scribblearea.h"

Paint::Paint()
{
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);
    createActions();
    createMenus();
    setWindowTitle(tr("Paint Master"));
    resize(500,500);

}

void Paint::closeEvent(QCloseEvent *event)
{
    if(maybeSave()){
        event->accept();

    }
    else {
        event->ignore();
    }
}

void Paint::open(){
        if(maybeSave()){
            QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),
                                                            QDir::currentPath());
            if(!fileName.isEmpty()){
                scribbleArea->openImage(fileName);
            }
        }

}

void Paint::save(){
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}

void Paint::penColor(){
    QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
    if(newColor.isValid()){
        scribbleArea->setPenColor(newColor);
    }
}

void Paint::penWidth(){
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
            tr("Select pen width: "),
            scribbleArea->penWidth(),
            1, 50, 1, &ok);

    if(ok){
        scribbleArea->setPenWidth(newWidth);
    }
}

void Paint::about(){
    QMessageBox::about(this, tr("About Scribble"),
                       tr("<p>The <b> Scribble</b> example is awsome</p>"));
}

void Paint::createActions(){
    openAct = new QAction(tr("&Open"),this);
    openAct->setShortcut(QKeySequence::Open);
    connect(openAct, SIGNAL(triggred()), this, SLOT(open()));


    foreach(QByteArray format, QImageWriter::supportedImageFormats()){
        QString text = tr("%1...").arg(QString(format).toUpper());
        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(open()));
        saveAsActs.append(action);
    }

        printAct = new QAction(tr("&Print..."), this);
        connect(printAct, SIGNAL(triggered()), scribbleArea, SLOT(print()));


        exitAct = new QAction(tr("&Exit"), this);
        exitAct->setShortcuts(QKeySequence::Quit);
        connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

        penColorAct = new QAction(tr("&Pen Color..."), this);
        connect(penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));
        penWidthAct = new QAction(tr("Pen &Width..."),this);
        connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));

        clearScreenAct = new QAction(tr("&Clear Screen..."), this);
        clearScreenAct->setShortcut(tr("Ctrl+l"));
        connect(clearScreenAct, SIGNAL(triggered()), scribbleArea, SLOT(clearImage()));


        aboutAct = new QAction(tr("&About..."),this);
        connect(aboutAct, SIGNAL(triggered()), SLOT(about()));

        aboutQtAct = new QAction(tr("About &Qt..."),this);
        connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));


}

void Paint::createMenus(){
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach (QAction *action, saveAsActs)
            saveAsMenu->addAction(action);

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);


    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(helpMenu);


}

bool Paint::maybeSave(){
    if(scribbleArea->isModified()){
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Scribble"),
                                   tr("The image has been modified. \n"
                                      "Do you want to save your changes?"),
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if (ret == QMessageBox::Save) {
                    return saveFile("png");

        } else if (ret == QMessageBox::Cancel) {
                    return false;
                }
    }
    return true;
}
bool Paint::openFile(const QByteArray &fileFormat)
{
    // Define path, name and default file type
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    // Get selected file from dialog
    // Add the proper file formats and extensions
    QString fileName = QFileDialog::getOpenFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString::fromLatin1(fileFormat.toUpper()))
                               .arg(QString::fromLatin1(fileFormat)));

    // If no file do nothing
    if (fileName.isEmpty()) {
        return false;
    } else {

        // Call for the file to be saved
        return scribbleArea->saveImage(fileName, fileFormat.constData());
    }
}

bool Paint::saveFile(const QByteArray &fileFormat){
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    initialPath, tr("%1 Files (*.%2);; All Files(*)")
                                                    .arg(QString::fromLatin1(fileFormat.toUpper()))
                                                    .arg(QString::fromLatin1(fileFormat)));
    if(fileName.isEmpty()){
        return false;
    }
    else {
        return scribbleArea->saveImage(fileName, fileFormat.constData());
    }
}
