#ifndef UTILITIES_H_
#define UTILITIES_H_

struct Color {
    int r, g, b;
    Color(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    Color() {
        r = g = b = 0;
    }
};

#endif