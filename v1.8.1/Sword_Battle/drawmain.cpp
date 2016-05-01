#include "widget.h"
#include "ui_widget.h"
#include <math.h>

#include <QTimer>

void Widget::drawMain(QPainter &p, int sceneid)
{
    // ----------------------------------------------------------------- DrawMain -----------------------------------------------------------------

    p.setFont(fontRounds);

    // Background
    drawTexture(p,mainBackgroundTexture);

    // Draw Background Logo
    drawBackgroundLogo(p);

    // Draw mainMask (Gradient)
    drawMainGradient(p);

    // Draw Icons
    drawIcons(p);

    // Draw Help Icons Texts
    QBrush brush;
    brush.setColor(whiteBrown);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    QPen pen;
    pen.setColor(brown);
    pen.setWidth(6);
    p.setPen(pen);

    if(iconCoins.inside(moveX, moveY))
    {
        QRect textRect(moveX, moveY+20,125,p.font().pixelSize()+10);
        p.drawRoundRect(textRect,40,40);
        p.setPen(Qt::black);
        p.drawText(textRect, Qt::AlignCenter, "Coins");
    }
    else if(iconDamage.inside(moveX, moveY))
    {
        QRect textRect(moveX-90, moveY+20,180,p.font().pixelSize()+10);
        p.drawRoundRect(textRect,40,40);
        p.setPen(Qt::black);
        p.drawText(textRect, Qt::AlignCenter, "Damage");
    }
    else if(iconSpeed.inside(moveX, moveY))
    {
        QRect textRect(moveX-70, moveY+20,140,p.font().pixelSize()+10);
        p.drawRoundRect(textRect,40,40);
        p.setPen(Qt::black);
        p.drawText(textRect, Qt::AlignCenter, "Speed");
    }
    else if(iconDefense.inside(moveX, moveY))
    {
        QRect textRect(moveX-90, moveY+20,180,p.font().pixelSize()+10);
        p.drawRoundRect(textRect,40,40);
        p.setPen(Qt::black);
        p.drawText(textRect, Qt::AlignCenter, "Defence");
    }
    p.setPen(Qt::black);


    if(sceneid == sceneMap["main"])
    {
        // ----------------------------------------------------------------- Main -----------------------------------------------------------------

        // Draw Logo
        drawLogo(p);

        // Draw
        mainButtonShop.draw(p);
        mainButtonPlay.draw(p);
        mainButtonExit.draw(p);
        mainButtonOptions.draw(p);
    }

    // Options Grand
    else if(sceneid == sceneMap["options"])
    {
        // ----------------------------------------------------------------- Options -----------------------------------------------------------------
        drawLogo(p);

        // Draw
        optionsButtonSoundTrack.draw(p);
        optionsButtonSoundEffects.draw(p);
        optionsButtonBack.draw(p);
        optionsButtonSite.draw(p);
        optionsButtonCheckUpdates.draw(p);
    }

    else if(sceneid == sceneMap["mainQExit"])
    {
        // ----------------------------------------------------------------- QExit -----------------------------------------------------------------

        // Draw Confirm Text
        fontRounds.setPixelSize(width()/12);
        p.setFont(fontRounds);
        QRect mainQConfirmTextRect(0, (height()/2)-(fontRounds.pixelSize()/2)-mainIndentY*2,
                                   width(), fontRounds.pixelSize());
        p.drawText(mainQConfirmTextRect, Qt::AlignCenter, mainQConfirmText);

        // Draw
        qExitButtonNo.draw(p);
        qExitButtonYes.draw(p);
    }

    else if(sceneid == sceneMap["shop"])
    {
        // ----------------------------------------------------------------- Shop -----------------------------------------------------------------

        // Draw Text

            // Text Level
            fontRounds.setPixelSize(height()/20);
            p.setFont(fontRounds);

            QString labelLevelText;
            if(swords[selectSwordId].levelSword>0)
                labelLevelText = "Level:"+QString::number(swords[selectSwordId].levelSword);
            else
                labelLevelText = "For sale!";

            p.drawText(QRect(0,height()/20*6,
                             width(), p.font().pixelSize()),Qt::AlignCenter, labelLevelText);

            // Text Name
            fontRounds.setPixelSize(height()/17);
            p.setFont(fontRounds);

            QString labelNameText = swords[selectSwordId].name;

            p.drawText(QRect(0,height()/20*7,
                             width(), p.font().pixelSize()),Qt::AlignCenter, labelNameText);

        // Draw Logo
            drawLogo(p,true,false);

        // Draw Buttons
            // Upgrade
            // Set Visible
            if(selectSwordId != usedSwordId && swords[selectSwordId].levelSword>0)
                shopButtonUpgrade.visible = false;
            else
                shopButtonUpgrade.visible = true;

            // Set Text
            if(swords[selectSwordId].levelSword>0)
                shopButtonUpgrade.setText("Upgrade");
            else
                shopButtonUpgrade.setText("Buy");

            shopButtonUpgrade.draw(p);

            // Back
            shopButtonBack.draw(p);

            // Use
            if(swords[selectSwordId].levelSword>0)
            {
                if(selectSwordId == usedSwordId)
                    shopButtonUse.setText("Used");
                else
                    shopButtonUse.setText("Use");
                shopButtonUse.draw(p);
            }

            // Left and Right
            shopButtonLeft.draw(p);
            shopButtonRight.draw(p);
    }

    // Screensaver
    drawScreensaver(p);
}


