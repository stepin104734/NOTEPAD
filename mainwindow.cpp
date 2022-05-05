#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QDebug"
#include "QMessageBox"
#include "dialog.h"

QString current_file_path="";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit_Notepad);
     this->setWindowTitle("Notepad-Madhu");
    this->showMaximized();
    this->statusBar()->addWidget(ui->m_fontSize);
    ui->m_fontSize->setValue( ui->textEdit_Notepad->fontInfo().pointSize());
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
   if(!(ui->textEdit_Notepad->toPlainText()== ""))
   {
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Open File", "Current file going to save and close, You want to open new file?");
    if(reply == QMessageBox::Yes)
    {
    this->on_actionSave_triggered();
    }
    else
        return;
   }
    ui->textEdit_Notepad->clear();
    QString file_open_path=QFileDialog::getOpenFileName();
    QFile file_open(file_open_path);
    current_file_path = file_open_path;
    file_open.open(QFile::ReadWrite);
    QTextStream in(&file_open);
    ui->textEdit_Notepad->insertPlainText(in.readAll());
    file_open.close();
}


void MainWindow::on_actionSave_triggered()
{
    if(!(current_file_path == ""))
    {
    QFile current_file(current_file_path);
    QTextStream out(&current_file);
    current_file.open(QFile::ReadWrite);
    current_file.resize(0);
    out<<ui->textEdit_Notepad->toPlainText();
    // qDebug()<<ui->textEdit_Notepad->toPlainText();
    current_file.close();
    QMessageBox::information(this, "Save File", "File saved successfully");
    }
    else
    qDebug()<<"NOT";
    }



void MainWindow::on_actionSave_As_triggered()
{
    QString temp = ui->textEdit_Notepad->toPlainText();
    this->on_actionNew_triggered();
    QFile save_as(current_file_path);
    save_as.open(QFile::ReadWrite);
    QTextStream out(&save_as);
    ui->textEdit_Notepad->setText(temp);
    out<<ui->textEdit_Notepad->toPlainText();
    save_as.close();

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
    this->on_actionSave_triggered();
    QString new_file_path = QFileDialog::getSaveFileName(this, "New File", "Select File name");
    current_file_path = new_file_path;
    ui->textEdit_Notepad->clear();


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


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    qDebug()<< font.family();
    qDebug()<<ok;
    ui->textEdit_Notepad->setFont(font);
}


void MainWindow::on_actionColor_triggered()
{
    QColor color;
    color = QColorDialog::getColor();
    ui->textEdit_Notepad->setTextColor(color);
}

