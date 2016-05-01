#ifndef ANIMATIONCOORDS_H
#define ANIMATIONCOORDS_H

#include <QObject>

#include <QPropertyAnimation>

class AnimationCoords : public QObject
{
    Q_OBJECT
public:
    explicit AnimationCoords(QObject *parent = 0);

    QPropertyAnimation *animationX;
    QPropertyAnimation *animationY;

    int x,y;
    int dX,dY,endX,endY;

    void setXAnimation(int newVal);
    int getXAnimation();
    void setYAnimation(int newVal);
    int getYAnimation();

    Q_PROPERTY(int x READ getXAnimation WRITE setXAnimation)
    Q_PROPERTY(int y READ getYAnimation WRITE setYAnimation)

    signals:

    public slots:
    void create();
    void stop();
    void start(bool stopAnimation = true, bool setDefaultCoords = true);
    void startOut(bool stopAnimation = true);
    void pause();
    void setX(int newVal, bool saveDefaultCoords = true);
    void setY(int newVal, bool saveDefaultCoords = true);
    void setEndX(int newVal);
    void setEndY(int newVal);
    void setDuration(int duration);
    void setEasingCurve(QEasingCurve easingCurve);
    void resetX();
    void resetY();
    void reset();
};

#endif // ANIMATIONCOORDS_H
