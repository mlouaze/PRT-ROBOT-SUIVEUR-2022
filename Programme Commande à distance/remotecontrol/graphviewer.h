#ifndef GRAPHVIEWER_H
#define GRAPHVIEWER_H
#include <QChart>
#include <QTimer>
#include <QtCharts>
#include <iostream>


class GraphViewer : public QChartView
{
    Q_OBJECT
public:
    GraphViewer();
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event); //redefine the action done when a click is performed
    QPointF PointCLick; //where the click is done
    QPointF PointRelease; //where the click is release
    QRectF RectZoom; //rectangle where we are going to zoom
};
//graphviewer is the widget that show the datas receveived from the robot

#endif // GRAPHVIEWER_H
