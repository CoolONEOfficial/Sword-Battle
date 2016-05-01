#include "animation.h"

Animation::Animation(QObject *parent) : QObject(parent)
{

}

void Animation::setValueAnimation(int newVal)
{
    value = newVal;
}

int Animation::getValueAnimation()
{
    return value;
}

void Animation::create()
{
    animation = new QPropertyAnimation(this, "value");
}

void Animation::stop()
{
    animation->stop();
}

void Animation::start(bool stopAnimation, bool setDefaultCoords)
{
    if(stopAnimation)
        stop();
    if(setDefaultCoords)
        reset();
    animation->start();
}

void Animation::pause()
{
    animation->pause();
}

void Animation::setValue(int newVal, bool saveDefaultCoords)
{
    if(saveDefaultCoords)
        dValue = newVal;
    value = newVal;
}

void Animation::reset()
{
    value = dValue;
}

void Animation::setEndValue(int newVal)
{
    animation->setEndValue(newVal);
}

void Animation::setDuration(int duration)
{
    animation->setDuration(duration);
}

void Animation::setEasingCurve(QEasingCurve easingCurve)
{
    animation->setEasingCurve(easingCurve);
}

