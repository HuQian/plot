#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    m_graph = new graph(this);
    m_crtbox = new crtbox(this);

    m_layout = new QVBoxLayout(this);

    m_layout->addWidget(m_graph);
    m_layout->addWidget(m_crtbox);
}

Widget::~Widget()
{

    delete m_graph;
    delete m_crtbox;
    delete m_layout;
    delete ui;
}
