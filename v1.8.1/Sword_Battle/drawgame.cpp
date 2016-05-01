#include "widget.h"
#include "ui_widget.h"

void Widget::drawGame(QPainter &p, int sceneid)
{
    // ----------------------------------------------------------------- Game -----------------------------------------------------------------

    if(sceneid == sceneMap["game"] ||
            sceneid == sceneMap["gamePause"] ||
            sceneid == sceneMap["gameOptions"])
    {
        // Set Font
        p.setFont(fontAxis);

        // Draw background
        gameBackgroundRect.setRect(0,0,width(),height());
        p.drawImage(gameBackgroundRect,gameBackground);

        // Layers
        if(sceneid != sceneMap["gamePause"] &&
                sceneid != sceneMap["gameOptions"])
        {            
            // Draw texts
            drawGameUi(p);

            if(upLayer)
            {
                drawPlayerSword(p);
                drawEnemySword(p);
            }
            else
            {
                drawEnemySword(p);
                drawPlayerSword(p);
            }

            // HealthBars
            drawHealthbars(p);

            if(enemyCombo >  0)
            {
                if(enemyCombo<=10)
                    p.setPen(QColor(enemyCombo*25.5,0,0));
                else
                    p.setPen(QColor(255,0,0));

                p.drawText(QRect((enemyHealthBarAnimation.x - enemyHealthBarDown.width())-enemyCombo+(rand()%(enemyCombo*2)),
                                 (playerHealthBarAnimation.y+playerHealthBarDown.height())-enemyCombo+(rand()%(enemyCombo*2)),
                             playerHealthBarDown.width()-playerHealthBarIcon.width(), playerHealthBarDown.height()), Qt::AlignRight, "x"+QString::number(enemyCombo));
            }

            if(playerCombo >  0)
            {
                if(playerCombo<=10)
                    p.setPen(QColor(playerCombo*25.5,0,0));
                else
                    p.setPen(QColor(255,0,0));

                p.drawText(QRect((playerHealthBarAnimation.x+playerHealthBarIcon.width())-playerCombo+(rand()%(playerCombo*2)),
                                 (playerHealthBarAnimation.y+playerHealthBarDown.height())-playerCombo+(rand()%(playerCombo*2)),
                             playerHealthBarDown.width(), playerHealthBarDown.height()), Qt::AlignLeft, "x"+QString::number(playerCombo));
            }

            // Draw
            gameButtonPause.draw(p);
        }

        // ----------------------------------------------------------------- Pause -----------------------------------------------------------------
       else if(sceneid == sceneMap["gamePause"])
        {
            // Pause black rect
            QBrush oldBrush = p.brush();
            QBrush brush = QColor(Qt::black);
            p.setBrush(brush);
            p.drawRect(gameBackgroundMaskPauseAnimation.x,
                       gameBackgroundMaskPauseAnimation.y+(height()/2),
                       width(),
                       height());
            p.setBrush(oldBrush);

            // Mask Pause
            QLinearGradient gamePauseMask(gameBackgroundMaskPauseAnimation.x,
                                          gameBackgroundMaskPauseAnimation.y,
                                          gameBackgroundMaskPauseAnimation.x,
                                          gameBackgroundMaskPauseAnimation.y+(height()/2));
            gamePauseMask.setColorAt(0, colorNone);
            gamePauseMask.setColorAt(1, Qt::black);
            QBrush gamePauseMaskBrush(gamePauseMask);
            p.setBrush(gamePauseMaskBrush);

            p.drawRect(0, 0, width(), height());

            fontAxis.setPixelSize(height()/8);
            p.setFont(fontAxis);
            p.drawText(0,gameBackgroundMaskPauseAnimation.y, width(),p.font().pixelSize(), Qt::AlignCenter, "Pause");

            // Draw
            pauseButtonMain.draw(p);
            pauseButtonOptions.draw(p);
            pauseButtonBack.draw(p);
            pauseButtonExit.draw(p);
        }
        else if(sceneid == sceneMap["gameOptions"])
        {
            p.setBrush(QColor(0,0,0,100));
            p.drawRect(0,0,width(),height());

            // Mask Pause
            QLinearGradient gameOptionsMask(gameOptionsMaskAnimation.x,
                                          gameOptionsMaskAnimation.y,
                                          gameOptionsMaskAnimation.x,
                                          gameOptionsMaskAnimation.y+(height()/2));
            gameOptionsMask.setColorAt(0, colorNone);
            gameOptionsMask.setColorAt(1, Qt::black);
            QBrush gameOptionsMaskBrush(gameOptionsMask);
            p.setBrush(gameOptionsMaskBrush);

            p.drawRect(0, 0, width(), height());

            fontAxis.setPixelSize(height()/8);
            p.setFont(fontAxis);
            p.drawText(0,gameOptionsMaskAnimation.y, width(),p.font().pixelSize(), Qt::AlignCenter, gameOptionsText);

            // Draw Buttons
            gameOptionsButtonHard.draw(p);
            gameOptionsButtonPlay.draw(p);
            gameOptionsButtonMain.draw(p);
        }
    }
}