void Widget::drawBackgroundLogo(QPainter &p)
{
    QPolygon logoBackgroundPolygon;
    logoBackgroundPolygon.append(QPoint((width() * 0.125)*2+2, (height() * 0.15625)*3));
    logoBackgroundPolygon.append(QPoint((width() * 0.125)*4, (height() * 0.15625)*1+2));
    logoBackgroundPolygon.append(QPoint((width() * 0.125)*6-2, (height() * 0.15625)*3));
    logoBackgroundPolygon.append(QPoint((width() * 0.125)*4, (height() * 0.15625)*5-2));
    QBrush logoBackgroundPolygonBrush;
    logoBackgroundPolygonBrush.setColor(brown);
    logoBackgroundPolygonBrush.setStyle(Qt::SolidPattern);
    QPainterPath path;
    path.addPolygon(logoBackgroundPolygon);
    p.drawPolygon(logoBackgroundPolygon);
    p.fillPath(path, logoBackgroundPolygonBrush);
}

void Widget::setChange(QPainter &p, QString &changeText, int change1, int change2)
{
    // Set
    changeText = QString::number(change1);

    QColor color = whiteBrownLogo;
    if(change1 != change2)
    {
        if(change1 > change2)
        {
            color.setGreen(255);
        }
        else if(change1 < change2)
        {
            color.setRed(255);
        }
        p.setPen(color);

        changeText+="(";

        if(change1 > change2)
            changeText+="+";

        changeText+=QString::number(change1-change2)+")";
    }
}

