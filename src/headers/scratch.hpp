#include <window.hpp>
#include <utilities.hpp>

class Scratch {
public:
    Scratch(string name, int width, int height, Color bgcolor, bool resizable);\
    void addSDrawable(SDrawable sd);

private:
    Window window;
    
    string name;
    bool visible, resizable;
    int width, height;
    Color bgcolor;
};