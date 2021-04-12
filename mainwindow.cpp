#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_zero,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_one,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_two,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_three,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_four,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_five,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_six,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_seven,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_eight,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_nine,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if((ui->pushButton_plus->isChecked()|| ui->pushButton_minus->isChecked()||ui->pushButton_multiply->isChecked()||ui->pushButton_divide->isChecked())&&(!userIsTypingSecondNumber))
    {
       labelNumber = button->text().toDouble();
       userIsTypingSecondNumber=true;
       newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {
       if(ui->label->text().contains(".")&& button->text()=="0")
       {
           newLabel = ui->label->text()+button->text();
       }
       else
       {
          labelNumber = (ui->label->text()+button->text()).toDouble();
          newLabel = QString::number(labelNumber,'g',15);
       }

    }


    ui->label->setText(newLabel);

}


void MainWindow::on_pushButton_decimal_released()
{
    if(ui->label->text().contains("."))
    {
        ui->label->setText(ui->label->text());

    }
    else
    {
    ui->label->setText(ui->label->text()+".");
    }
}

void MainWindow::unary_operation_pressed()
{
    double labelNumber;
    QString newLabel;

    QPushButton * button = (QPushButton*)sender();
    if(button->text() == "+/-")
    {
      labelNumber= ui->label->text().toDouble();
      labelNumber=labelNumber* -1;
      newLabel = QString::number(labelNumber,'g',15);
      ui->label->setText(newLabel);
     }
    if(button->text() == "%")
    {
      labelNumber= ui->label->text().toDouble();
      labelNumber=labelNumber* .01;
      newLabel = QString::number(labelNumber,'g',15);
      ui->label->setText(newLabel);
     }
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    userIsTypingSecondNumber=false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
  double secondnum,labelNumber;
  QString newLabel;
  secondnum= ui->label->text().toDouble();

  if(ui->pushButton_plus->isChecked())
  {

      labelNumber=firstnum+secondnum;
      newLabel = QString::number(labelNumber,'g',15);
      ui->label->setText(newLabel);
      ui->pushButton_plus->setChecked(false);

  }
  if(ui->pushButton_minus->isChecked())
  {
      labelNumber=firstnum-secondnum;
      newLabel = QString::number(labelNumber,'g',15);
      ui->label->setText(newLabel);
      ui->pushButton_minus->setChecked(false);

  }
  if(ui->pushButton_multiply->isChecked())
  {
      labelNumber=firstnum*secondnum;
      newLabel = QString::number(labelNumber,'g',15);
      ui->label->setText(newLabel);
      ui->pushButton_multiply->setChecked(false);

  }
  if(ui->pushButton_divide->isChecked())
  {
      labelNumber=firstnum/secondnum;
      newLabel = QString::number(labelNumber,'g',15);
      ui->label->setText(newLabel);
      ui->pushButton_divide->setChecked(false);

  }

  userIsTypingSecondNumber=false;

}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    firstnum=ui->label->text().toDouble();
    button->setChecked(true);
}

void MainWindow:: keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_0)
    {
       qDebug()<<"test";
    }
    if(event->key()==Qt::Key_1)
    {

    }
    if(event->key()==Qt::Key_2)
    {

    }
    if(event->key()==Qt::Key_3)
    {

    }
    if(event->key()==Qt::Key_4)
    {

    }
    if(event->key()==Qt::Key_5)
    {

    }
    if(event->key()==Qt::Key_6)
    {

    }
    if(event->key()==Qt::Key_7)
    {

    }
    if(event->key()==Qt::Key_8)
    {

    }
    if(event->key()==Qt::Key_9)
    {

    }

}
