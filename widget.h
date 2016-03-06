#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

//coded and designed by myself
#include "graph.h"
#include "crtbox.h"

//provided by qt
#include <QVBoxLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    //it is a plane for show curve graph
    graph* m_graph;
    //it is a plane for controller
    crtbox* m_crtbox;

    QVBoxLayout* m_layout;

};

#endif // WIDGET_H