void Widget::drawIcons(QPainter &p)
{
    p.setPen(whiteBrownLogo);

    fontArista.setPixelSize(Icon::size/3*2);
    p.setFont(fontArista);

    // Coins

        QString iconCoinsText = QString::number(coins);

        // Draw Icon
        iconCoins.draw(p);

        if((shopButtonUpgrade.inside(moveX, moveY) &&
                swords[selectSwordId].levelSword>0) ||
                (swords[selectSwordId].levelSword == 0))
        {
            // Changes
            iconCoinsText += "-";
            if(swords[selectSwordId].levelSword>0)
                iconCoinsText += QString::number(swords[selectSwordId].price()*pow(2, swords[selectSwordId].levelSword));
            else
                iconCoinsText += QString::number(swords[selectSwordId].price());
        }

        // Draw Text
        p.drawText(QRect(QPoint(iconCoins.x() + iconCoins.size + mainIndentX, iconCoins.y()),
                         QPoint(iconDamage.x(), iconDamage.y() + iconDamage.size)),
                         Qt::AlignVCenter, iconCoinsText);

    // Damage

        QString iconDamageText = QString::number(swords[usedSwordId].damage());

        // Draw
        iconDamage.draw(p);

        if(scene == sceneMap["shop"])
        {
            // Changes
            setChange(p, iconDamageText, swords[selectSwordId].damage(), swords[usedSwordId].damage());

            // Changes of next level
            if(shopButtonUpgrade.inside(moveX, moveY) &&
                    swords[selectSwordId].levelSword>0)
            {
                setChange(p, iconDamageText, swords[selectSwordId].damage(swords[selectSwordId].levelSword+1), swords[selectSwordId].damage());
            }
        }

        // Draw Text
        p.drawText(QRect(QPoint(iconDamage.x() + iconDamage.size + mainIndentX, iconDamage.y()),
                         QPoint(iconDefense.x(), iconDefense.y() + iconDefense.size)),
                         Qt::AlignVCenter, iconDamageText);

    // Defence

        QString iconDefenceText = QString::number(swords[usedSwordId].defence());

        // Draw Icon
        iconDefense.draw(p);

        if(scene == sceneMap["shop"])
        {
            // Changes
            setChange(p, iconDefenceText, swords[selectSwordId].defence(), swords[usedSwordId].defence());

            // Changes of next level
            if(shopButtonUpgrade.inside(moveX, moveY) &&
                    swords[selectSwordId].levelSword>0)
            {
                setChange(p, iconDefenceText, swords[selectSwordId].defence(swords[selectSwordId].levelSword+1), swords[selectSwordId].defence());
            }
        }

        // Draw Text
        p.drawText(QRect(QPoint(iconDefense.x() + iconDefense.size + mainIndentX, iconDefense.y()),
                         QPoint(iconSpeed.x(), iconSpeed.y() + iconSpeed.size)),
                         Qt::AlignVCenter, iconDefenceText);

    // Speed

        QString iconSpeedText = QString::number(swords[usedSwordId].roundSpeed());

        iconSpeed.draw(p);

        if(scene == sceneMap["shop"])
        {
            // Changes
            setChange(p, iconSpeedText, swords[selectSwordId].roundSpeed(), swords[usedSwordId].roundSpeed());

            // Changes of next level
            if(shopButtonUpgrade.inside(moveX, moveY) &&
                    swords[selectSwordId].levelSword>0)
            {
                setChange(p, iconSpeedText, swords[selectSwordId].roundSpeed(swords[selectSwordId].levelSword+1), swords[selectSwordId].roundSpeed());
            }
        }

        p.drawText(QRect(QPoint(iconSpeed.x() + iconSpeed.size + mainIndentX, iconSpeed.y()),
                         QPoint(width(), iconSpeed.y() + iconSpeed.size)),
                         Qt::AlignVCenter, iconSpeedText);

        p.setPen(Qt::black);
}

