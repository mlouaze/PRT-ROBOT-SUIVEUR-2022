#ifndef ROBOTPOSVIEWER_H
#define ROBOTPOSVIEWER_H
#include <QTimer>
#include <QtCharts>
#include <QPainter>
#include <iostream>
#include <QList>
#include <math.h>


class RobotPosviewer: public QChartView
{
    Q_OBJECT
public:
    RobotPosviewer(QWidget *parent = 0);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    void CalculTrajectoire();


    QPointF PointCLick;
    QPointF PointRelease;
    QRectF RectZoom;

    int Mode = 0; //mode=1 for point following, 2 for obstacles
    bool SelectPointsMode;
    QLineSeries ListPoints;//list of passage points
    QScatterSeries Obstacles;//List of obstacles
    QList<float> Radius; //Obstacles radius
    bool modeRadius=0; //1 if we are setting up the radius

    float Xdes=0;
    float Ydes=2;
    QScatterSeries Dest;

protected :
    void paintEvent(QPaintEvent *event) override;
};

#endif // ROBOTPOSVIEWER_H
