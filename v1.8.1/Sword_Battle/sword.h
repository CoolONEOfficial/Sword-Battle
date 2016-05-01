#ifndef SWORD_H
#define SWORD_H

#include <QObject>
#include <QImage>

class Widget;

class Sword : public QObject
{
    Q_OBJECT
public:
    explicit Sword(QObject *parent = 0, QString type = "");

    // Widget
    Widget *widget;

    QImage sword, mask;

    QString name;

    int levelSword;

    int dPrice;
    int price();
    int price(int level);

    int dDamage;
    int damage();
    int damage(int level);


    int dDefence;
    int defence();
    int defence(int level);

    int dSpeed;
    int speed();
    int speed(int level);
    int roundSpeed();
    int roundSpeed(int level);

signals:

public slots:
void load(QString type, bool player = true);
void setWidget(Widget *w);
void setSpeed(int newSpeed);
};

#endif // SWORD_H
