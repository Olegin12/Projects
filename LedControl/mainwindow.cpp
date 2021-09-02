#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QSerialPort serialPort;
   serialPort.setPortName(this->ui->textPort->text());
   serialPort.setBaudRate(QSerialPort::Baud9600 );
   if (!serialPort.open(QIODevice::ReadWrite))
   {

       QMessageBox::warning(this, "Error", "No connection");
       return;
   }
   serialPort.write("1");
   //serialPort.waitForBytesWritten();
  QByteArray data;
   while(serialPort.waitForReadyRead(10))
   {
         data.append(serialPort.readAll());
   }
   ui->textOutput->append(data);

   serialPort.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QSerialPort serialPort;
    serialPort.setPortName(this->ui->textPort->text());
    serialPort.setBaudRate(QSerialPort::Baud9600 );
    if (!serialPort.open(QIODevice::ReadWrite))
    {

        QMessageBox::warning(this, "Error", "No connection");
        return;
    }
    serialPort.write("2");
    //serialPort.waitForBytesWritten();
   QByteArray data;
    while(serialPort.waitForReadyRead(10))
    {
          data.append(serialPort.readAll());
    }
    ui->textOutput->append(data);

    serialPort.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    QSerialPort serialPort;
    serialPort.setPortName(this->ui->textPort->text());
    serialPort.setBaudRate(QSerialPort::Baud9600 );
    if (!serialPort.open(QIODevice::ReadWrite))
    {

        QMessageBox::warning(this, "Error", "No connection");
        return;
    }
    serialPort.write("3");
    //serialPort.waitForBytesWritten();
   QByteArray data;
    while(serialPort.waitForReadyRead(10))
    {
          data.append(serialPort.readAll());
    }
    ui->textOutput->append(data);

    serialPort.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    QSerialPort serialPort;
    serialPort.setPortName(this->ui->textPort->text());
    serialPort.setBaudRate(QSerialPort::Baud9600 );
    if (!serialPort.open(QIODevice::ReadWrite))
    {

        QMessageBox::warning(this, "Error", "No connection");
        return;
    }
    serialPort.write("4");
    //serialPort.waitForBytesWritten();
   QByteArray data;
    while(serialPort.waitForReadyRead(10))
    {
          data.append(serialPort.readAll());
    }
    ui->textOutput->append(data);

    serialPort.close();
}

void MainWindow::on_pushButton_5_clicked()
{
    QSerialPort serialPort;
    serialPort.setPortName(this->ui->textPort->text());
    serialPort.setBaudRate(QSerialPort::Baud9600 );
    if (!serialPort.open(QIODevice::ReadWrite))
    {

        QMessageBox::warning(this, "Error", "No connection");
        return;
    }
    serialPort.write("reset");
    //serialPort.waitForBytesWritten();
   QByteArray data;
    while(serialPort.waitForReadyRead(10))
    {
          data.append(serialPort.readAll());
    }
    ui->textOutput->append(data);

    serialPort.close();
}
