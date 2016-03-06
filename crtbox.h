#ifndef CRTBOX_H
#define CRTBOX_H

#include <QWidget>

namespace Ui {
class crtbox;
}

class crtbox : public QWidget
{
    Q_OBJECT

public:
    explicit crtbox(QWidget *parent = 0);
    ~crtbox();

private:
    Ui::crtbox *ui;
    int m_sum_time;

private slots:
    void slot_label_time(int value);
    void slot_button_more(bool flag);
};

#endif // CRTBOX_H
