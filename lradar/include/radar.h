#ifndef _RADAR_H_
#define _RADAR_H_


#include <QWidget>
#include <QVector>

class QTimerEvent;
class QPoint;
class QColor;

class Point
{
public:
    Point()
    {
        m_angle = 0.0;
        m_distance = 0.0;
    }
    Point(double angle, double distance)
    {
        m_angle = angle;
        m_distance = distance;
    }
    double getAngle()
    {
        return m_angle;
    }
    double getDistance()
    {
        return m_distance;
    }
private:
    double m_angle;
    double m_distance;
};

class Radar : public QWidget
{
    Q_OBJECT

public:
    Radar(QWidget *parent = Q_NULLPTR, Qt::WindowFlags fl=Qt::WindowFlags());
    ~Radar();

    void paintEvent(QPaintEvent * event);
    void timerEvent(QTimerEvent *evet);

    void pushPoint(double angle, double distance);

    double getMaxDistance()
    {
        return m_maxDistance;
    }
    void setMaxDistance(double maxDistance)
    {
        m_maxDistance = maxDistance;
    }

private:
    int m_width;
    int m_height;
    int m_radius;
    double m_maxDistance;
    bool m_dir;
    QRect m_rect;
    QPoint m_center;
    QColor m_fontColor;
    QColor m_groudColor;

    QVector<Point> m_points;

    QPixmap *m_pix;
    void preDraw();
    void drawCircle(QPainter &painter);
    void drawArc(QPainter &painter);
    void drawScan(QPainter & painter, double angle);
    void addPoint(double angle, double distance);
    void drawPoints(QPainter & painter);
    
};





#endif // !_RADAR_H_



