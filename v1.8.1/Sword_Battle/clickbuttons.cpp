#include "widget.h"
#include "ui_widget.h"
#include <QMediaPlaylist>
#include <QDesktopServices>
#include <math.h>

void Widget::onClickButton(int buttonId)
{
    // ----------------------------------------------------------------- Main -----------------------------------------------------------------

    if(screensaverEnd())
    {
        // Set oldScene
        if(scene != sceneMap["mainQExit"] &&
                scene != sceneMap["options"] &&
                scene != sceneMap["shop"])
            oldScene = scene;

        if(scene == sceneMap["main"]) // ----------------------------- Main -----------------------------

        {
            if(buttonId == mainButtonPlay.id) // Button Play
            {
                scene = sceneMap["gameOptions"];

                // Set Duration (Sword Speed)
                playerAnimation.setDuration(swords[usedSwordId].speed());

                // Set text
                gameOptionsText = "Game Options";

                // Sounds
                playSound(gameSoundStartBattle);
                pauseSound(mainSoundtrack);

                startGameOptionsAnimations();
            }

            else if(buttonId == mainButtonExit.id) // Button Exit
            {
                scene = sceneMap["mainQExit"];

                // Start Animations
                startQExitAnimations();
            }

            else if(buttonId == mainButtonShop.id) // Button shop
            {
                scene = sceneMap["shop"];

                // Set selectSwordId
                selectSwordId = usedSwordId;

                // Start Animations
                startShopAnimations();

                shopButtonUse.visible = true;
            }

            else if(buttonId == mainButtonOptions.id) // Button options
            {
                scene = sceneMap["options"];

                // Start Animations
                startOptionsAnimations();
            }

        }

        else if(scene == sceneMap["options"]) // ----------------------------- Options -----------------------------

        {
            if(buttonId == optionsButtonBack.id) // Button Options Back
            {
                if(oldScene == sceneMap["main"])
                {
                    // Start Animations
                    startMainAnimations(false);
                }

                else if(oldScene == sceneMap["gamePause"])
                {
                    // Start Animations
                    startPauseAnimations();
                }
                scene = oldScene;
            }

            else if(buttonId == optionsButtonSite.id) // Button Options Back
            {
                QDesktopServices::openUrl(QUrl("http://coolone.ru/category/projects/"));
            }

            else if(buttonId == optionsButtonCheckUpdates.id) // Button Options Back
            {
                QDesktopServices::openUrl(QUrl("http://coolone.ru/category/projects/games/sword-battle/"));
            }

        }

        else if(scene == sceneMap["shop"]) // ----------------------------- Shop -----------------------------

        {
            if(buttonId == shopButtonUpgrade.id) // Button Update
            {
                // Buy Upgrade / Price
                int price = swords[selectSwordId].price();
                if(coins >= price)
                {
                    // Buy / Upgrade
                    if(swords[selectSwordId].levelSword>0)
                        playSound(shopSoundUpgrade);
                    else
                        playSound(shopSoundBuy);
                    coins -= price;
                    swords[selectSwordId].levelSword++;
                    usedSwordId = selectSwordId;
                }

                shopButtonUse.visible = true;
            }

            else if(buttonId == shopButtonBack.id) // Button Back
            {
                scene = sceneMap["main"];

                // Start Animations
                bool iconsAniamtions = false;
                if(usedSwordId != selectSwordId)
                    iconsAniamtions = true;
                startMainAnimations(iconsAniamtions);
            }

            else if(buttonId == shopButtonUse.id) // Button Use
            {
                if(swords[selectSwordId].levelSword>0)
                {
                    usedSwordId = selectSwordId;
                    playSound(shopSoundUse);
                }
            }

            else if(buttonId == shopButtonLeft.id) // Button Left
            {
                if(selectSwordId<=0)
                {
                    selectSwordId = numberSwords-1;
                }
                else
                {
                    selectSwordId--;
                }

                if(swords[selectSwordId].levelSword > 0)
                {
                    shopButtonUse.visible = true;
                }
                else
                {
                    shopButtonUse.visible = false;
                }
            }

            else if(buttonId == shopButtonRight.id) // Button Right
            {
                if(selectSwordId+1>numberSwords-1)
                {
                    selectSwordId = 0;
                }
                else
                {
                    selectSwordId++;
                }

                if(swords[selectSwordId].levelSword > 0)
                {
                    shopButtonUse.visible = true;
                }
                else
                {
                    shopButtonUse.visible = false;
                }
            }
        }

        else if(scene == sceneMap["mainQExit"]) // ----------------------------- QExit -----------------------------

        {
            if(buttonId == qExitButtonNo.id) // Button QNo
            {
                if(oldScene == sceneMap["main"])
                {
                    // Start Animations
                    startMainAnimations(false);
                }
                else if(oldScene == sceneMap["gamePause"])
                {
                    // Start Animations
                    startPauseAnimations();
                }
                scene = oldScene;
            }

            else if(buttonId == qExitButtonYes.id) // Button QYes
            {
                QApplication::exit();
            }
        }

        // ----------------------------------------------------------------- Game -----------------------------------------------------------------

        else if(scene == sceneMap["gameOptions"]) // ----------------------------- Game Options -----------------------------

        {
            if(buttonId == gameOptionsButtonPlay.id) // Button Options Play
            {
                // Set player sword coords
                playerAnimation.x = moveX;
                playerAnimation.y = moveY;

                // Set sword and sounds Id
                int id;
                if(gameOptionsButtonHard.text == "Easy")
                {
                    id = 0;
                }
                else if(gameOptionsButtonHard.text == "Normal")
                {
                    id = 1;
                }
                else
                {
                    id = 2;
                }

                gameSoundShotsId = id;
                usedEnemySwordId = id;

                // Set combo
                playerCombo = 0;
                enemyCombo = 0;

                // Enemy go attack
                enemyAttack = true;

                playerLeft = true;

                // Set full health
                dEnemyHealth = 100+gameOptionsButtonHard.progressValue*9;

                enemyHealthDAnimation.animation->stop();
                enemyHealth = dEnemyHealth;
                enemyHealthDAnimation.value = enemyHealth;
                playerHealth = dPlayerHealth;
                playerHealthDAnimation.value = playerHealth;

                scene = sceneMap["game"];

                // Start Animations
                startGameAnimations();
            }

            else if(buttonId == gameOptionsButtonMain.id) // Button Play
            {
                scene = sceneMap["gamePause"];
                onClickButton(pauseButtonMain.id);
            }
        }

        else if(scene == sceneMap["game"]) // ----------------------------- Game -----------------------------

        {
            if(buttonId == gameButtonPause.id) // Button Pause
            {
                scene = sceneMap["gamePause"];

                enemyAnimation.pause();

                // Start Animations
                startPauseAnimations();
            }
        }

        else if(scene == sceneMap["gamePause"]) // ----------------------------- Pause -----------------------------

        {
            if(buttonId == pauseButtonExit.id) // Button Pause Exit
            {
                scene = sceneMap["mainQExit"];

                // Start Animations
                startQExitAnimations();
            }

            else if(buttonId == pauseButtonOptions.id) // Button Pause options
            {
                scene = sceneMap["options"];

                // Start Animations
                startOptionsAnimations();
            }

            else if(buttonId == pauseButtonMain.id) // Button Pause Main
            {
                scene = sceneMap["main"];

                // Set Default game values
                enemyAttackSpeed = dEnemyAttackSpeed;
                playerScore = 0;

                // Play Soundtrack
                playSound(mainSoundtrack);

                // Stop Health Bars Aniamtions
                enemyHealthDAnimation.animation->stop();
                playerHealthDAnimation.animation->stop();

                // Set null opasity mask main logo sword
                mainSwordOpasityAnimation.setValue(minOpasitySword);
                mainSwordOpasityAnimation.start();

                // Start Animations
                startMainAnimations();
            }

            else if(buttonId == pauseButtonBack.id) // Button Pause Back
            {
                scene = sceneMap["game"];

                // Start Animations
                enemyAnimation.start(false,false);
                startGameAnimations();
            }
        }
    }
}

