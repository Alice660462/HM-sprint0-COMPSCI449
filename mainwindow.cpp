#include "mainwindow.h"
#include "ui_mainwindow.h"


QImage img(500,500,QImage::Format_ARGB32);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // constructor
    // draw a line here on the canvas
    img.fill(Qt::transparent);
    drawLineDDA(100,300,200,400);
    // insert the canvas into the frame
    ui->myframe->setPixmap(QPixmap::fromImage(img));
    ui->myframe->lower();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: plotPoint(int x, int y){
    //plotting a single point on the canvas
    img.setPixel(x,y,qRgb(255,0,0));
}
void MainWindow::drawLineDDA(int x1, int y1, int x2, int y2){
    float dx = x2 - x1;
    float dy = y2-y1;
    float step;
    if (abs(dx)> abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);

    }
    float x_inc = dx/step;
    float y_inc = dy/step;
    float x = x1;
    float y = y1;
    plotPoint(x1,y1);
    for (int i = 0; i<step; i++){
        plotPoint(x,y);
        x = x+x_inc;
        y = y+y_inc;
    }
}

void MainWindow::on_clearbutton_clicked()
{
    ui->text1->setPlainText("");
    ui->text2->setPlainText("");
    ui->welcome->setText("");
    ui->female->setAutoExclusive(false);
    ui->male->setAutoExclusive(false);
    ui->female->setChecked(false);
    ui->male->setChecked(false);
    ui->female->setAutoExclusive(true);
    ui->male->setAutoExclusive(true);
    ui->dogs->setChecked(false);
    ui->cats->setChecked(false);
}


void MainWindow::on_okbutton_clicked()
{
    QString firstName = ui->text1->toPlainText();
    QString lastName = ui->text2->toPlainText();
    QString pet = "nothing";
    if (ui->cats->isChecked() && ui->dogs->isChecked()) {
        pet = "doggies and kitties";
    }
    else if (ui->dogs->isChecked()) {
        pet = "doggies";
    }
    else if (ui->cats->isChecked()) {
        pet = "kitties";
    }



    ui->welcome->setText( firstName + " " + lastName + " likes " + pet );

}

