#ifndef SCRATCH_H_
#define SCRATCH_H_

#include <window.hpp>
#include <utilities.hpp>

class Scratch {
public:
    Scratch(string name, int width, int height, Color bgcolor, bool resizable);

    void refresh();

    void addSprite();
private:
    Window window;
    
    string name;
    bool visible, resizable;
    int width, height;
    Color bgcolor;
};

#endif