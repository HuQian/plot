#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include "graph/qcustomplot.h"

#define MAX_CHANNELS 4096


namespace Ui {
class graph;
}

class graph : public QWidget
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = 0);
    ~graph();


    void drawPlot();

    long m_data[MAX_CHANNELS];
    short m_channels;

private:
    void initUI();

    QHBoxLayout *m_layout;
    QCustomPlot *m_qCustomPlot;


    Ui::graph *ui;
};

#endif // GRAPH_H
