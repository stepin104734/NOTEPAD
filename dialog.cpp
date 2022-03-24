#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "QString"
#include "QMessageBox"
#include "QFile"
#include "QTextStream"
#include "QDebug"

QString uname;
QString pswd;

void init()
{
    QFile login(":/text_files/Resource/login.txt");
    login.open(QFile::ReadOnly);
    QTextStream in(&login);
    uname=in.readLine();
    pswd=in.readLine();
    //qDebug()<<uname;
    login.close();
}
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

void Dialog::on_pushButton_clicked()
{
    init();
    if(attempt<3)
    {
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

