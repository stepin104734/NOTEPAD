#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string"
#include "QDebug"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit_Notepad);

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
    QMessageBox::information(this, "About", "A Simple notepad application as QT beginner");
}

