#ifndef SPRITE_H_
#define SPRITE_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include <utilities.hpp>
#include <costume.hpp>

using namespace std;

class Sprite {
public:
    Sprite(string name);
    Sprite(string name, bool visible);
    Sprite(string name, bool visible, int x, int y);
    Sprite(string name, int x, int y);
    Sprite(int x, int y);
    Sprite();

    void update();
    void draw();

    void move(int steps);
    void move(int steps, double dir);
    void pointInDirection(double dir);
    void turnLeft(double ang);
    void turnRight(double ang);
    void changeX(int i);
    void changeY(int i);
    void setX(int x);
    void serY(int y);

    bool touching(Sprite other);
    bool touching(Color col);

    void setCostume(int c);
    void setCostume(string cname);
    void addCostume(Costume c);

    int getCostumeIdx();
    Costume getCostume();
    Costume getCostume(int i);
    Costume getCostume(string name);
    double getSize();
    string getName();
    int getX();
    int getY();
    int getWidth();
    int getHeight();

private:
    vector<Costume> costumes;
    string name;
    bool visible;
    int costume;
    double size;
    int x, y;
    double direction;

    void(*update_callback)(Sprite s);
};

#endif