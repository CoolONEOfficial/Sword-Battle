#include "icon.h"
#include "widget.h"

#include <QMessageBox>

Icon::Icon(QObject *parent) : QObject(parent)
{
    widget = 0;
}

int Icon::x()
{
    return animation.x;
}

int Icon::y()
{
    return animation.y;
}

void Icon::load(QString type)
{
    QString path = "icons//"+type+"//";

    widget->loadImage(images[widget->stateMap["passive"]], path + "passive.png");
    widget->loadImage(images[widget->stateMap["move"]], path + "move.png");
}

void Icon::setWidget(Widget *w)
{
    widget = w;
}

void Icon::draw(QPainter &p)
{
    // Set state
    if(widget != 0)
    {
        if(inside(widget->moveX, widget->moveY))
        {
            setState(widget->stateMap["move"]);
        }
        else
        {
            setState(widget->stateMap["passive"]);
        }
    }

    QRect rect = QRect(x(), y(), size, size);

    p.drawImage(rect, images[state]);
}

void Icon::setState(int newState)
{
    state = newState;
}

bool Icon::inside(int cursorX, int cursorY)
{
    if( cursorX - (x()+size/2) < size/2 &&
        cursorY - (y()+size/2) < size/2 &&
        cursorX - (x()+size/2) > -(size/2) &&
        cursorY - (y()+size/2) > -(size/2) )
       return true;
    else
       return false;
}

