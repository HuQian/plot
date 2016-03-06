#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);

    m_qCustomPlot = new QCustomPlot(this);
    m_layout = new QHBoxLayout(this);
    m_layout->addWidget(m_qCustomPlot);
    //this->setLayout(m_layout);

    this->initUI();
}

graph::~graph()
{

    //delete[] m_qCustomPlot;
    //delete[] m_layout;

    delete ui;

}

void graph::drawPlot()
{
    m_qCustomPlot->clearGraphs();   //清除上次的图像

    QVector<double> y(m_channels);
    QVector<double> x(m_channels);
    double max_y,min_y;

    max_y = min_y = (double)m_data[0];
    for(int i = 0; i < m_channels; i++)
    {

        x[i] = (double)i;
        y[i] = (double)m_data[i];

        if(max_y < y[i])
            max_y = y[i];

        if(min_y > y[i])
            min_y = y[i];
    }

    //qDebug() << max_y << "min" << min_y;    //以数据的最大，最小值作为y轴范围



    // create and configure plottables:
    QCPGraph *graph1 = m_qCustomPlot->addGraph(0);
    //m_qCustomPlot->graph(0)->setData(m_x,y);
    //m_qCustomPlot->graph(0)->setPen(QPen(QColor(255,0,0)));
    graph1->setData(x, y);
    graph1->setPen(QPen(QColor(255,0,0)));
    m_qCustomPlot->xAxis->setRange(0, m_channels);
    m_qCustomPlot->yAxis->setRange(min_y - 1, max_y + 1);
    //m_qCustomPlot->yAxis->setRange(min_y  - 1, max_y + 1);   //以数据的最大，最小值作为y轴范围
    m_qCustomPlot->replot();

    qDebug() << "draw";
}

void graph::initUI()
{


    //==============


    m_qCustomPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    m_qCustomPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    m_qCustomPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    m_qCustomPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    m_qCustomPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    m_qCustomPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    m_qCustomPlot->xAxis->setTickLabelColor(Qt::white);
    m_qCustomPlot->yAxis->setTickLabelColor(Qt::white);
    m_qCustomPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    m_qCustomPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    m_qCustomPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    m_qCustomPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    m_qCustomPlot->xAxis->grid()->setSubGridVisible(true);
    m_qCustomPlot->yAxis->grid()->setSubGridVisible(true);
    m_qCustomPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    m_qCustomPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    m_qCustomPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    m_qCustomPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    m_qCustomPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    m_qCustomPlot->axisRect()->setBackground(axisRectGradient);
}
