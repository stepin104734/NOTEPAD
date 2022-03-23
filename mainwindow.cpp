#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QDebug"
#include "QMessageBox"
#include "dialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit_Notepad);
     this->setWindowTitle("Notepad-Madhu");
    this->showMaximized();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{

}


void MainWindow::on_actionOpen_2_triggered()
{

}


void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_actionSave_As_triggered()
{

}


void MainWindow::on_actionCopy_triggered()
{
        ui->textEdit_Notepad->copy();

//        QMessageBox::warning(this, "Copy Action", "Please select text before copy");


}


void MainWindow::on_actionPase_triggered()
{
   if(!ui->textEdit_Notepad->canPaste())
       QMessageBox::warning(this, "Paste Action", "Paste is empty");
   else
       ui->textEdit_Notepad->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit_Notepad->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit_Notepad->redo();
}


void MainWindow::on_actionAbout_Notepad_triggered()
{
    QMessageBox::about(this, "About", " A Simple notepad application as QT beginner\n Date: 11/03/2022\n Version: 1.0");
}


void MainWindow::on_actionNew_triggered()
{
    QMessageBox::warning(this,"New file is being opened", "Please save file opening new File");
   // QString file_path = getOpenFileName(this);
}


void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quit", "You sure about exiting application?");
    if(reply== QMessageBox::Yes){
        this->close();
    }
}


void MainWindow::on_actionLogout_triggered()
{
    QMessageBox::StandardButton Reply;
    Reply = QMessageBox::question(this, "Logout", "You sure about logging out application?");
    if(Reply == QMessageBox::Yes){
        Dialog *uiagain = new Dialog;
        this->close();
        uiagain->show();
    }


}

