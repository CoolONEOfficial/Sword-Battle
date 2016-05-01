#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <QPainter>
#include <QFontDatabase>
#include <QFile>
#include <QTextStream>
#include <QMediaPlaylist>
#include <fstream>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setButtonsWidget();

    ui->setupUi(this);

    showFullScreen();

    setMouseTracking(true);

    setCursor(Qt::BlankCursor);

    ver = "1.8";

    setValues();
    loadAll();
    setAnimations();
    readSave();

    screensaverSmallTextAnimation.start();

    // Timers
    screensaverTimer = new QTimer(this);
    screensaverTimer->setSingleShot(true);
    connect(screensaverTimer, SIGNAL(timeout()), this, SLOT(goFade()));
    screensaverTimer->start(timeScreensaver);

    updateTimer = startTimer(1000/fps);

    playSound(mainSoundtrack);
    playSound(soundTrackStart);
}

Widget::~Widget()
{
    // Save
    writeSave();

    delete ui;
}

void Widget::stopSound(QMediaPlayer *player)
{
    // if no media error
    if( player != 0 )
        if(player->error() == QMediaPlayer::NoError)
        {
            player->stop();
        }
}

void Widget::pauseSound(QMediaPlayer *player)
{
    // if no media error
    if( player != 0 )
        if(player->error() == QMediaPlayer::NoError)
        {
            player->pause();
        }
}

void Widget::playSound(QMediaPlayer *player)
{
    // if no media error
    if( player != 0 )
        if(player->error() == QMediaPlayer::NoError)
        {
            stopSound(player);
            player->play();
        }
}

void Widget::readSave()
{
    //  Read Config
    std::ifstream fileConfig;
    QString fileConfigName("config.cfg");
    fileConfig.open( fileConfigName.toStdString().c_str() ) ;
    if( fileConfig )
    {
        do
        {
            // Config Commands
            std::string command;
            fileConfig>>command;

            if(command == "grand")
            {
                // Set grand
                int grand;
                fileConfig>>grand;
                if(grand<=100 && grand>=0)
                    optionsButtonSoundTrack.setValue(grand);
                else
                    optionsButtonSoundTrack.setValue(100);
            }

            if(command == "sfx")
            {
                // Set SFX
                int sfx;
                fileConfig>>sfx;
                if(sfx<=100 && sfx>=0)
                    optionsButtonSoundEffects.setValue(sfx);
                else
                    optionsButtonSoundEffects.setValue(100);
            }

            if(command == "firstOpen")
            {
                // Set first open
                int firstOpenId;
                fileConfig>>firstOpenId;
                if(firstOpenId == 0)
                    firstOpen = false;
            }

            if(command == "highscore")
            {
                // Set Highscore
                int highscore;
                fileConfig>>highscore;
                if(highscore>0)
                playerHighscore = highscore;
            }

            if(command == "coins")
            {
                // Set Highscore
                int coinsSave;
                fileConfig>>coinsSave;
                if(coinsSave>=0)
                coins = coinsSave;
            }

            if(command == "swordUse")
            {
                // Set swordUse
                int swordUseSave;
                fileConfig>>swordUseSave;
                if(swordUseSave>=0)
                usedSwordId = swordUseSave;
            }

            if(command == "levelSword")
            {
                // Set Level
                int levelSwordSave;
                fileConfig>>levelSwordSave;

                if(levelSwordSave>0)
                {
                    int swordSaveId;
                    fileConfig>>swordSaveId;

                    swords[swordSaveId].levelSword = levelSwordSave;
                }
            }

            if(fileConfig.fail())
            {
                break;
            }
        }while(true);
    } else
    {
        optionsButtonSoundEffects.setValue(100);
        optionsButtonSoundTrack.setValue(100);
        playerHighscore = 0;
    }
    fileConfig.close();

    // Give default sword
    if(swords[0].levelSword < 1)
        swords[0].levelSword = 1;
}

