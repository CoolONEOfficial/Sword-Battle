#include "widget.h"
#include "ui_widget.h"

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(screensaverEnd())
    {
         // ----------------------------------------------------------------- Game -----------------------------------------------------------------
        if(scene == sceneMap["game"])
        {
            if(event->key() == Qt::Key_Space ||
                    event->key() == Qt::Key_Escape ||
                    event->key() == Qt::Key_Return)
            {
                onClickButton(gameButtonPause.id);
            }
        }
        else if(scene == sceneMap["gamePause"])
        {
            if(event->key() == Qt::Key_Space ||
                    event->key() == Qt::Key_Return)
            {
                onClickButton(pauseButtonBack.id);
            }
            else if(event->key() == Qt::Key_Escape)
            {
                onClickButton(pauseButtonExit.id);
            }
        }

         // ----------------------------------------------------------------- Main -----------------------------------------------------------------
        else if(scene == sceneMap["main"])
        {
            if(event->key() == Qt::Key_Space ||
                    event->key() == Qt::Key_Return)
            {
                onClickButton(mainButtonPlay.id);
            }
            else if(event->key() == Qt::Key_Escape)
            {
                onClickButton(mainButtonExit.id);
            }
        }
        else if(scene == sceneMap["mainQExit"])
        {
            if(event->key() == Qt::Key_Space ||
                    event->key() == Qt::Key_Return)
            {
                onClickButton(qExitButtonYes.id);
            }
            else if(event->key() == Qt::Key_Escape)
            {
                onClickButton(qExitButtonNo.id);
            }
        }
        else if(scene == sceneMap["shop"])
        {
            if(event->key() == Qt::Key_Left ||
                    event->key() == Qt::Key_A)
            {
                onClickButton(shopButtonLeft.id);
            }
            else if(event->key() == Qt::Key_Right ||
                     event->key() == Qt::Key_D)
            {
                onClickButton(shopButtonRight.id);
            }
            else if(event->key() == Qt::Key_Space ||
                    event->key() == Qt::Key_S)
            {
                onClickButton(shopButtonUse.id);
            }
            else if(event->key() == Qt::Key_Escape)
            {
                onClickButton(shopButtonBack.id);
            }
            else if(event->key() == Qt::Key_Return)
            {
                onClickButton(shopButtonUpgrade.id);
            }
        }
    }
    else
    {
        if(!firstOpen)
            goFade();
    }
}
