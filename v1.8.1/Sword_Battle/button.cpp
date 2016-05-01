#include "button.h"
#include "widget.h"

#include <QMessageBox>

Button::Button(QObject *parent) : QObject(parent)
{
    widget = 0;

    visible = true;
}

int Button::x()
{
    return animation.x;
}

int Button::y()
{
    return animation.y;
}

int Button::width()
{
    return images[0].width();
}

int Button::height()
{
    return images[0].height();
}

bool Button::inside(int cursorX, int cursorY)
{
    if( cursorX > animation.x &&
       cursorX < animation.x + width() &&
       cursorY > animation.y &&
       cursorY < animation.y + height() &&
       visible)
       return true;
    else
       return false;
}

void Button::setWidget(Widget *w)
{
    widget = w;
}

void Button::load(QString type)
{
    QString path = "buttons//"+type+"//";

    // Load
    widget->loadImage(images[0], path + "passive.png");
    widget->loadImage(images[1], path + "move.png");
    widget->loadImage(images[2], path + "click.png");
}

void Button::setState(int newState)
{
    state = newState;
}

void Button::draw(QPainter &p)
{
    if(visible)
    {
        // Set state
        if(widget != 0)
        {
            if(inside(widget->moveX,widget->moveY))
            {
                if(widget->clicked)
                {
                    setState(widget->stateMap["click"]);
                    widget->playSound(widget->buttonSoundClick);
                }
                else
                {
                    setState(widget->stateMap["move"]);
                }
            }
            else
            {
                setState(widget->stateMap["passive"]);
            }

            // Draw
            QRect rect;

            p.drawImage(x(), y(), images[state]);

            widget->fontArista.setPixelSize(height()/3);
            p.setFont(widget->fontArista);

            // Draw button text
            if(state == widget->stateMap["click"]) // Click pos text
            {
               rect.setRect(animation.x, animation.y, images[state].width(), images[state].height()*1.05);
            }
            else // Default pos text
            {
               rect.setRect(animation.x, animation.y, images[state].width(), images[state].height()*0.8);
            }

            p.drawText(rect, Qt::AlignCenter, text);
        }
    }
}

void Button::setText(QString newText)
{
    text = newText;
}