void Widget::writeSave()
{
    // Save config.cfg
    QFile file("config.cfg");
    QTextStream out(&file);
    if(file.open(QIODevice::Truncate | QIODevice::Text | QIODevice::WriteOnly))
    {
        out<<"grand "<<QString::number(volumeGrand);
        endl(out);
        out<<"sfx "<<QString::number(volumeSFX);
        endl(out);
        out<<"highscore "<<QString::number(playerHighscore);
        endl(out);
        out<<"coins  "<<QString::number(coins);
        endl(out);
        out<<"firstOpen 0";
        endl(out);
        out<<"swordUse "+QString::number(usedSwordId);
        endl(out);


        for(int f = 0; f<numberSwords; f++)
        {
            out<<"levelSword "<<QString::number(swords[f].levelSword)<<" "<<f;
            endl(out);
        }
    }
    file.close();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.setRenderHints(QPainter::Antialiasing);

    setCustomCursor();

    if(scene >= sceneMap["game"])
    {
        drawGame(p,scene);
    }

    else if(scene <= sceneMap["main"])
    {
        drawMain(p,scene);
    }

    // Remove media error
    if( soundTrackStart != 0 )
        if(soundTrackStart->error() != QMediaPlayer::NoError)
        {
            delete soundTrackStart;
            soundTrackStart = 0;
        }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    clicked = false;

    releaseX = event->x();
    releaseY = event->y();

    // ----------------------------------------------------------------- Main Scene -----------------------------------------------------------------
    if(screensaverEnd())
    {
        if(scene == sceneMap["main"])
        {
            // Play Button
            if(mainButtonPlay.inside(releaseX,releaseY) &&
                    mainButtonPlay.inside(clickX, clickY))
            {
                onClickButton(mainButtonPlay.id);
            }

            // Exit Button
            else if(mainButtonExit.inside(releaseX, releaseY) &&
                    mainButtonExit.inside(clickX, clickY))
            {
                onClickButton(mainButtonExit.id);
            }
            // Options Button
            else if(mainButtonOptions.inside(releaseX, releaseY) &&
                    mainButtonOptions.inside(clickX, clickY))
            {
                onClickButton(mainButtonOptions.id);
            }
            // Shop Button
            else if(mainButtonShop.inside(releaseX, releaseY) &&
                    mainButtonShop.inside(clickX, clickY))
            {
                onClickButton(mainButtonShop.id);
            }
        }
        // ----------------------------------------------------------------- Options Scene -----------------------------------------------------------------
        else if(scene == sceneMap["options"])
        {
            // options back Button
            if(optionsButtonBack.inside(releaseX, releaseY) &&
                    optionsButtonBack.inside(clickX, clickY))
            {
                onClickButton(optionsButtonBack.id);
            }
            // options check updates Button
            else if(optionsButtonCheckUpdates.inside(releaseX, releaseY) &&
                    optionsButtonCheckUpdates.inside(clickX, clickY))
            {
                onClickButton(optionsButtonCheckUpdates.id);
            }
            // options site Button
            else if(optionsButtonSite.inside(releaseX, releaseY) &&
                    optionsButtonSite.inside(clickX, clickY))
            {
                onClickButton(optionsButtonSite.id);
            }
        }
        // ----------------------------------------------------------------- Shop Scene -----------------------------------------------------------------
        else if(scene == sceneMap["shop"])
        {
            // Shop Update Button
            if(shopButtonUpgrade.inside(releaseX, releaseY) &&
                    shopButtonUpgrade.inside(clickX, clickY))
            {
                onClickButton(shopButtonUpgrade.id);
            }
            else if(shopButtonBack.inside(releaseX, releaseY) &&
                        shopButtonBack.inside(clickX, clickY))
            {
                onClickButton(shopButtonBack.id);
            }
            else if(shopButtonUse.inside(releaseX, releaseY) &&
                        shopButtonUse.inside(clickX, clickY))
            {
                onClickButton(shopButtonUse.id);
            }
            else if(shopButtonLeft.inside(releaseX, releaseY) &&
                        shopButtonLeft.inside(clickX, clickY))
            {
                onClickButton(shopButtonLeft.id);
            }
            else if(shopButtonRight.inside(releaseX, releaseY) &&
                        shopButtonRight.inside(clickX, clickY))
            {
                onClickButton(shopButtonRight.id);
            }
        }
        // ----------------------------------------------------------------- QExit Scene -----------------------------------------------------------------
        else if(scene == sceneMap["mainQExit"])
        {
            // QNo Button
            if(qExitButtonNo.inside(releaseX, releaseY) &&
                    qExitButtonNo.inside(clickX, clickY))
            {
                onClickButton(qExitButtonNo.id);
            }

            // QYes Button
            else if(qExitButtonYes.inside(releaseX, releaseY) &&
                    qExitButtonYes.inside(clickX, clickY))
            {
                onClickButton(qExitButtonYes.id);
            }
        }

        // ----------------------------------------------------------------- Game Scene -----------------------------------------------------------------
        else if(scene == sceneMap["game"])
        {
            // Pause Button
            if(gameButtonPause.inside(releaseX, releaseY) &&
                    gameButtonPause.inside(clickX, clickY))
            {
                onClickButton(gameButtonPause.id);
            }
            else
            {
                // Magic

            }
        }

        // ----------------------------------------------------------------- Game Options Scene -----------------------------------------------------------------
        else if(scene == sceneMap["gameOptions"])
        {
            // Pause Button
            if(gameOptionsButtonPlay.inside(releaseX, releaseY) &&
                    gameOptionsButtonPlay.inside(clickX, clickY))
            {
                onClickButton(gameOptionsButtonPlay.id);
            }

            // Pause Button
            else if(gameOptionsButtonMain.inside(releaseX, releaseY) &&
                    gameOptionsButtonMain.inside(clickX, clickY))
            {
                onClickButton(gameOptionsButtonMain.id);
            }
        }

        // ----------------------------------------------------------------- Game Pause Scene -----------------------------------------------------------------
        else if(scene == sceneMap["gamePause"])
        {
        // Pause options Button
            if(pauseButtonOptions.inside(releaseX, releaseY) &&
                    pauseButtonOptions.inside(clickX, clickY))
            {
                onClickButton(pauseButtonOptions.id);
            }

        // Pause Exit Button
            else if(pauseButtonExit.inside(releaseX, releaseY) &&
                    pauseButtonExit.inside(clickX, clickY))
            {
                onClickButton(pauseButtonExit.id);
            }

        // Pause Main Button
            else if(pauseButtonMain.inside(releaseX, releaseY) &&
                    pauseButtonMain.inside(clickX, clickY))
            {
                onClickButton(pauseButtonMain.id);
            }

        // Pause Back Button
            else if(pauseButtonBack.inside(releaseX, releaseY) &&
                    pauseButtonBack.inside(clickX, clickY))
            {
                onClickButton(pauseButtonBack.id);
            }
        }
    }
    else
    {
        if(!firstOpen)
        goFade();
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    clicked = true;

    // Set click coords
    clickX = event->x();
    clickY = event->y();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    // Set X and Y
    moveX = event->x();
    moveY = event->y();

    if(scene == sceneMap["game"])
    {
        playerAnimation.stop();
        playerAnimation.setEndX(moveX);
        playerAnimation.setEndY(moveY);
        playerAnimation.start(false, false);

        // Old X and Y
        for(int f = 1; f<oldPlayerXCoordinates; f++)
        {
            oldPlayerX[f-1] = oldPlayerX[f];
        }

        for(int f = 1; f<oldPlayerYCoordinates; f++)
        {
            oldPlayerY[f-1] = oldPlayerY[f];
        }

        oldPlayerX[oldPlayerXCoordinates-1] = playerAnimation.x;
        oldPlayerY[oldPlayerYCoordinates-1] = playerAnimation.y;

        // Set Speed
        playerSpeed = (abs(playerAnimation.x - oldPlayerX[oldPlayerXCoordinates-3]) +
                               abs(playerAnimation.y - oldPlayerY[oldPlayerYCoordinates-3]))/2;

        if(enemyAttack)
        {
            if(playerLeft)
            {
                enemyAnimation.setEndX(playerAnimation.x+swords[usedSwordId].sword.width()/2);
            }
            else
            {
                enemyAnimation.setEndX(playerAnimation.x-swords[usedSwordId].sword.width()/2);
            }
            enemyAnimation.setEndY(playerAnimation.y);

            enemyAnimation.start(false,false);
        }
        connect(enemyAnimation.animationX, SIGNAL(finished()), this, SLOT(enemyShot()));
        connect(enemyAnimation.animationY, SIGNAL(finished()), this, SLOT(enemyShot()));

        if(playerAnimation.x < enemyAnimation.x-enemySwords[usedEnemySwordId].sword.width()*1.2 ||
                playerAnimation.x < width()/8)
        {
             playerLeft = true;
        }
        else if(playerAnimation.x > enemyAnimation.x+enemySwords[usedEnemySwordId].sword.width()*1.2 ||
                playerAnimation.x > width()-width()/8)
        {
             playerLeft = false;
        }

        setMatrixPlayer();
        setMatrixEnemy();
    }

    if(screensaverEnd())
    {
        // Set Cursor
        if(clicked)
        {
            // Set ProgressButtons Values
            if(scene == sceneMap["options"])
            {        
                setButtonProgressValue(optionsButtonSoundTrack);

                setButtonProgressValue(optionsButtonSoundEffects);
            }
            else if(scene == sceneMap["gameOptions"])
            {
                setButtonProgressValue(gameOptionsButtonHard);

                if(gameOptionsButtonHard.progressValue <= 20)
                {
                    gameOptionsButtonHard.setText("Easy");
                }
                else if(gameOptionsButtonHard.progressValue > 20 &&
                        gameOptionsButtonHard.progressValue <= 40)
                {
                    gameOptionsButtonHard.setText("Normal");
                }
                else if(gameOptionsButtonHard.progressValue > 40 &&
                        gameOptionsButtonHard.progressValue <= 60)
                {
                    gameOptionsButtonHard.setText("Medium");
                }
                else if(gameOptionsButtonHard.progressValue > 60 &&
                        gameOptionsButtonHard.progressValue <= 80)
                {
                    gameOptionsButtonHard.setText("Hard");
                }
                if(gameOptionsButtonHard.progressValue > 80)
                {
                   gameOptionsButtonHard.setText("Hardcore");
                }
            }
        }
    }
}

void Widget::setButtonProgressValue(ButtonProgress &button)
{
    if(button.inside(moveX,moveY))
    {
        int val = ((moveX-button.animation.x)*100)/button.width();

        if( val < 0 ) val = 0;
        else if( val > 100 ) val = 100;

        if(button.rightDir)
            button.setValue(val);
        else
            button.setValue(100-val);
    }
}

void Widget::setButtonsWidget()
{    
    // Swords
    for(int f = 0; f<numberSwords; f++)
    {
        swords[f].setWidget(this);
    }

    enemySwords[0].setWidget(this);
    enemySwords[1].setWidget(this);
    enemySwords[2].setWidget(this);

    // Icons
    iconPrice.setWidget(this);
    iconDefense.setWidget(this);
    iconDamage.setWidget(this);
    iconCoins.setWidget(this);
    iconSpeed.setWidget(this);

    // Buttons
    mainButtonPlay.setWidget(this);
        gameButtonPause.setWidget(this);
            pauseButtonExit.setWidget(this);
            pauseButtonMain.setWidget(this);
            pauseButtonOptions.setWidget(this);
            pauseButtonBack.setWidget(this);

        gameOptionsButtonHard.setWidget(this);
        gameOptionsButtonPlay.setWidget(this);
        gameOptionsButtonMain.setWidget(this);

    mainButtonExit.setWidget(this);
        qExitButtonNo.setWidget(this);
        qExitButtonYes.setWidget(this);

    mainButtonShop.setWidget(this);
        shopButtonUpgrade.setWidget(this);
        shopButtonBack.setWidget(this);
        shopButtonUse.setWidget(this);
        shopButtonLeft.setWidget(this);
        shopButtonRight.setWidget(this);

    mainButtonOptions.setWidget(this);
        optionsButtonSoundTrack.setWidget(this);
        optionsButtonSoundEffects.setWidget(this);
        optionsButtonBack.setWidget(this);
        optionsButtonCheckUpdates.setWidget(this);
        optionsButtonSite.setWidget(this);
}

void Widget::loadAll()
{
    // Icons
    iconCoins.load("coins");
    iconDamage.load("damage");
    iconDefense.load("defence");
    iconPrice.load("price");
    iconSpeed.load("speed");

    // Fonts
    loadFont(fontVagtur,"vagtur.ttf");
    loadFont(fontAxis,"axis.otf");
    loadFont(fontRounds,"rounds.otf");
    loadFont(fontArista,"arista.ttf");
    loadFont(fontProjects,"projects.ttf");

    // Cursors
    cursorBlank = Qt::BlankCursor;
    loadCursor(cursor,"cursor.png");
    loadCursor(cursorHand,"cursorhand.png");
    loadCursor(cursorCHand,"cursorchand.png");

    // ----------------------------------------------------------------- Buttons -----------------------------------------------------------------

    mainButtonPlay.load("green");
        gameButtonPause.load("pause");
            pauseButtonExit.load("red");
            pauseButtonMain.load("white");
            pauseButtonBack.load("green");
            pauseButtonOptions.load("white");

        gameOptionsButtonHard.load();
        gameOptionsButtonPlay.load("green");
        gameOptionsButtonMain.load("white");

    mainButtonShop.load("white");
        shopButtonUpgrade.load("white");
        shopButtonBack.load("green");
        shopButtonUse.load("white");
        shopButtonLeft.load("left");
        shopButtonRight.load("right");

    mainButtonOptions.load("white");
        optionsButtonSoundTrack.load();
        optionsButtonSoundEffects.load();
        optionsButtonBack.load("white");
        optionsButtonSite.load("white");
        optionsButtonCheckUpdates.load("white");

    mainButtonExit.load("white");
        qExitButtonNo.load("white");
        qExitButtonYes.load("white");

    // ----------------------------------------------------------------- Game -----------------------------------------------------------------

    // Player Swords
    swords[0].load("sword");
    swords[0].dPrice = 5;
    swords[0].setSpeed(30);
    swords[0].dDamage = 3;
    swords[0].dDefence = 1;

    swords[1].load("smallsword");
    swords[1].dPrice = 25;
    swords[1].setSpeed(70);
    swords[1].dDamage = 5;
    swords[1].dDefence = 5;

    swords[2].load("backsword");
    swords[2].dPrice = 50;
    swords[2].setSpeed(10);
    swords[2].dDamage = 20;
    swords[2].dDefence = 10;

    swords[3].load("ax");
    swords[3].dPrice = 150;
    swords[3].setSpeed(10);
    swords[3].dDamage = 25;
    swords[3].dDefence = 15;

    swords[4].load("katana");
    swords[4].dPrice = 300;
    swords[4].setSpeed(80);
    swords[4].dDamage = 5;
    swords[4].dDefence = 5;

    swords[5].load("mace");
    swords[5].dPrice = 500;
    swords[5].setSpeed(20);
    swords[5].dDamage = 25;
    swords[5].dDefence = 25;

    swords[6].load("trident");
    swords[6].dPrice = 750;
    swords[6].setSpeed(30);
    swords[6].dDamage = 15;
    swords[6].dDefence = 10;

    swords[7].load("rune");
    swords[7].dPrice = 1000;
    swords[7].setSpeed(30);
    swords[7].dDamage = 15;
    swords[7].dDefence = 8;

    swords[8].load("stalhrim");
    swords[8].dPrice = 5000;
    swords[8].setSpeed(40);
    swords[8].dDamage = 20;
    swords[8].dDefence = 10;

    swords[9].load("daedric");
    swords[9].dPrice = 8000;
    swords[9].setSpeed(90);
    swords[9].dDamage = 25;
    swords[9].dDefence = 30;

    // Enemy Swords
    enemySwords[0].load("easy", false);

    enemySwords[1].load("normal", false);

    enemySwords[2].load("default", false);

    // Backgrounds
    loadImage(gameBackground,"game\\backgrounds\\gamebackground1.png");

    // Player Bars
    loadImage(playerHealthBarIcon,"game\\player\\bars\\health\\icon\\icon.png");
    loadImage(playerHealthBarIconMask,"game\\player\\bars\\health\\icon\\mask.png");
    loadImage(playerHealthBarUp,"game\\player\\bars\\health\\playerhealthbarup.png");
    loadImage(playerHealthBarDown,"game\\player\\bars\\health\\playerhealthbardown.png");
    loadImage(playerHealthBarImg,"game\\player\\bars\\health\\playerhealth.png");
    loadImage(playerHealthBarDImg,"game\\player\\bars\\health\\playerhealthd.png");

    // Enemy Bars
    loadImage(enemyHealthBarIcon,"game\\enemy\\bars\\health\\icon\\icon.png");
    loadImage(enemyHealthBarIconMask,"game\\enemy\\bars\\health\\icon\\mask.png");
    loadImage(enemyHealthBarUp,"game\\enemy\\bars\\health\\enemyhealthbarup.png");
    loadImage(enemyHealthBarDown,"game\\enemy\\bars\\health\\enemyhealthbardown.png");
    loadImage(enemyHealthBarImg,"game\\enemy\\bars\\health\\enemyhealth.png");
    loadImage(enemyHealthBarDImg,"game\\enemy\\bars\\health\\enemyhealthd.png");

    // Background Texture
    loadImage(mainBackgroundTexture, "main\\textures\\mainbackgroundtexture.png");

    // Sounds
    buttonSoundClick = loadSound("buttons\\click\\click.mp3");

    mainSoundtrack = loadSound("main\\soundtrack\\soundtrackbattle.mp3");

    soundTrackStart = new QMediaPlayer;
    soundtrackPlaylist = new QMediaPlaylist;

    soundtrackPlaylist->addMedia(QUrl::fromLocalFile(baseDir+"\\sounds\\main\\soundtrack\\soundtrackstart.mp3"));

    for(int f = 0; f<mainSoundTracksNumber; f++)
    {
        if(!soundtrackPlaylist->addMedia(QUrl::fromLocalFile(baseDir+"\\sounds\\game\\shot\\sword\\"+QString::number(f+1)+".mp3")))
        {
            QMessageBox::information(this, "Can' load media", baseDir+"\\sounds\\main\\soundtrack\\soundtrack"+QString::number(f+1)+".mp3");
        }
    }

    soundtrackPlaylist->setCurrentIndex(1);
    soundTrackStart->setPlaylist(soundtrackPlaylist);
    soundtrackPlaylist->setPlaybackMode(QMediaPlaylist::Loop);

    gameSoundStartBattle = loadSound("game\\startbattle\\startbattle.mp3");
    gameSoundEndBattle = loadSound("game\\endbattle\\endbattle.mp3");

    shopSoundUpgrade = loadSound("shop\\upgrade\\upgrade.mp3");
    shopSoundBuy = loadSound("shop\\buy\\buy.mp3");
    shopSoundUse = loadSound("shop\\use\\use.mp3");

    for(int num = 0; num<gameSoundShotsNumber; num++)
    { // Load Sound shots sword
        gameSoundShot[0][num] = loadSound("game\\shot\\easy\\"+QString::number(num+1)+".mp3");
    }   

    for(int num = 0; num<gameSoundShotsNumber; num++)
    { // Load Sound shots sword
        gameSoundShot[1][num] = loadSound("game\\shot\\normal\\"+QString::number(num+1)+".mp3");
    }

    for(int num = 0; num<gameSoundShotsNumber; num++)
    { // Load Sound shots sword
        gameSoundShot[2][num] = loadSound("game\\shot\\default\\"+QString::number(num+1)+".mp3");
    }
}

void Widget::loadImage(QImage &image, const QString &imagePath)
{
    if( !image.load(baseDir+"\\sprites\\"+imagePath))
    {
        QMessageBox::information(this,"Error load image",imagePath);
    }
}

void Widget::loadFont(QFont &font, const QString &name)
{
    int fontId;
    // Set path
    fontId = QFontDatabase::addApplicationFont(baseDir+"\\fonts\\"+name);

    if (fontId != -1)  // No load Fail?
    {
        font.setFamily(QFontDatabase::applicationFontFamilies(fontId).first());
    } else
    {
        QMessageBox::information(this, "Error load font "+name, name);
    }
}

void Widget::loadCursor(QCursor &cursor, const QString &name)
{
    cursor = QCursor(QPixmap(baseDir+"\\sprites\\cursors\\"+name));
}

QMediaPlayer* Widget::loadSound(const QString &soundPath)
{
    QMediaPlayer *mediaPlayer = new QMediaPlayer;
    mediaPlayer->setMedia(QUrl::fromLocalFile(baseDir+"\\sounds\\"+soundPath));
    if(mediaPlayer->error() != mediaPlayer->NoError )
    {
        QMessageBox::information(this,"Error load sound",soundPath);
    }
    return mediaPlayer;
}

QRect Widget::rectCenter(QRect rect, int width, int height)
{
    float scaleX = rect.width() / static_cast<float>(width);

    int newHeight = height*scaleX;

    int shiftY = (rect.height() - newHeight) / 2;

    return QRect(rect.x(), rect.y()+shiftY, rect.width(), newHeight);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == updateTimer)
    {
        update();
    }
}

