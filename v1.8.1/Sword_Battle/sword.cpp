#include "sword.h"

#include "widget.h"

#include "math.h"

Sword::Sword(QObject *parent, QString type) : QObject(parent)
{
    widget = 0;

    name = "No Name";

    levelSword = 0;

    if(type != "")
        load(type);

    dSpeed = 350;

    dPrice = 5;

    dDamage = 10;

    dDefence = 10;
}

int Sword::price()
{
    return price(levelSword);
}

int Sword::price(int level)
{
    if(level > 0)
    {
        // Upgrade price
        return dPrice*pow(2, level);
    }
    else
    {
        // Buy price
        return dPrice;
    }
}

int Sword::damage()
{
    return damage(levelSword);
}

int Sword::damage(int level)
{
    return dDamage+(level*5);
}

int Sword::defence()
{
    return defence(levelSword);
}

int Sword::defence(int level)
{
    return dDefence+(level*2);
}

int Sword::speed()
{
    return speed(levelSword);
}

int Sword::speed(int level)
{
    int outSpeed = 1000-((dSpeed+(level*10)));
    if(outSpeed<=10)
        outSpeed = 10;
    return outSpeed;
}

int Sword::roundSpeed()
{
    return roundSpeed(levelSword);
}

int Sword::roundSpeed(int level)
{
    return 100-speed(level)/10;
}

void Sword::load(QString type, bool player)
{
    QString pathType;

    name = type;

    // Set path
    if(player)
        pathType = "player";
    else
        pathType = "enemy";

    QString path = "game//"+pathType+"//swords//"+type+"//";

    widget->loadImage(sword, path + "sword.png");
    widget->loadImage(mask, path + "mask.png");
}

void Sword::setWidget(Widget *w)
{
    widget = w;
}

void Sword::setSpeed(int newSpeed)
{
    dSpeed = newSpeed*10;
}