void Widget::drawLogo(QPainter &p, bool paintSword, bool paintText)
{
    // Draw Logo

    QFont oldFont = p.font();
    if(paintText)
    {
        // Set fonts
        fontVagtur.setPixelSize(height()/8);

        // Set rect
        QRect logoTextRect1(0, height()/2-fontVagtur.pixelSize()-mainButtonPlay.height()/2+(height()/70)+mainIndentY,
                                width(), fontVagtur.pixelSize());

        p.setFont(fontVagtur);

        // Draw text
        p.drawText(logoTextRect1, Qt::AlignCenter, "sword");
    }
    if(paintSword)
    {
        // Set Current Sword Id
        int currentSwordId;
        if(scene == sceneMap["shop"])
            currentSwordId = selectSwordId;
        else
            currentSwordId = usedSwordId;

        // Set rect
        QRect mainLogoSwordRect = rectCenter(QRect(width()/2 - (height()*0.37/2),
                                height()/2 - (height()*0.067/2) - mainButtonPlay.height()/2+mainIndentY,
                                height()*0.37,
                                height()*0.067),
                                swords[currentSwordId].sword.width(),
                                swords[currentSwordId].sword.height());

        // Draw Sword
        p.drawImage(mainLogoSwordRect, swords[currentSwordId].sword);
        p.setOpacity(mainSwordOpasityAnimation.value/1000.0);
        p.drawImage(mainLogoSwordRect, swords[currentSwordId].mask);
        p.setOpacity(1.0);
    }
    if(paintText)
    {
        // Set rect
        QRect logoTextRect2(0, height()/2-mainButtonPlay.height()/2-(height()/70)+mainIndentY,
                                width(), fontVagtur.pixelSize());

        // Draw text
        p.drawText(logoTextRect2, Qt::AlignCenter, "battle");

        // Draw Ver
        fontVagtur.setPixelSize(height()/18);
        p.setFont(fontVagtur);

        QRect logoVerTextRect(0, height()/3*2,
                                width(), fontVagtur.pixelSize());

        p.drawText(logoVerTextRect, Qt::AlignCenter, ver);

        // Draw Highscore
        if(playerHighscore>0)
        {
            fontVagtur.setPixelSize(height()/20);
            p.setFont(fontVagtur);

            QRect logoHighscoreTextRect(0, height()/3*2-fontVagtur.pixelSize()*1.5,
                                    width(), fontVagtur.pixelSize());

            p.drawText(logoHighscoreTextRect, Qt::AlignCenter, "highscore: "+QString::number(playerHighscore));
        }

        p.setFont(oldFont);
    }
}

void Widget::drawTexture(QPainter &p, QImage texture, int startX, int startY)
{
    for(int x = startX; x<startX+1+width() / (width() * 0.125); x++)
    {
        for(int y = startY; y<startY+1+height() / (height() * 0.15625); y++)
        {
            mainBackgroundTextureRect.setRect(x*(width() * 0.125),y*(height() * 0.15625),
                                              (width() * 0.125),(height() * 0.15625));
            p.drawImage(mainBackgroundTextureRect, texture);
        }
    }
}

void Widget::drawScreensaver(QPainter &p)
{
    // Draw Screensaver
    QPen oldPen = p.pen();
    QPen screensaverPen;
    QFont oldFont = p.font();

    p.setOpacity(1-(opasityScreensaverAnimation.value/1000.0));
    p.setBrush(Qt::black);
    p.drawRect(0,0,width(),height());
    screensaverPen.setColor(whiteBrownLogo);
    p.setPen(screensaverPen);
    fontProjects.setPixelSize(height()*0.1111);
    p.setFont(fontProjects);
    p.drawText(width()*0.49-((height()*0.1111)*5.175),height()*0.5452,"cool");
    fontProjects.setPixelSize(height()*0.1428);
    p.setFont(fontProjects);
    p.drawText(width()*0.49,height()*0.55,"one");
    fontProjects.setPixelSize(height()*0.055);
    screensaverPen.setColor(Qt::red);
    p.setPen(screensaverPen);
    p.setFont(fontProjects);
    p.drawText(screensaverSmallTextAnimation.x, screensaverSmallTextAnimation.y, mainScreensaverSmallText);

    p.setPen(oldPen);
    p.setOpacity(1.0);
    p.setFont(oldFont);
}

void Widget::goFade()
{
    // Fade Timer
    opasityScreensaverAnimation.animation->start();
    screensaverTimer->stop();
}

void Widget::drawMainGradient(QPainter &p)
{
    QRadialGradient mainMask(QPoint(width()/2-(width()/10), height()/2-(mainButtonPlay.height()/2)-(mainIndentY)),
                            (height()/2)-(mainButtonPlay.height()/2)-mainIndentY*2);
    mainMask.setColorAt(0, colorNone);
    mainMask.setColorAt(1, Qt::black);
    QBrush mainMaskBrush(mainMask);
    p.setBrush(mainMaskBrush);

    p.scale(1.25,1.0);

    p.drawRect(0, 0, width(), height()-mainButtonPlay.height()-(mainIndentY*2));

    p.setBrush(QColor(Qt::black));
    p.drawRect(0,height()-mainButtonPlay.height()-mainIndentY*2,
               width(),mainButtonPlay.height()+mainIndentY*2);

    p.resetTransform();
}
