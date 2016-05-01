#include "buttonprogress.h"
#include "button.h"
#include "widget.h"

ButtonProgress::ButtonProgress()
{
    rightDir = true;
    progressX = 10;
    progressY = 10;
    progressColor = QColor(255,0,0,opasityColor);
}

void ButtonProgress::draw(QPainter &p)
{
    if(visible)
    {
        if(widget != 0)
        {
            widget->fontArista.setPixelSize(height()/3);
            p.setFont(widget->fontArista);
        }

        // Set state
        if(widget != 0)
        {
            if(inside(widget->moveX,widget->moveY))
            {
                if(widget->clicked)
                {
                    setState(widget->stateMap["click"]);
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
        }

        // Background
        p.drawImage(x(), y(), backgroundImages[state]);
        // Progress
        if(widget != 0)
        {
            QLinearGradient buttonMask(animation.x,animation.y,animation.x+width(),animation.y);
            if(rightDir) // To right Progress
            {
                buttonMask.setColorAt(0, Qt::transparent);
                buttonMask.setColorAt(1, progressColor);
                QBrush buttonMaskBrush(buttonMask);
                p.setBrush(buttonMaskBrush);

                if(state == widget->stateMap["click"])
                { // if Click
                    p.drawRect(animation.x+progressX, animation.y+progressY*1.1,
                               ( backgroundImages[0].width()-progressX*2 )*(progressValue/100),
                               backgroundImages[0].height()-progressY*3);
                }
                else
                { // if Passive or Move
                    p.drawRect(animation.x+progressX, animation.y+progressY,
                               (backgroundImages[0].width()-progressX*2 )*(progressValue/100),
                               backgroundImages[0].height()-progressY*3);
                }
            }
            else if(!rightDir)// To left progress
            {
                buttonMask.setColorAt(1, Qt::transparent);
                buttonMask.setColorAt(0, progressColor);
                QBrush buttonMaskBrush(buttonMask);
                p.setBrush(buttonMaskBrush);

                if(state == widget->stateMap["click"])
                { // if Click
                    p.drawRect(animation.x+width()-progressX, animation.y+progressY*1.1,
                               0 - (( backgroundImages[0].width()-progressX*2 )*(progressValue/100)),
                               backgroundImages[0].height()-progressY*3);
                }
                else
                { // if Passive or Move
                    p.drawRect(animation.x+width()-progressX, animation.y+progressY,
                               0 - (( backgroundImages[0].width()-progressX*2 )*(progressValue/100)),
                               backgroundImages[0].height()-progressY*3);
                }
            }
        }

        // Other
        Button::draw(p);
    }
}

void ButtonProgress::load()
{
    QString path  = "buttons//buttonsProgress//";

    Button::load("buttonsProgress");

    widget->loadImage(backgroundImages[0], path + "backgroundpassive.png");
    widget->loadImage(backgroundImages[1], path + "backgroundmove.png");
    widget->loadImage(backgroundImages[2], path + "backgroundclick.png");
}

void ButtonProgress::setValue(int newVal)
{
    progressValue = newVal;
    widget->setVolume(id);
}

void ButtonProgress::setColor(QColor newColor)
{
    newColor.setAlpha(opasityColor);
    progressColor = newColor;
}