void Widget::drawGameUi(QPainter &p)
{
    // Draw Texts

    // Score
    fontAxis.setPixelSize(height()/10);
    p.setFont(fontAxis);

    QRect playerScoreRect(0, height()-fontAxis.pixelSize()*3,
                          width(), fontAxis.pixelSize());

    p.drawText(playerScoreRect, Qt::AlignCenter, QString::number(playerScore));

    // Highscore
    fontAxis.setPixelSize(height()/15);
    p.setFont(fontAxis);

    QRect playerHighscoreRect(0, height()-fontAxis.pixelSize()-gameIndentY*2,
                          width(), fontAxis.pixelSize()+gameIndentY);

    p.drawText(playerHighscoreRect, Qt::AlignCenter, "Highscore: "+QString::number(playerHighscore));

    // Coins
    fontAxis.setPixelSize(height()/20);
    p.setFont(fontAxis);

    QRect playerCoinsRect(0, height()-fontAxis.pixelSize()-gameIndentY*2-gameIndentY*4,
                          width(), fontAxis.pixelSize());

    p.drawText(playerCoinsRect, Qt::AlignCenter, "Coins: "+QString::number(coins));
}

void Widget::drawPlayerSword(QPainter &p)
{
    p.resetTransform();

    QRect playerSwordRect = QRect(0, 0,
                           swords[usedSwordId].sword.width(), swords[usedSwordId].sword.height());

    playerAngle = (playerAnimation.y*(180.0/height())-90)-(enemyAnimation.y*(180.0/height())-90);

    if(playerLeft)
        p.translate(playerAnimation.x-(swords[usedSwordId].sword.width()/2),playerAnimation.y-(swords[usedSwordId].sword.height()/2));
    else
        p.translate(playerAnimation.x+(swords[usedSwordId].sword.width()/2),playerAnimation.y-(swords[usedSwordId].sword.height()/2));

    p.setMatrix(matrixPlayer, true);

    p.rotate(playerAngle);
    p.drawImage(playerSwordRect,swords[usedSwordId].sword);

    // Mask
    float opasity = p.opacity();
    if(playerCombo <= 10)
        p.setOpacity(playerCombo/20.0);
    else
        p.setOpacity(0.5);
    p.drawImage(playerSwordRect,swords[usedSwordId].mask);
    p.setOpacity(opasity);

    p.rotate(-playerAngle);

    p.resetMatrix();

    if(playerLeft)
        p.translate(-(playerAnimation.x-(swords[usedSwordId].sword.width()/2)),-(playerAnimation.y-(swords[usedSwordId].sword.height()/2)));
    else
        p.translate(-(playerAnimation.x+(swords[usedSwordId].sword.width()/2)),-(playerAnimation.y)-(swords[usedSwordId].sword.height()/2));

    p.resetTransform();
}

void Widget::drawEnemySword(QPainter &p)
{
    p.resetTransform();

    QRect enemySwordRect = QRect(0, 0,
                           enemySwords[usedEnemySwordId].sword.width(), enemySwords[usedEnemySwordId].sword.height());

    enemyAngle = (enemyAnimation.y*(180.0/height())-90)-(enemyAnimation.y*(180.0/height())-90);

    if(playerLeft)
        p.translate(enemyAnimation.x-(enemySwords[usedEnemySwordId].sword.width()/2),enemyAnimation.y-(enemySwords[usedEnemySwordId].sword.height()/2));
    else
        p.translate(enemyAnimation.x+(enemySwords[usedEnemySwordId].sword.width()/2),enemyAnimation.y-(enemySwords[usedEnemySwordId].sword.height()/2));

    p.setMatrix(matrixPlayer, true);

    p.rotate(enemyAngle);
    p.drawImage(enemySwordRect,enemySwords[usedEnemySwordId].sword);

    // Mask
    float opasity = p.opacity();
    if(enemyCombo <= 10)
        p.setOpacity(enemyCombo/20.0);
    else
        p.setOpacity(0.5);
    p.drawImage(enemySwordRect,enemySwords[usedEnemySwordId].mask);
    p.setOpacity(opasity);

    p.rotate(-enemyAngle);

    p.resetMatrix();

    if(playerLeft)
        p.translate(-(enemyAnimation.x-(enemySwords[usedEnemySwordId].sword.width()/2)),-(enemyAnimation.y-(enemySwords[usedEnemySwordId].sword.height()/2)));
    else
        p.translate(-(enemyAnimation.x+(enemySwords[usedEnemySwordId].sword.width()/2)),-(enemyAnimation.y)-(enemySwords[usedEnemySwordId].sword.height()/2));

    p.resetTransform();
}

