#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "button.h"
#include "buttonprogress.h"
#include "animation.h"
#include "animationcoords.h"
#include "sword.h"
#include "icon.h"

#include <QPropertyAnimation>
#include <QPainter>
#include <QKeyEvent>
#include <QMap>
#include <QMediaPlayer>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget;

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent = 0);
   ~Widget();

   // Version
   QString ver;

   // Coins
   int coins;

   // Player Score
   int playerScore;
   int playerHighscore;

   // Player Combo
   int playerCombo;
   int enemyCombo;

   // Speed Enemy Attack
   int dEnemyAttackSpeed;
   int enemyAttackSpeed;
   int enemyAttackSpeedRand;

   // Health
   int dPlayerHealth;
   int dEnemyHealth;

   int volumeGrand;
   int volumeSFX;

   static const int numberSwords = 10;

   // Indents
   static const int mainIndentX = 15;
   static const int mainIndentY = 15;
   static const int gameIndentX = 15;
   static const int gameIndentY = 15;

   // Main Opasity Sword
   static const int minOpasitySword = 100;
   static const int maxOpasitySword = 500;

   // Sounds Number Sword Shot
   static const int gameSoundShotsNumber = 5;
   static const int mainSoundTracksNumber = 1;

   // StateMap
   QMap<QString, int> stateMap;

   // Button Ids
   QMap<QString, int> buttonMap;

   // Scenes Ids
   QMap<QString,int> sceneMap;

   // Damage
   static const float dDamageScale = 0.15;

   // Speed Animations
   static const float speedButtonsAnimation = 1250;
   static const int speedEnemy = 2000;

   // Screensaver
   static const int timeScreensaver = 13200;
   QTimer *screensaverTimer;
   bool screensaverEnd();

   // Update timer
   int updateTimer;
   static const int fps = 60;

   // Matrix
   QMatrix matrixEnemy, matrixPlayer;

   // Buttons
   Button mainButtonPlay;
       Button gameButtonPause;
           Button pauseButtonBack;
           Button pauseButtonExit;
           Button pauseButtonMain;
           Button pauseButtonOptions;

       ButtonProgress gameOptionsButtonHard;
       Button gameOptionsButtonPlay;
       Button gameOptionsButtonMain;

   Button mainButtonExit;
       Button qExitButtonNo;
       Button qExitButtonYes;

   Button mainButtonOptions;
       ButtonProgress optionsButtonSoundTrack;
       ButtonProgress optionsButtonSoundEffects;
       Button optionsButtonBack;
       Button optionsButtonCheckUpdates;
       Button optionsButtonSite;

   Button mainButtonShop;
      Button shopButtonUpgrade;
      Button shopButtonBack;
      Button shopButtonUse;
      Button shopButtonLeft;
      Button shopButtonRight;

   // Colors
   QColor whiteBrownLogo;
   QColor whiteBrown;
   QColor brown;
   QColor colorNone;

   // Texts
   QString mainScreensaverSmallText;
   QString mainQConfirmText;
   QString gameOptionsText;

   // Path for a current project
   QString baseDir;

   // Path to Fonts
   int logoFontId,mainFontId,gameFontId,buttonFontId;

   // Random Sound Sword
   int oldSwordSoundNumber,swordSoundNumber;

   // Fonts
   QFont fontVagtur;
   QFont fontRounds;
   QFont fontProjects;
   QFont fontAxis;
   QFont fontArista;

   // Sounds
   QMediaPlaylist *soundtrackPlaylist;

   QMediaPlayer *loadSound(const QString &soundPath);

   QMediaPlayer *mainSoundtrack;
   QMediaPlayer *soundTrackStart;
   QMediaPlayer *soundTrack[1];
   \
   QMediaPlayer *shopSoundUpgrade;
   QMediaPlayer *shopSoundBuy;
   QMediaPlayer *shopSoundUse;

   QMediaPlayer *gameSoundShot[3][gameSoundShotsNumber];
   int gameSoundShotsId;
   QMediaPlayer *gameSoundEndBattle;
   QMediaPlayer *gameSoundStartBattle;

   QMediaPlayer *buttonSoundClick;

   // Change fade
   QTimer *fadeTimer;
   QTimer *playerTimer;
   QTimer *enemyTimer;

   // OldX and OldY
   static const int oldPlayerXCoordinates = 20;
   static const int oldPlayerYCoordinates = 20;
   int oldPlayerX[oldPlayerXCoordinates],oldPlayerY[oldPlayerYCoordinates];

   // OldX and OldY
   static const int oldEnemyXCoordinates = 20;
   static const int oldEnemyYCoordinates = 20;
   int oldEnemyX[oldEnemyXCoordinates],oldEnemyY[oldEnemyYCoordinates];
   // Speed
   float playerSpeed,enemySpeed;

   // Health
   int playerHealth,enemyHealth;

   // Current scene
   int scene,oldScene;

   // Sprites Angles
   int playerAngle,enemyAngle;

   // Damage
   float damageScale;

   // Bools
   bool firstOpen;
   bool clicked;
   bool enemyAttack;
   bool attack;
   bool playerLeft;
   bool upLayer;
   bool inButton;

   // Rect for background
   QRect gameBackgroundRect;

   // Rect for background
   QRect gamePauseMaskRect;

   // Rect for mask
   QRect mainBackgroundMaskRect;

   // Rect for background texture
   QRect mainBackgroundTextureRect;

   // Cursors
   QCursor cursorBlank;
   QCursor cursor;
   QCursor cursorHand;
   QCursor cursorCHand;

   QRect rectCenter(QRect rect, int width, int height);

   // ----------------------------------------------------------------- X and Y -----------------------------------------------------------------

   int clickX, clickY;
   int moveX, moveY;
   int releaseX, releaseY;

   // ----------------------------------------------------------------- Images -----------------------------------------------------------------

   // Icons
   Icon iconPrice;
   Icon iconDefense;
   Icon iconDamage;
   Icon iconCoins;
   Icon iconSpeed;

   // Backgrounds
   QImage gameBackground;
   QImage mainBackgroundTexture;

   // Swords
   Sword swords[numberSwords];
   int selectSwordId;
   int usedSwordId;

   Sword enemySwords[3];
   int usedEnemySwordId;

   // Bars
   QImage playerHealthBarIcon,playerHealthBarIconMask,playerHealthBarUp,playerHealthBarDown;
   QImage enemyHealthBarIcon,enemyHealthBarIconMask,enemyHealthBarUp,enemyHealthBarDown;
   QImage playerHealthBarImg,enemyHealthBarImg, playerHealthBarDImg,enemyHealthBarDImg;

   // Animations
   Animation mainSwordOpasityAnimation;
   AnimationCoords playerAnimation;
   AnimationCoords enemyAnimation;
   AnimationCoords screensaverSmallTextAnimation;
   Animation enemyHealthDAnimation;
   Animation playerHealthDAnimation;
   Animation opasityScreensaverAnimation;
   AnimationCoords gameBackgroundMaskPauseAnimation;
   AnimationCoords playerHealthBarAnimation;
   AnimationCoords enemyHealthBarAnimation;
   AnimationCoords gameOptionsMaskAnimation;

   void timerEvent(QTimerEvent *);

   private slots:
   void checkAttack();
   void setMatrixPlayer();
   void setMatrixEnemy();
   void enemyShot();
   void goFade();
   void paintEvent(QPaintEvent *);
   void mouseReleaseEvent(QMouseEvent *);
   void mousePressEvent(QMouseEvent *);
   void mouseMoveEvent(QMouseEvent *);
   void startMainAnimations(bool iconsAnimations = true);
   void startIconsAnimations();
   void startQExitAnimations();
   void startOptionsAnimations();
   void startGameAnimations();
   void startPauseAnimations();
   void startShopAnimations();
   void startGameOptionsAnimations();
   void restartMainSwordOpasityAnimation();

