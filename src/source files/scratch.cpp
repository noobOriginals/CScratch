#include <scratch.hpp>

long windowCount = 0;

Scratch::Scratch(string name, int width, int height, Color bgcolor, bool resizable) {
    windowCount++;

    if (windowCount > 1) {
        cerr << "Cannot create multiple Scratch type odjects!" << endl;
        return;
    }

    this->name = name;
    this->width = width;
    this->height = height;
    this->bgcolor = bgcolor;
    visible = true;
    this->resizable = resizable;

    window = Window(width, height, name);
    window.show();
}
