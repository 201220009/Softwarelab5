#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

   count=0;
    /*QFile file("C:/Users/ghx/Desktop/equal.csv");
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }
    QString txtname;
    QStringList txtlist;
    while(!file.atEnd()){
        txtname=file.readLine();
        txtlist=txtname.split(",");
        txtnamelist1.append(txtlist[0]);
        txtnamelist2.append(txtlist[1]);
        txtlist.clear();
    }
    file.close();

    QFile file1(txtnamelist1[1]);
    QFile file2(txtnamelist2[1]);

    if(!file1.open(QIODevice::ReadOnly) || !file2.open(QIODevice::ReadOnly)){
        return;
    }
    QByteArray temp1 =file1.readAll();
    QByteArray temp2 =file2.readAll();

    ui->textEdit->setText(temp1);
    ui->textEdit_2->setText(temp2);*/
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_equal_btn_clicked()
{
    QFile file("C:/Users/ghx/Desktop/equal.csv");
    if(!file.open(QIODevice::Append)){

        return;
    }
    QString temp =txtnamelist1[count]+","+txtnamelist2[count];
    file.write(temp.toUtf8());
    count++;

}

void MainWindow::on_inequal_btn_clicked()
{
    QFile file("C:/Users/ghx/Desktop/inequal.csv");
    if(!file.open(QIODevice::Append)){

        return;
    }
    QString temp =txtnamelist1[count]+","+txtnamelist2[count];
    file.write(temp.toUtf8());
    count++;
}

void MainWindow::on_nextbtn_clicked()
{

     QFile file("C:/Users/ghx/Desktop/equal.csv");
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

         return;
     }
     QString txtname;
     QStringList txtlist;
     txtname=file.readLine();
     while(!file.atEnd()){
         txtname=file.readLine();
         txtlist=txtname.split(",");
         txtlist[1].chop(1);
         txtnamelist1.append(txtlist[0]);
         txtnamelist2.append(txtlist[1]);
         txtlist.clear();
     }
     file.close();


     QFile file1(txtnamelist1[count]);

     if(!file1.open(QIODevice::ReadOnly)){
         QString warning="error";
         ui->textEdit->setText(warning);
         return;
     }

     QByteArray temp1 =file1.readAll();
     ui->textEdit->setText(temp1);
     file1.close();

     QFile file2(txtnamelist2[count]);

     if(!file2.open(QIODevice::ReadOnly)){

         QByteArray temp2 =file2.readAll();
         ui->textEdit_2->setText(temp2);

         return;
     }
     QByteArray temp2 =file2.readAll();
     ui->textEdit_2->setText(temp2);


}
