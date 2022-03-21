#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "QString"
#include "QMessageBox"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString uname = "madhu";
    QString pswd = "madhu";
    if(ui->lineEdit__pswd->text() == pswd && ui->lineEdit_uname->text()==uname){
    MainWindow *w=new MainWindow;
    this->close();
    w->show();
    }
    else
    {

       QMessageBox::information(this, "Login failed", "Username or Password is wrong, Please try again");
}
}

