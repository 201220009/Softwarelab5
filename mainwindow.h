#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QString>
#include<QVector>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_equal_btn_clicked();

    void on_inequal_btn_clicked();

    void on_nextbtn_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> txtnamelist1;
    QVector<QString> txtnamelist2;
    int count;
};

#endif // MAINWINDOW_H
