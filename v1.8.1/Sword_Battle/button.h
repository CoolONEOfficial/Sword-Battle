#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include "animation.h"
#include "animationcoords.h"

#include <QPropertyAnimation>
#include <QPainter>
#include <QMap>

class Widget;

class Button : public QObject
{
    Q_OBJECT
public:
    explicit Button(QObject *parent = 0);

    // Widget
    Widget *widget;

    // Animation
    AnimationCoords animation;
    int x();
    int y();

    // Buton Text
    QString text;

    // Images for states
    QImage images[3];
    int width();
    int height();

    // Font
    QFont font;

    // Id
    int id;

    // States
    int state;

    // Visible
    bool visible;

    void setWidget(Widget *w);
    bool inside(int cursorX,int cursorY);
    void load(QString type);
    void setText(QString newText);
    void setState(int newState);
    void draw(QPainter &p);

signals:

public slots:
};

#endif // BUTTON_H
