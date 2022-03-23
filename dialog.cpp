#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "QString"
#include "QMessageBox"

static int attempt=0;
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
QString uname = "madhu";
void Dialog::on_pushButton_clicked()
{
    if(attempt<3)
    {
    QString pswd = "madhu";
    if(ui->lineEdit__pswd->text() == pswd && ui->lineEdit_uname->text()==uname){
    MainWindow *w=new MainWindow;
    this->close();
    w->show();
    }
    else
    {

       QMessageBox::warning(this, "Login failed", "Username or Password is wrong, Please try again");
       attempt++;
    }
    }
    else{
    ui->pushButton->setDisabled(1);
    }
}

