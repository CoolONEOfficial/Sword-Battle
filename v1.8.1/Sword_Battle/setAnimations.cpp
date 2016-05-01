#include "widget.h"

void Widget::setAnimations()
{
    // ----------------------------------------------------------------- Animations -----------------------------------------------------------------

    // ----------------------------------------------------------------- Icons -----------------------------------------------------------------

    // Animation Icon Coins
    iconCoins.animation.create();
    iconCoins.animation.setDuration(speedButtonsAnimation);
    iconCoins.animation.setEasingCurve(QEasingCurve::OutBack);

    iconCoins.animation.setX(mainIndentX);
    iconCoins.animation.setY(-iconCoins.size);

    iconCoins.animation.setEndX(iconCoins.animation.x);
    iconCoins.animation.setEndY(mainIndentY);

    // Animation Icon Damage
    iconDamage.animation.create();
    iconDamage.animation.setDuration(speedButtonsAnimation);
    iconDamage.animation.setEasingCurve(QEasingCurve::OutBack);

    iconDamage.animation.setX(width()/4+mainIndentX/2);
    iconDamage.animation.setY(-iconDamage.size);

    iconDamage.animation.setEndX(iconDamage.animation.x);
    iconDamage.animation.setEndY(mainIndentY);

    // Animation Icon Speed
    iconSpeed.animation.create();
    iconSpeed.animation.setDuration(speedButtonsAnimation);
    iconSpeed.animation.setEasingCurve(QEasingCurve::OutBack);

    iconSpeed.animation.setX(width()/4*3+mainIndentX/2);
    iconSpeed.animation.setY(-iconSpeed.size);

    iconSpeed.animation.setEndX(iconSpeed.animation.x);
    iconSpeed.animation.setEndY(mainIndentY);

    // Animation Icon Defense
    iconDefense.animation.create();
    iconDefense.animation.setDuration(speedButtonsAnimation);
    iconDefense.animation.setEasingCurve(QEasingCurve::OutBack);

    iconDefense.animation.setX(width()/4*2+mainIndentX/2);
    iconDefense.animation.setY(-iconDefense.size);

    iconDefense.animation.setEndX(iconDefense.animation.x);
    iconDefense.animation.setEndY(mainIndentY);

    // Animation Icon Price
    iconPrice.animation.create();
    iconPrice.animation.setDuration(speedButtonsAnimation);
    iconPrice.animation.setEasingCurve(QEasingCurve::OutBack);

    iconPrice.animation.setX(width()/4*3+mainIndentX);
    iconPrice.animation.setY(-iconPrice.size);

    iconPrice.animation.setEndX(iconPrice.animation.x);
    iconPrice.animation.setEndY(mainIndentY);

    // ----------------------------------------------------------------- Main Buttons Animations -----------------------------------------------------------------

    int indentMainButtons = (width()-(width()/4-(mainButtonPlay.width())))/4-(mainButtonPlay.width());

    // Animation mainButton Play
    mainButtonPlay.animation.create();
    mainButtonPlay.animation.setDuration(speedButtonsAnimation);
    mainButtonPlay.animation.setEasingCurve(QEasingCurve::OutBack);

    mainButtonPlay.animation.setX(-mainButtonPlay.width());
    mainButtonPlay.animation.setY(height()-mainButtonPlay.height());

    mainButtonPlay.animation.setEndX(indentMainButtons);
    mainButtonPlay.animation.setEndY(height()-mainButtonPlay.height()-mainIndentY);

    // Animation mainButton Exit
    mainButtonExit.animation.create();
    mainButtonExit.animation.setDuration(speedButtonsAnimation);
    mainButtonExit.animation.setEasingCurve(QEasingCurve::OutBack);

    mainButtonExit.animation.setX(width());
    mainButtonExit.animation.setY(height()-mainButtonExit.height()-gameIndentY);

    mainButtonExit.animation.setEndX(indentMainButtons*4+mainButtonPlay.width()*3);
    mainButtonExit.animation.setEndY(mainButtonExit.animation.y);

    // Animation mainButton shop
    mainButtonShop.animation.create();
    mainButtonShop.animation.setDuration(speedButtonsAnimation);
    mainButtonShop.animation.setEasingCurve(QEasingCurve::OutBack);

    mainButtonShop.animation.setX(width());
    mainButtonShop.animation.setY(height()-mainButtonShop.height()-gameIndentY);

    mainButtonShop.animation.setEndX(indentMainButtons*3+mainButtonPlay.width()*2);
    mainButtonShop.animation.setEndY(mainButtonShop.animation.y);

    // Animation mainButton options
    mainButtonOptions.animation.create();
    mainButtonOptions.animation.setDuration(speedButtonsAnimation);
    mainButtonOptions.animation.setEasingCurve(QEasingCurve::OutBack);

    mainButtonOptions.animation.setX(-mainButtonOptions.width());
    mainButtonOptions.animation.setY(height()-mainButtonOptions.height());

    mainButtonOptions.animation.setEndX(indentMainButtons*2+mainButtonPlay.width());
    mainButtonOptions.animation.setEndY(height() - mainButtonOptions.height() - mainIndentY);

    // Animation mainButton options grand
    optionsButtonSoundTrack.animation.create();
    optionsButtonSoundTrack.animation.setDuration(speedButtonsAnimation);
    optionsButtonSoundTrack.animation.setEasingCurve(QEasingCurve::OutBack);

    optionsButtonSoundTrack.animation.setX(0-optionsButtonSoundTrack.width());
    optionsButtonSoundTrack.animation.setY(height()-optionsButtonSoundTrack.height()-gameIndentY);

    optionsButtonSoundTrack.animation.setEndX(width()/5-optionsButtonSoundTrack.width()/2);
    optionsButtonSoundTrack.animation.setEndY(optionsButtonSoundTrack.animation.y);

    // Animation mainButton options sfx
    optionsButtonSoundEffects.animation.create();
    optionsButtonSoundEffects.animation.setDuration(speedButtonsAnimation);
    optionsButtonSoundEffects.animation.setEasingCurve(QEasingCurve::OutBack);

    optionsButtonSoundEffects.rightDir = false;
    optionsButtonSoundEffects.animation.setX(width());
    optionsButtonSoundEffects.animation.setY(height()-optionsButtonSoundEffects.height()-gameIndentY);

    optionsButtonSoundEffects.animation.setEndX(width()/5*4-optionsButtonSoundEffects.width()/2);
    optionsButtonSoundEffects.animation.setEndY(optionsButtonSoundEffects.animation.y);

    // Animation mainButton options back
    optionsButtonBack.animation.create();
    optionsButtonBack.animation.setDuration(speedButtonsAnimation);
    optionsButtonBack.animation.setEasingCurve(QEasingCurve::OutBack);

    optionsButtonBack.animation.setX(width()/2-optionsButtonBack.width()/2);
    optionsButtonBack.animation.setY(height());

    optionsButtonBack.animation.setEndX(width()/2-optionsButtonBack.width()/2);
    optionsButtonBack.animation.setEndY(height()-optionsButtonBack.height()-mainIndentY);

    // Animation mainButton options check updates
    optionsButtonCheckUpdates.animation.create();
    optionsButtonCheckUpdates.animation.setDuration(speedButtonsAnimation);
    optionsButtonCheckUpdates.animation.setEasingCurve(QEasingCurve::OutBack);

    optionsButtonCheckUpdates.animation.setX(0-optionsButtonCheckUpdates.width());
    optionsButtonCheckUpdates.animation.setY(height()-optionsButtonCheckUpdates.height()*2-mainIndentY*2);

    optionsButtonCheckUpdates.animation.setEndX(width()/3-optionsButtonCheckUpdates.width()/2);
    optionsButtonCheckUpdates.animation.setEndY(height()-optionsButtonCheckUpdates.height()*2-mainIndentY*2);

    // Animation mainButton options check updates
    optionsButtonSite.animation.create();
    optionsButtonSite.animation.setDuration(speedButtonsAnimation);
    optionsButtonSite.animation.setEasingCurve(QEasingCurve::OutBack);

    optionsButtonSite.animation.setX(width());
    optionsButtonSite.animation.setY(height()-optionsButtonSite.height()*2-mainIndentY*2);

    optionsButtonSite.animation.setEndX(width()/3*2-optionsButtonSite.width()/2);
    optionsButtonSite.animation.setEndY(height()-optionsButtonSite.height()*2-mainIndentY*2);

    // Animation mainShopButton Upgrade
    shopButtonUpgrade.animation.create();
    shopButtonUpgrade.animation.setDuration(speedButtonsAnimation);
    shopButtonUpgrade.animation.setEasingCurve(QEasingCurve::OutBack);

    shopButtonUpgrade.animation.setX(width()/2-shopButtonUpgrade.width()/2);
    shopButtonUpgrade.animation.setY(height());

    shopButtonUpgrade.animation.setEndX(width()/2-shopButtonUpgrade.width()/2);
    shopButtonUpgrade.animation.setEndY(height()/20*11);

    // Animation mainShopButton Back
    shopButtonBack.animation.create();
    shopButtonBack.animation.setDuration(speedButtonsAnimation);
    shopButtonBack.animation.setEasingCurve(QEasingCurve::OutBack);

    shopButtonBack.animation.setX(width()/2-shopButtonBack.width()/2);
    shopButtonBack.animation.setY(height());

    shopButtonBack.animation.setEndX(width()/2-shopButtonBack.width()/2);
    shopButtonBack.animation.setEndY(height()-shopButtonBack.height()-mainIndentY);

    // Animation mainShopButton Buy
    shopButtonUse.animation.create();
    shopButtonUse.animation.setDuration(speedButtonsAnimation);
    shopButtonUse.animation.setEasingCurve(QEasingCurve::OutBack);

    shopButtonUse.animation.setX(width()/2-shopButtonUse.width()/2);
    shopButtonUse.animation.setY(height());

    shopButtonUse.animation.setEndX(shopButtonUse.animation.dX);
    shopButtonUse.animation.setEndY(height()-mainIndentY*2-shopButtonUse.height()*2);

    // Animation mainShopButton Left
    shopButtonLeft.animation.create();
    shopButtonLeft.animation.setDuration(speedButtonsAnimation);
    shopButtonLeft.animation.setEasingCurve(QEasingCurve::OutBack);

    shopButtonLeft.animation.setX(-shopButtonLeft.width());
    shopButtonLeft.animation.setY(height()/2-shopButtonLeft.height()/2);

    shopButtonLeft.animation.setEndX(mainIndentX);
    shopButtonLeft.animation.setEndY(shopButtonLeft.animation.dY);

    // Animation mainShopButton Right
    shopButtonRight.animation.create();
    shopButtonRight.animation.setDuration(speedButtonsAnimation);
    shopButtonRight.animation.setEasingCurve(QEasingCurve::OutBack);

    shopButtonRight.animation.setX(width());
    shopButtonRight.animation.setY(height()/2-shopButtonRight.height()/2);

    shopButtonRight.animation.setEndX(width()-shopButtonRight.width()-mainIndentX);
    shopButtonRight.animation.setEndY(shopButtonRight.animation.dY);

    // Animation mainButton QYes
    qExitButtonYes.animation.create();
    qExitButtonYes.animation.setDuration(speedButtonsAnimation);
    qExitButtonYes.animation.setEasingCurve(QEasingCurve::OutBack);

    qExitButtonYes.animation.setX(width());
    qExitButtonYes.animation.setY(height()-qExitButtonYes.height()-gameIndentY);

    qExitButtonYes.animation.setEndX(width()/3*2-qExitButtonYes.width()/2);
    qExitButtonYes.animation.setEndY(qExitButtonYes.animation.y);

    // Animation mainButton QNo
    qExitButtonNo.animation.create();
    qExitButtonNo.animation.setDuration(speedButtonsAnimation);
    qExitButtonNo.animation.setEasingCurve(QEasingCurve::OutBack);

    qExitButtonNo.animation.setX(0-qExitButtonYes.width());
    qExitButtonNo.animation.setY(height()-qExitButtonNo.height()-gameIndentY);

    qExitButtonNo.animation.setEndX(width()/3-qExitButtonNo.width()/2);
    qExitButtonNo.animation.setEndY(qExitButtonNo.animation.y);

    // ----------------------------------------------------------------- Game Buttons Animations -----------------------------------------------------------------

    // Animation gameButton Pause
    gameButtonPause.animation.create();
    gameButtonPause.animation.setDuration(speedButtonsAnimation/3*2);
    gameButtonPause.animation.setEasingCurve(QEasingCurve::OutCirc);

    gameButtonPause.animation.setX(0 - gameButtonPause.width());
    gameButtonPause.animation.setY(height());

    gameButtonPause.animation.setEndX(0);
    gameButtonPause.animation.setEndY(height()-gameButtonPause.height());

    int indentGameButtonsPause = (width()-(width()/4-(pauseButtonBack.width())))/4-(pauseButtonBack.width());

    // Animation gameButton Pause Back
    pauseButtonBack.animation.create();
    pauseButtonBack.animation.setDuration(speedButtonsAnimation);
    pauseButtonBack.animation.setEasingCurve(QEasingCurve::OutCirc);

    pauseButtonBack.animation.setX(0 - pauseButtonBack.width());
    pauseButtonBack.animation.setY(height() - pauseButtonBack.height() - gameIndentY);

    pauseButtonBack.animation.setEndX(indentGameButtonsPause);
    pauseButtonBack.animation.setEndY(pauseButtonBack.animation.y);

    // Animation gameButtonPause Main
    pauseButtonMain.animation.create();
    pauseButtonMain.animation.setDuration(speedButtonsAnimation);
    pauseButtonMain.animation.setEasingCurve(QEasingCurve::OutCirc);

    pauseButtonMain.animation.setX(0 - pauseButtonBack.width());
    pauseButtonMain.animation.setY(height() - pauseButtonBack.height() - gameIndentY);

    pauseButtonMain.animation.setEndX(indentGameButtonsPause*2+(pauseButtonMain.width()));
    pauseButtonMain.animation.setEndY(pauseButtonMain.animation.y);

    // Animation gameButtonPause options
    pauseButtonOptions.animation.create();
    pauseButtonOptions.animation.setDuration(speedButtonsAnimation);
    pauseButtonOptions.animation.setEasingCurve(QEasingCurve::OutCirc);

    pauseButtonOptions.animation.setX(width());
    pauseButtonOptions.animation.setY(height() - pauseButtonExit.height() - gameIndentY);

    pauseButtonOptions.animation.setEndX(indentGameButtonsPause*3+(pauseButtonOptions.width()*2));
    pauseButtonOptions.animation.setEndY(pauseButtonOptions.animation.y);

    // Animation gameButton Pause Exit
    pauseButtonExit.animation.create();
    pauseButtonExit.animation.setDuration(speedButtonsAnimation);
    pauseButtonExit.animation.setEasingCurve(QEasingCurve::OutCirc);

    pauseButtonExit.animation.setX(width());
    pauseButtonExit.animation.setY(height() - pauseButtonExit.height() - gameIndentY);

    pauseButtonExit.animation.setEndX(indentGameButtonsPause*4+(pauseButtonExit.width()*3));
    pauseButtonExit.animation.setEndY(pauseButtonExit.animation.y);

    // Animation gameButton Options Hard
    gameOptionsButtonHard.animation.create();
    gameOptionsButtonHard.animation.setDuration(speedButtonsAnimation);
    gameOptionsButtonHard.animation.setEasingCurve(QEasingCurve::OutBack);

    gameOptionsButtonHard.animation.setX(-gameOptionsButtonHard.width());
    gameOptionsButtonHard.animation.setY(height() - gameOptionsButtonHard.height()-gameIndentY);

    gameOptionsButtonHard.animation.setEndX(gameIndentX);
    gameOptionsButtonHard.animation.setEndY(gameOptionsButtonHard.animation.y);

    gameOptionsButtonHard.setValue(50);

    // Animation gameButton Optons Play
    gameOptionsButtonPlay.animation.create();
    gameOptionsButtonPlay.animation.setDuration(speedButtonsAnimation);
    gameOptionsButtonPlay.animation.setEasingCurve(QEasingCurve::OutBack);

    gameOptionsButtonPlay.animation.setX(width() / 2 - gameOptionsButtonPlay.width()/2);
    gameOptionsButtonPlay.animation.setY(height());

    gameOptionsButtonPlay.animation.setEndX(gameOptionsButtonPlay.animation.x);
    gameOptionsButtonPlay.animation.setEndY(height()- gameOptionsButtonPlay.height()-gameIndentY);

    // Animation gameButton Optons Main
    gameOptionsButtonMain.animation.create();
    gameOptionsButtonMain.animation.setDuration(speedButtonsAnimation);
    gameOptionsButtonMain.animation.setEasingCurve(QEasingCurve::OutBack);

    gameOptionsButtonMain.animation.setX(width());
    gameOptionsButtonMain.animation.setY(height()-gameOptionsButtonMain.height()-gameIndentY);

    gameOptionsButtonMain.animation.setEndX(width()-gameOptionsButtonMain.width()-gameIndentX);
    gameOptionsButtonMain.animation.setEndY(gameOptionsButtonMain.animation.y);

    // ----------------------------------------------------------------- Other Animations -----------------------------------------------------------------

    // Animation enemyCoords
    enemyAnimation.create();
    enemyAnimation.setDuration(enemyAttackSpeed);
    enemyAnimation.setEasingCurve(QEasingCurve::InBack);
    connect(enemyAnimation.animationX, SIGNAL(valueChanged(QVariant)), this, SLOT(checkAttack()));

    // Animation playerCoords
    playerAnimation.create();
    playerAnimation.setDuration(swords[usedSwordId].dSpeed);
    playerAnimation.setEasingCurve(QEasingCurve::OutBack);

    // Animation gameBackgroundMaskPause
    gameBackgroundMaskPauseAnimation.create();
    gameBackgroundMaskPauseAnimation.setDuration(speedButtonsAnimation);
    gameBackgroundMaskPauseAnimation.setEasingCurve(QEasingCurve::OutBack);

    gameBackgroundMaskPauseAnimation.setX(0);
    gameBackgroundMaskPauseAnimation.setY(height());

    gameBackgroundMaskPauseAnimation.setEndX(gameBackgroundMaskPauseAnimation.x);
    gameBackgroundMaskPauseAnimation.setEndY(gameBackgroundMaskPauseAnimation.y-(height()/2)-pauseButtonBack.height()-(gameIndentY*2));

    // main Sword Opasity Animation
    mainSwordOpasityAnimation.create();
    mainSwordOpasityAnimation.setDuration(5000);
    mainSwordOpasityAnimation.setValue(0);
    mainSwordOpasityAnimation.setEndValue(maxOpasitySword);
    connect(mainSwordOpasityAnimation.animation, SIGNAL(finished()), this, SLOT(restartMainSwordOpasityAnimation()));
    mainSwordOpasityAnimation.start(false, false);

    // Animation gameOptionsMask
    gameOptionsMaskAnimation.create();
    gameOptionsMaskAnimation.setDuration(speedButtonsAnimation);
    gameOptionsMaskAnimation.setEasingCurve(QEasingCurve::OutBack);

    gameOptionsMaskAnimation.setX(0);
    gameOptionsMaskAnimation.setY(height());

    gameOptionsMaskAnimation.setEndX(gameOptionsMaskAnimation.x);
    gameOptionsMaskAnimation.setEndY(gameOptionsMaskAnimation.y-(height()/2)-gameOptionsButtonPlay.height()-(gameIndentY*2));


    // Animation screensaver small text
    screensaverSmallTextAnimation.create();
    screensaverSmallTextAnimation.setDuration(50000);
    screensaverSmallTextAnimation.setEasingCurve(QEasingCurve::Linear);

    screensaverSmallTextAnimation.setX(width()*0.477);
    screensaverSmallTextAnimation.setY(height()*0.64);

    screensaverSmallTextAnimation.setEndX(0);
    screensaverSmallTextAnimation.setEndY(height()*0.64);

    // Animation enemyHealthD
    enemyHealthDAnimation.create();
    enemyHealthDAnimation.setDuration(1000);
    enemyHealthDAnimation.setEasingCurve(QEasingCurve::OutSine);

    // Animation playerHealthD
    playerHealthDAnimation.create();
    playerHealthDAnimation.setDuration(1000);
    playerHealthDAnimation.setEasingCurve(QEasingCurve::OutSine);

    // playerHealthBarAnimation
    playerHealthBarAnimation.create();
    playerHealthBarAnimation.setDuration(speedButtonsAnimation);
    playerHealthBarAnimation.setEasingCurve(QEasingCurve::OutBack);

    playerHealthBarAnimation.setX(gameIndentX);
    playerHealthBarAnimation.setY(0-playerHealthBarIcon.height());

    playerHealthBarAnimation.setEndX(playerHealthBarAnimation.x);
    playerHealthBarAnimation.setEndY(playerHealthBarAnimation.y+playerHealthBarIcon.height()+gameIndentY);

    // enemyHealthBarAnimation
    enemyHealthBarAnimation.create();
    enemyHealthBarAnimation.setDuration(speedButtonsAnimation);
    enemyHealthBarAnimation.setEasingCurve(QEasingCurve::OutBack);

    enemyHealthBarAnimation.setX(width()-gameIndentX);
    enemyHealthBarAnimation.setY(0-enemyHealthBarIcon.height());

    enemyHealthBarAnimation.setEndX(enemyHealthBarAnimation.x);
    enemyHealthBarAnimation.setEndY(enemyHealthBarAnimation.y+enemyHealthBarIcon.height()+gameIndentY);

    // Animation OpasityScreensaver
    opasityScreensaverAnimation.create();
    opasityScreensaverAnimation.setDuration(1100);
    opasityScreensaverAnimation.setEasingCurve(QEasingCurve::Linear);

    opasityScreensaverAnimation.setValue(1);
    opasityScreensaverAnimation.setEndValue(1000);

    connect(opasityScreensaverAnimation.animation, SIGNAL(finished()), this, SLOT(startMainAnimations()));
}
