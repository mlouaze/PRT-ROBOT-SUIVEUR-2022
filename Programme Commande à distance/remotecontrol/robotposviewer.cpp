#include "robotposviewer.h"

RobotPosviewer::RobotPosviewer(QWidget *parent) : QChartView (parent)
{
    ListPoints.setPointsVisible();
    Dest.setVisible(false);
    SelectPointsMode=false;
    QPointF Point0=QPointF(0,0);
    ListPoints<<Point0;

    QPointF dest(Xdes,Ydes);
    Dest<<dest;


}

void RobotPosviewer::mousePressEvent(QMouseEvent *event){
    if(SelectPointsMode){
        if(Mode==1){
            QPointF newPoint=this->chart()->mapToValue(event->localPos());
            ListPoints<<newPoint;}
        if(Mode==2){
            if(modeRadius){
                modeRadius=0;
                QPointF newPoint=this->chart()->mapToValue(event->localPos());
                float Rad = sqrt((newPoint.x()-Obstacles.points().last().x())*(newPoint.x()-Obstacles.points().last().x())+(newPoint.y()-Obstacles.points().last().y())*(newPoint.y()-Obstacles.points().last().y()));
                Radius.append(Rad);
                this->viewport()->update();
            }else{
                QPointF newPoint=this->chart()->mapToValue(event->localPos());
                Obstacles<<newPoint;
                modeRadius=1;
            }

        }
    }else{
        this->viewport()->update();
        if(event->button()==Qt::RightButton)
            this->chart()->zoomReset();
        if(event->button()==Qt::LeftButton)
            PointCLick=event->localPos();
    }
}

void RobotPosviewer::mouseReleaseEvent(QMouseEvent *event){
    this->viewport()->update();
    if(SelectPointsMode){
    }else{
        if(event->button()==Qt::LeftButton){
            PointRelease=event->localPos();
            QRectF RectZoom(PointCLick,PointRelease);
            this->chart()->zoomIn(RectZoom);
        }
    }
}

void RobotPosviewer::paintEvent(QPaintEvent *event){

    QChartView::paintEvent(event);
    QPainter Painter(viewport());
    QPen Pen(Qt::green);
    Pen.setWidth(3);
    Pen.setStyle(Qt::DashDotLine);
    Painter.setPen(Pen);
    for(int i=0;i<Radius.length();i++){
        QPointF pointreel=Obstacles.points().at(i);
        QPointF pointfenetre=this->chart()->mapToPosition(pointreel);

        QPointF Pointreelhaut(pointreel.x(), pointreel.y()+Radius.at(i));
        QPointF Pointreeldroit(pointreel.x()+Radius.at(i), pointreel.y());

        QPointF pointfenetrehaut=this->chart()->mapToPosition(Pointreelhaut);
        QPointF pointfenetredroit=this->chart()->mapToPosition(Pointreeldroit);

        int rx=pointfenetredroit.x()-pointfenetre.x();
        int ry=pointfenetrehaut.y()-pointfenetre.y();
        Painter.drawEllipse(pointfenetre,rx,ry);
    }
}

void RobotPosviewer::CalculTrajectoire(){

    float posX=0;
    float posY=0;

    float stepsize = 0.1;//distance between 2 points
    int maxiteration = 100;//maximal number of iterations
    bool Arrived=false;

    float XForce=0;
    float YForce=0;
    float XForcePrev=0;
    float YForcePrev=0;
    float NormForce=0;
    float Xdisplacement=0;
    float Ydisplacement=0;
    float newX=0;
    float newY=0;
    QPointF NewPoint;

    int i=0;

    while(!Arrived&&i<maxiteration){
        XForce=0;
        YForce=0;
        for(int k=0;k<Obstacles.count();k++){ //repulsives forces
            float deltax=(posX-Obstacles.at(k).x());
            float deltay = (posY-Obstacles.at(k).y()) ;
            float dis=sqrt(deltax * deltax + deltay * deltay);
            float radius = Radius.at(k);

            XForce+=deltax/dis*radius*2.5*exp(-Radius.at(k)*dis*dis*1.6);
            YForce+=deltay/dis*radius*2.5*exp(-Radius.at(k)*dis*dis*1.6);
        }

        QPointF arrivePoint;
        arrivePoint=Dest.at(0);
        float deltax=(posX-arrivePoint.x());
        float deltay = (posY-arrivePoint.y()) ;
        float dis=sqrt(deltax * deltax + deltay * deltay);//attractive forces

        XForce-=deltax/(dis*dis)*1.2;
        YForce-=deltay/(dis*dis)*1.2;//ajouter coeff?

        XForce=0.5*(XForce+XForcePrev);
        YForce=0.5*(YForce+YForcePrev);


        NormForce=sqrt(XForce*XForce+YForce*YForce);
        Xdisplacement=XForce/NormForce*stepsize;
        Ydisplacement=YForce/NormForce*stepsize;

        newX=ListPoints.points().last().x()+Xdisplacement;
        newY=ListPoints.points().last().y()+Ydisplacement;

        posX=newX;
        posY=newY;

        NewPoint=QPointF(newX,newY);
        ListPoints<<NewPoint;

        if(dis<=stepsize){//verification distance
            Arrived=true;
        }

        XForcePrev=XForce;
        YForcePrev=YForce;

        i++;
    }

}