void Widget::setMatrixPlayer()
{
    if(!playerLeft)
    {
        matrixPlayer.reset();
        matrixPlayer.setMatrix(-1,0, 0,1, 0,0);
    }
    else
    {
        matrixPlayer.reset();
    }
}

void Widget::setMatrixEnemy()
{
    if(!playerLeft)
    {
        matrixEnemy.reset();
        matrixEnemy.setMatrix(-1,0, 0,1, 0,0);
    }
    else
    {
        matrixEnemy.reset();
    }
}

void Widget::enemyShot()
{
    if(enemyAnimation.animationX->state() == QPropertyAnimation::Stopped  &&
       enemyAnimation.animationY->state() == QPropertyAnimation::Stopped)
    {
        if(enemyAttack) // If enemy attack
        {
            if(playerLeft)
            {
                enemyAnimation.setEndX(enemyAnimation.dX);
            }
            else
            {
                enemyAnimation.setEndX(width()-enemyAnimation.dX);
            }
            enemyAnimation.setEndY(enemyAnimation.dY);
        }
        else // Else goto player coords
        {
            enemyAnimation.setDuration(enemyAttackSpeed-enemyAttackSpeedRand+(rand()%(enemyAttackSpeedRand*2)));
            if(playerLeft)
            {
                enemyAnimation.setEndX(playerAnimation.x+swords[usedSwordId].sword.width()/2);
            }
            else
            {
                enemyAnimation.setEndX(playerAnimation.x-swords[usedSwordId].sword.width()/2);
            }
            enemyAnimation.setEndY(playerAnimation.y);
        }
        enemyAnimation.start(false,false);

        enemyAttack = !enemyAttack;
    }
}

