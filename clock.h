#ifndef CLOCK_H
#define CLOCK_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
class Clock : public QWidget
{
public:


   Clock(QWidget *parent );
    QSize sizeHint() const override;

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
      void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QPoint dragPosition;

};

#endif // CLOCK_H