public:
   void setVolume(int butttonId);
   void playSound(QMediaPlayer *player);
   void stopSound(QMediaPlayer *player);
   void pauseSound(QMediaPlayer *player);
   void loadImage(QImage &image, const QString &imagePath );
   void loadFont(QFont &font, const QString &name);
   void loadCursor(QCursor &cursor, const QString &name);

   private:
   void keyReleaseEvent(QKeyEvent *event);
   void setButtonsWidget();
   void drawScreensaver(QPainter &p);
   void drawBackgroundLogo(QPainter &p);
   void drawIcons(QPainter &p);
   void drawLogo(QPainter &p,bool paintSword = true,bool paintText = true);
   void drawMainGradient(QPainter &p);
   void drawGame(QPainter &p, int sceneid);
   void drawMain(QPainter &p, int sceneid);
   void drawPlayerSword(QPainter &p);
   void drawEnemySword(QPainter &p);
   void onClickButton(int buttonId);
   void drawTexture(QPainter &p, QImage texture, int startX = 0, int startY = 0);
   void drawHealthbars(QPainter &p);
   void playSwordShot();
   void loadAll();
   void setValues();
   void setAnimations();
   void setCursorInsideButton(QCursor &inCursor, QCursor &outCursor, int cursorX, int cursorY);
   void setCustomCursor();
   void writeSave();
   void readSave();
   void drawGameUi(QPainter &p);
   void setButtonProgressValue(ButtonProgress &button);
   void setChange(QPainter &p, QString &changeText, int change1, int change2);

   Ui::Widget *ui;
};

#endif // WIDGET_H