bool Widget::screensaverEnd()
{
    if(opasityScreensaverAnimation.value == opasityScreensaverAnimation.animation->endValue())
        return 1;
    else return 0;
}

void Widget::setValues()
{
    // Path to current project
    baseDir = QApplication::applicationDirPath();

    dPlayerHealth = 100;
    dEnemyHealth = 100;

    // Set Coins
    coins = 0;

    // Set select sword (shop)
    selectSwordId = 0;

    // Set used swords (logo and game)
    usedSwordId = 0;
    usedEnemySwordId = 0;

    gameSoundShotsId = 0;

    // Set player scores
    playerHighscore = 0;
    playerScore = 0;

    // Set Combo
    playerCombo = 2;
    enemyCombo = 0;

    volumeGrand = 100;
    volumeSFX = 100;

    // Set enemy attack speed
    dEnemyAttackSpeed = 300;
    enemyAttackSpeed = dEnemyAttackSpeed;
    enemyAttackSpeedRand = 100;

    // Set default enemy coords
    enemyAnimation.dX = width()/10*7;
    enemyAnimation.dY = height()/3*2;
    enemyAnimation.x = enemyAnimation.dX;
    enemyAnimation.y = enemyAnimation.dY;

    // Button map
    mainButtonPlay.id= 1;
        gameButtonPause.id = 2;
            pauseButtonBack.id = 3;
            pauseButtonOptions.id = 4;
            pauseButtonMain.id = 5;
            pauseButtonExit.id = 6;

        gameOptionsButtonHard.id = 7;
        gameOptionsButtonPlay.id = 8;

    mainButtonExit.id = 9;
        qExitButtonNo.id= 10;
        qExitButtonYes.id = 11;

    mainButtonShop.id = 12;
        shopButtonUpgrade.id = 13;
        shopButtonBack.id = 14;
        shopButtonUse.id = 15;
        shopButtonLeft.id = 16;
        shopButtonRight.id = 17;

    mainButtonOptions.id = 18;
        optionsButtonSoundEffects.id = 19;
        optionsButtonSoundTrack.id = 20;
        optionsButtonBack.id = 21;
        optionsButtonSite.id = 22;
        optionsButtonCheckUpdates.id = 23;

    // Button map
    buttonMap["mainOptionsGrand"] = 0;
    buttonMap["mainOptionsSFX"] = 1;

    // Scene map
    sceneMap["shop"] = -4;
    sceneMap["options"] = -3;
    sceneMap["mainQExit"] = -2;
    sceneMap["main"] = -1;

    sceneMap["game"] = 1;
    sceneMap["gamePause"] = 2;
    sceneMap["gameOptions"] = 3;

    // State Map
    stateMap["passive"] = 0;
    stateMap["move"] = 1;
    stateMap["click"] = 2;

    //Scene
    scene = sceneMap["main"];
    oldScene = scene;

    //Bools
    firstOpen = true;
    clicked = false;
    attack = false;
    upLayer = true;
    inButton = false;

    // Sound Shot Random Number
    swordSoundNumber = rand()%(gameSoundShotsNumber-1);
    oldSwordSoundNumber = swordSoundNumber;

    // Zeroing
    moveX = 0;
    moveY = 0;
    releaseX = 0;
    releaseY = 0;
    clickX = 0;
    clickY = 0;
    playerSpeed = 0;
    enemySpeed = 0;
    playerAngle = 0;
    enemyAngle = 0;

    for(int f = 0; f<oldPlayerXCoordinates; f++)
        oldPlayerX[f] = 0;
    for(int f = 0; f<oldPlayerYCoordinates; f++)
        oldPlayerY[f] = 0;

    for(int f = 0; f<oldEnemyXCoordinates; f++)
        oldEnemyX[f] = 0;
    for(int f = 0; f<oldEnemyYCoordinates; f++)
        oldEnemyY[f] = 0;

    // Health
    playerHealth = dPlayerHealth;
    enemyHealth = dEnemyHealth;
    playerHealthDAnimation.value = playerHealth;

    // Texts
    mainScreensaverSmallText = "presents";

    // Buttons Texts
    mainButtonPlay.text = "Play";
        pauseButtonExit.text = "Exit";
        pauseButtonMain.text = "Main";
        pauseButtonBack.text = "Back";
        pauseButtonOptions.text = "Options";

        gameOptionsButtonHard.text = "Difficulty";
        gameOptionsButtonPlay.text = "Play";
        gameOptionsButtonMain.text = "Main";

    mainButtonExit.text = "Exit";
        qExitButtonNo.text = "No";
        qExitButtonYes.text = "Yes";
        mainQConfirmText = "Really?";

    mainButtonShop.text = "Shop";
        shopButtonUpgrade.text = "Upgrade";
        shopButtonBack.text = "Back";
        shopButtonUse.text = "Use";

    mainButtonOptions.text = "Options";
        optionsButtonBack.text = "Back";
        optionsButtonCheckUpdates.text = "Check Updates";
        optionsButtonSite.text = "Other Games";
        optionsButtonSoundTrack.text = "Soundtrack";
        optionsButtonSoundEffects.text = "Effects";

    // Colors
    colorNone.setAlpha(0);
    whiteBrownLogo.setRgb(225,223,180);
    whiteBrown.setRgb(221,180,152);
    brown.setRgb(116,52,8);
}

