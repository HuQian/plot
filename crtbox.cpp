#include "crtbox.h"
#include "ui_crtbox.h"
#include "dialog.h"

crtbox::crtbox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crtbox)
{
    ui->setupUi(this);
    connect(this->ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(slot_label_time(int)));
    connect(this->ui->toolButton,SIGNAL(clicked(bool)),this,SLOT(slot_button_more(bool)));

}

crtbox::~crtbox()
{
     delete ui;
}

void crtbox::slot_label_time(int value)
{
    m_sum_time = value;


    ui->label_5->setText("0s/"+QString::number(m_sum_time)+"s");
}

void crtbox::slot_button_more(bool flag)
{
    flag = !flag;
    Dialog a;
    a.setWindowTitle("Analysis");
    a.exec();
}