void Widget::startMainAnimations(bool iconsAnimations)
{
    // Start Main Animations
    mainButtonPlay.animation.start();
    mainButtonExit.animation.start();
    mainButtonShop.animation.start();
    mainButtonOptions.animation.start();

    if(iconsAnimations)
        startIconsAnimations();
}

void Widget::startIconsAnimations()
{
    iconCoins.animation.start();
    iconDamage.animation.start();
    iconDefense.animation.start();
    iconSpeed.animation.start();
}

void Widget::startQExitAnimations()
{
    // Start QExitAnimations
    qExitButtonNo.animation.start();
    qExitButtonYes.animation.start();
}

void Widget::startOptionsAnimations()
{
    // Start OptionsAnimations
    optionsButtonSoundTrack.animation.start();
    optionsButtonSoundEffects.animation.start();
    optionsButtonBack.animation.start();
    optionsButtonSite.animation.start();
    optionsButtonCheckUpdates.animation.start();
}

void Widget::startGameAnimations()
{
    // Start Game Animations
    gameButtonPause.animation.start();
    playerHealthBarAnimation.start();
    enemyHealthBarAnimation.start();
}

void Widget::startPauseAnimations()
{
    // Start Pause Animations
    pauseButtonBack.animation.start();
    pauseButtonMain.animation.start();
    pauseButtonExit.animation.start();
    pauseButtonOptions.animation.start();
    gameBackgroundMaskPauseAnimation.start();
}

void Widget::startShopAnimations()
{
    // Start Shop Animations
    shopButtonUpgrade.animation.start();
    shopButtonBack.animation.start();
    shopButtonUse.animation.start();
    shopButtonLeft.animation.start();
    shopButtonRight.animation.start();
}

void Widget::startGameOptionsAnimations()
{
    // Start Game Options Animations
    gameOptionsButtonHard.animation.start();
    gameOptionsButtonPlay.animation.start();
    gameOptionsButtonMain.animation.start();

    gameOptionsMaskAnimation.start();
}

void Widget::restartMainSwordOpasityAnimation()
{
    if(mainSwordOpasityAnimation.value == minOpasitySword)
    {
        mainSwordOpasityAnimation.setEndValue(maxOpasitySword);
    }
    else if(mainSwordOpasityAnimation.value == maxOpasitySword)
    {
        mainSwordOpasityAnimation.setEndValue(minOpasitySword);
    }

    mainSwordOpasityAnimation.start(true, false);
}
