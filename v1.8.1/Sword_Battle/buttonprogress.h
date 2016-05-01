#ifndef BUTTONPROGRESS_H
#define BUTTONPROGRESS_H

#include <QImage>
#include "button.h"
class ButtonProgress : public Button
{
public:
    bool rightDir;
    ButtonProgress();

    static const int opasityColor = 150;

    QImage backgroundImages[3];

    QColor progressColor;
    float progressValue;

    int progressX, progressY;

    void draw(QPainter &p);
    void load();

    void setValue(int newVal);
    void setColor(QColor newColor);
};

#endif // BUTTONPROGRESS_H