void Widget::drawHealthbars(QPainter &p)
{
    // Scales Healthbars
    float enemyScaleHealthBarEnd = 100.0/dEnemyHealth*4.73;
    float playerScaleHealthBarEnd = 100.0/dPlayerHealth*4.73;

    float shiftHealthBarStart = 110;

    // ----------------------------------------------------------------- Player Bar -----------------------------------------------------------------

    // Draw Down Layer
    p.drawImage(playerHealthBarAnimation.x, playerHealthBarAnimation.y, playerHealthBarDown);

    // Draw DHealth
    for(int f = shiftHealthBarStart+(playerHealth*playerScaleHealthBarEnd);
        f<shiftHealthBarStart+(playerHealthDAnimation.value*playerScaleHealthBarEnd);
        f++)
    {
        if(f > playerHealthDAnimation.value*playerScaleHealthBarEnd)
        {
            if(f-playerHealthBarDImg.width()-gameIndentX < width()-gameIndentX-playerHealthBarIcon.width()/2)
            {
                p.drawImage(f+playerHealthBarDImg.width()+gameIndentX, 42+playerHealthBarAnimation.y, playerHealthBarDImg);
            }
        }
    }

    // Draw Health
    for(int f = shiftHealthBarStart;
        f<shiftHealthBarStart+(playerHealth*playerScaleHealthBarEnd);
        f++)
    {
        p.drawImage(f+playerHealthBarImg.width()+gameIndentX,42+playerHealthBarAnimation.y,playerHealthBarImg);
    }

    // Draw Up Layer
    p.drawImage(playerHealthBarAnimation.x, playerHealthBarAnimation.y, playerHealthBarUp);

        // Icon
    p.drawImage(playerHealthBarAnimation.x, playerHealthBarAnimation.y, playerHealthBarIcon);

        // Mask
    qreal opacity = p.opacity();
    p.setOpacity(0.5-playerHealthDAnimation.value/100.0);
    p.drawImage(playerHealthBarAnimation.x, playerHealthBarAnimation.y,playerHealthBarIconMask);
    p.setOpacity(opacity);

    // ----------------------------------------------------------------- Enemy Bar -----------------------------------------------------------------

    // Draw Down Layer
    p.drawImage(enemyHealthBarAnimation.x - enemyHealthBarDown.width(), enemyHealthBarAnimation.y, enemyHealthBarDown);

    // Draw DHealth
    for(int f = width()-shiftHealthBarStart-(enemyHealth*enemyScaleHealthBarEnd);
        f>width()-shiftHealthBarStart-(enemyHealthDAnimation.value*enemyScaleHealthBarEnd);
        f--)
    {
        if(f > enemyHealthDAnimation.value*enemyScaleHealthBarEnd)
        {
            if(f-enemyHealthBarDImg.width()-gameIndentX < width()-gameIndentX-enemyHealthBarIcon.width()/2)
            {
                p.drawImage(f-enemyHealthBarDImg.width()-gameIndentX,42+enemyHealthBarAnimation.y,enemyHealthBarDImg);
            }
        }
    }

    // Draw Health
    for(int f = width()-shiftHealthBarStart;
        f>width()-shiftHealthBarStart-(enemyHealth*enemyScaleHealthBarEnd);
        f--)
    {
        p.drawImage(f-enemyHealthBarImg.width()-gameIndentX,42+enemyHealthBarAnimation.y,enemyHealthBarImg);
    }

    // Draw Up Layer
    p.drawImage(enemyHealthBarAnimation.x-enemyHealthBarUp.width(),enemyHealthBarAnimation.y,enemyHealthBarUp);

    // Icon
    p.drawImage(enemyHealthBarAnimation.x-enemyHealthBarIcon.width(),enemyHealthBarAnimation.y,enemyHealthBarIcon);

    // Mask
    opacity = p.opacity();
    p.setOpacity(0.5-enemyHealthDAnimation.value/100.0);
    p.drawImage(enemyHealthBarAnimation.x-enemyHealthBarIconMask.width(),enemyHealthBarAnimation.y,enemyHealthBarIconMask);
    p.setOpacity(opacity);
}