void Widget::checkAttack()
{
   // Old X and Y
   for(int f = 1; f<oldEnemyXCoordinates; f++)
   {
       oldEnemyX[f-1] = oldEnemyX[f];
   }

   for(int f = 1; f<oldEnemyYCoordinates; f++)
   {
       oldEnemyY[f-1] = oldEnemyY[f];
   }

   oldEnemyX[oldEnemyXCoordinates-1] = enemyAnimation.x;
   oldEnemyY[oldEnemyYCoordinates-1] = enemyAnimation.y;

   // Set Speed
   enemySpeed = (abs(enemyAnimation.x - oldEnemyX[oldEnemyXCoordinates-2]) +
                           abs(enemyAnimation.y - oldEnemyY[oldEnemyYCoordinates-2]))/2;

   // Attack
   if(enemyAnimation.x+enemySwords[usedEnemySwordId].sword.width() > playerAnimation.x &&
       enemyAnimation.x < playerAnimation.x+swords[usedSwordId].sword.width() &&
       enemyAnimation.y+enemySwords[usedEnemySwordId].sword.height() > playerAnimation.y &&
       enemyAnimation.y < playerAnimation.y+swords[usedSwordId].sword.height())
   {
       if(!attack)
       {
           playSwordShot();

           // Change Layer
           attack = true;

           if(enemySpeed>playerSpeed)
           {
               int damage = (enemySpeed*(gameOptionsButtonHard.progressValue/100.0)+enemyCombo/2.0)
                       /100.0*(100-swords[usedSwordId].defence());

               if(damage > 0)
               {
                   if(playerHealthDAnimation.value > damage)
                   {
                       // Damage
                       playerHealth -= damage;

                       // Set Combo
                       enemyCombo++;
                       playerCombo = 0;
                   }
                   else
                   {
                       // Player Died

                       // Set Default Player Values
                       playerHealth = dPlayerHealth;
                       playerHealthDAnimation.value = playerHealth;
                       enemyAttackSpeed = dEnemyAttackSpeed;
                       // Set Score
                       playerScore = 0;
                       // Play Sound
                       playSound(gameSoundEndBattle);
                       // Stop Enemy
                       enemyAnimation.stop();

                       // Set scene
                       scene = sceneMap["main"];
                       onClickButton(mainButtonPlay.id);

                       // Set Text
                       gameOptionsText = "You lose";
                   }
               }

               // HealthD Animation
               playerHealthDAnimation.animation->stop();
               playerHealthDAnimation.animation->setEndValue(playerHealth);
               playerHealthDAnimation.animation->start();
           }
           else if(playerSpeed>enemySpeed)
           {
               int damage = swords[usedSwordId].damage()*(playerSpeed/20.0);

               if(enemyHealthDAnimation.value>damage)
               {
                   // Damage
                   enemyHealth -= damage;

                   // Set Combo
                   playerCombo++;
                   enemyCombo = 0;
               }
               else
               {
                   // Enemy Died

                   // Set Default Enemy Values
                   enemyAnimation.reset();
                   enemyHealth = dEnemyHealth;
                   enemyHealthDAnimation.value = enemyHealth;
                   // Enemy "angry"
                   enemyAttackSpeed -= enemyAttackSpeed/10;
                   // Score
                   playerScore++;
                   // Give Coins
                   if(gameOptionsButtonHard.progressValue>0)
                       coins += 1+gameOptionsButtonHard.progressValue/15;
                   // Set Highscore
                   if(playerScore>playerHighscore)
                       playerHighscore = playerScore;
                   // Play Sound
                   playSound(gameSoundEndBattle);
                }

               // HealthD Animation
               enemyHealthDAnimation.animation->stop();
               enemyHealthDAnimation.animation->setEndValue(enemyHealth);
               enemyHealthDAnimation.animation->start();
           }
       }
   }
   else
   {
       attack = false;
       upLayer = !upLayer;
   }
}

