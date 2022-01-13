#include "graphviewer.h"

GraphViewer::GraphViewer() : QChartView()
{

}

void GraphViewer::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton)
        this->chart()->zoomReset();
    if(event->button()==Qt::LeftButton)
        PointCLick=event->localPos();
}

void GraphViewer::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        PointRelease=event->localPos();
        QRectF RectZoom(PointCLick,PointRelease);
        this->chart()->zoomIn(RectZoom);
    }
}
