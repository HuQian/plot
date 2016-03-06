#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(slot_analysis(bool)));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slot_combo(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::slot_analysis(bool flag)
{
    flag != flag;

    ui->listWidget->addItem("hello");

}

void Dialog::slot_combo(int index)
{

}
