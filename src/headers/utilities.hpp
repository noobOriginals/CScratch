

class SDrawable {
public:
    virtual void draw(Window window);
};

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
namespace color {
    Color black = Color(0, 0, 0);
    Color white = Color(1, 1, 1);
}