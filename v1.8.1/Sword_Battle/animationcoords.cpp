#include "animationcoords.h"

#include <QPropertyAnimation>

AnimationCoords::AnimationCoords(QObject *parent) : QObject(parent)
{

}

void AnimationCoords::setXAnimation(int newVal)
{
    x = newVal;
}

int AnimationCoords::getXAnimation()
{
    return x;
}

void AnimationCoords::setYAnimation(int newVal)
{
    y = newVal;
}

int AnimationCoords::getYAnimation()
{
    return y;
}

void AnimationCoords::create()
{
    animationX = new QPropertyAnimation(this, "x");
    animationY = new QPropertyAnimation(this, "y");
}

void AnimationCoords::stop()
{
    animationX->stop();
    animationY->stop();
}

void AnimationCoords::resetX()
{
    x = dX;
}

void AnimationCoords::resetY()
{
    y = dY;
}

void AnimationCoords::reset()
{
    resetX();
    resetY();
}

void AnimationCoords::start(bool stopAnimation, bool setDefaultCoords)
{
    if(stopAnimation)
        stop();
    if(setDefaultCoords)
        reset();

    animationX->setEndValue(endX);
    animationY->setEndValue(endY);

    animationX->start();
    animationY->start();
}

void AnimationCoords::startOut(bool stopAnimation)
{
    if(stopAnimation)
        stop();

    animationX->setEndValue(dX);
    animationY->setEndValue(dY);

    animationX->start();
    animationY->start();
}

void AnimationCoords::pause()
{
    animationX->pause();
    animationY->pause();
}

void AnimationCoords::setX(int newVal, bool saveDefaultCoords)
{
    if(saveDefaultCoords)
        dX = newVal;

    x = newVal;
}

void AnimationCoords::setY(int newVal, bool saveDefaultCoords)
{
    if(saveDefaultCoords)
        dY = newVal;

    y = newVal;
}

void AnimationCoords::setEndX(int newVal)
{
    animationX->setEndValue(newVal);
    endX = newVal;
}

void AnimationCoords::setEndY(int newVal)
{
    animationY->setEndValue(newVal);
    endY = newVal;
}

void AnimationCoords::setDuration(int duration)
{
    animationX->setDuration(duration);
    animationY->setDuration(duration);
}

void AnimationCoords::setEasingCurve(QEasingCurve easingCurve)
{
    animationX->setEasingCurve(easingCurve);
    animationY->setEasingCurve(easingCurve);
}

