#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QColorDialog>
#include <QFont>
#include <QFontDialog>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionOpen_2_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCopy_triggered();

    void on_actionPase_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_Notepad_triggered();

    void on_actionNew_triggered();

    void on_actionExit_triggered();

    void on_actionLogout_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_m_fontSize_valueChanged(int arg1);

    void on_actionFind_triggered();

    void on_m_pb_find_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
