#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QPropertyAnimation>

class Animation : public QObject
{
    Q_OBJECT
public:
    explicit Animation(QObject *parent = 0);

    QPropertyAnimation *animation;

    int value;
    int dValue;

    void setValueAnimation(int newVal);
    int getValueAnimation();

    Q_PROPERTY(int value READ getValueAnimation WRITE setValueAnimation)

    signals:

    public slots:
    void create();
    void stop();
    void start(bool stopAnimation = true, bool setDefaultCoords = true);
    void pause();
    void reset();
    void setValue(int newVal, bool saveDefaultCoords = true);
    void setEndValue(int newVal);
    void setDuration(int duration);
    void setEasingCurve(QEasingCurve easingCurve);
};

#endif // ANIMATION_H
