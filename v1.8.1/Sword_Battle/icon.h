#ifndef ICON_H
#define ICON_H

#include <QObject>
#include <QImage>

#include "animationcoords.h"

class Widget;

class Icon : public QObject
{
    Q_OBJECT
public:
    explicit Icon(QObject *parent = 0);

    // Widget
    Widget *widget;

    static const int size = 70;

    // Animation
    AnimationCoords animation;
    int x();
    int y();

    // State
    int state;

    // Images
    QImage images[2];

signals:

public slots:
    void load(QString type);
    void setWidget(Widget *w);
    void draw(QPainter &p);
    void setState(int newState);
    bool inside(int cursorX,int cursorY);

};

#endif // ICON_H
