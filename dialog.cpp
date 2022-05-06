#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "QString"
#include "QMessageBox"
#include "QFile"
#include "QTextStream"
#include "QDebug"
#include "QTimer"

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
    //ui->statusBar->addWidget(label_loginStatus); // can't add this as Dialog don't have status bar
    ui->label_loginStatus->hide();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    init();
    QTimer *timer = new QTimer(this); //always create it as pointer.
    if(attempt<3)
    {

        if(ui->lineEdit__pswd->text() == pswd && ui->lineEdit_uname->text()==uname){
        MainWindow *w=new MainWindow;
        this->close();
        w->show();
        }
        else
        {
       //QMessageBox::warning(this, "Login failed", "Username or Password is wrong, Please try again");
        ui->label_loginStatus->setStyleSheet("color:black");
        ui->label_loginStatus->setText("Username or password is wrong \t" + QString::number(attempt));ui->label_loginStatus->show();
        attempt++;
        }
    }
    else{
        ui->pushButton->setDisabled(1);
        ui->pushButton->setStyleSheet("color:red");

        connect(timer, SIGNAL(timeout()), this, SLOT(enable_login()));
        timer->setSingleShot(1);//connect(ui->pushButton, SIGNAL(1), this, SLOT(disable_login()) ); prototype
        timer->start(5000); // NOTE: timer repeats every 5secs which is bad for us...

        ui->label_loginStatus->setText("");
        ui->label_loginStatus->show();
        ui->label_loginStatus->setText("Please Wait for 5 secs");
        ui->label_loginStatus->setStyleSheet("color: red;");

    }
}

void Dialog::enable_login()
{
    ui->pushButton->setEnabled(1);
    ui->pushButton->setStyleSheet("color:black");
    ui->label_loginStatus->hide();
    attempt=0;//resetting attempts

}