void Widget::setVolume(int butttonId)
{
    if( soundTrackStart != 0 )
        if(soundTrackStart->error() == QMediaPlayer::NoError)
        {
            // Set Volumes
            if(butttonId == optionsButtonSoundTrack.id)
            { // Set volumeGrand
                volumeGrand = optionsButtonSoundTrack.progressValue;
                mainSoundtrack->setVolume(volumeGrand);
                soundTrackStart->setVolume(volumeGrand);
            }
            else if(butttonId == optionsButtonSoundEffects.id)
            { // Set volumeSFX
                volumeSFX = optionsButtonSoundEffects.progressValue;
                buttonSoundClick->setVolume(volumeSFX);
                gameSoundStartBattle->setVolume(volumeSFX);
                gameSoundEndBattle->setVolume(volumeSFX);
                shopSoundBuy->setVolume(volumeSFX);
                shopSoundUpgrade->setVolume(volumeSFX);
                shopSoundUse->setVolume(volumeSFX);
                for(int num = 0; num<gameSoundShotsNumber; num++)
                {
                    gameSoundShot[0][num]->setVolume(volumeSFX);
                    gameSoundShot[1][num]->setVolume(volumeSFX);
                    gameSoundShot[2][num]->setVolume(volumeSFX);
                }
            }
        }
}

void Widget::setCursorInsideButton(QCursor &inCursor, QCursor &outCursor, int cursorX, int cursorY)
{
    if(scene == sceneMap["main"])
    {
        if(mainButtonExit.inside(cursorX, cursorY) ||
                mainButtonPlay.inside(cursorX, cursorY) ||
                mainButtonOptions.inside(cursorX, cursorY) ||
                mainButtonShop.inside(cursorX, cursorY))
        {
            setCursor(inCursor);
        }
        else
        {
            setCursor(outCursor);
        }
    }
    else if(scene == sceneMap["options"])
    {
        if(optionsButtonSoundTrack.inside(cursorX, cursorY) ||
                optionsButtonSoundEffects.inside(cursorX, cursorY) ||
                optionsButtonBack.inside(cursorX, cursorY) ||
                optionsButtonCheckUpdates.inside(cursorX, cursorY) ||
                optionsButtonSite.inside(cursorX, cursorY))
        {
            setCursor(inCursor);
        }
        else
        {
            setCursor(outCursor);
        }
    }
    else if(scene == sceneMap["shop"])
    {
        if(shopButtonUpgrade.inside(cursorX, cursorY) ||
                shopButtonBack.inside(cursorX,cursorY) ||
                shopButtonUse.inside(cursorX,cursorY) ||
                shopButtonLeft.inside(cursorX,cursorY) ||
                shopButtonRight.inside(cursorX,cursorY))
        {
            setCursor(inCursor);
        }
        else
        {
            setCursor(outCursor);
        }
    }
    else if(scene == sceneMap["mainQExit"])
    {
        if(qExitButtonNo.inside(cursorX, cursorY) ||
                qExitButtonYes.inside(cursorX, cursorY))
        {
            setCursor(inCursor);
        }
        else
        {
            setCursor(outCursor);
        }
    }
    else if(scene == sceneMap["game"])
    {
        if(gameButtonPause.inside(cursorX, cursorY))
        {
            setCursor(inCursor);
        }
        else
        {
            setCursor(outCursor);
        }
    }
    else if(scene == sceneMap["gameOptions"])
    {
        if(gameOptionsButtonHard.inside(cursorX, cursorY) ||
                gameOptionsButtonPlay.inside(cursorX, cursorY) ||
                gameOptionsButtonMain.inside(cursorX, cursorY))
        {
            setCursor(inCursor);
        }
        else
        {
            setCursor(outCursor);
        }
    }
    else if(scene == sceneMap["gamePause"])
    {
        if(pauseButtonBack.inside(cursorX, cursorY) ||
                pauseButtonMain.inside(cursorX, cursorY) ||
                pauseButtonExit.inside(cursorX, cursorY) ||
                pauseButtonOptions.inside(cursorX, cursorY))
        {
            setCursor(inCursor);
        }
        else
        {
            setCursor(outCursor);
        }
    }
}

void Widget::setCustomCursor()
{
    if(screensaverEnd())
    {
        if(scene == sceneMap["game"])
        {
            setCursorInsideButton(cursorHand, cursorBlank, moveX, moveY);
        }
        else
        {
            setCursorInsideButton(cursorHand, cursor, moveX, moveY);
        }

        if(clicked)
        {
            setCursorInsideButton(cursorCHand, cursor, moveX, moveY);
        }
    }
}

void Widget::playSwordShot()
{
    // Play Random Sound Shot Sword
    do
    { swordSoundNumber = rand()%(gameSoundShotsNumber-1); }
    while(swordSoundNumber == oldSwordSoundNumber);
    gameSoundShot[gameSoundShotsId][swordSoundNumber]->stop();
    playSound(gameSoundShot[gameSoundShotsId][swordSoundNumber]);
}
