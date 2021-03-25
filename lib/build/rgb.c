#include <stdbool.h>

#define MAX_RGB 255

struct RGB {
    int r;
    int g;
    int b;
};

bool rgb_set(struct RGB *rgb, int r, int g, int b) {
    r = r < 0 ? r * -1 : r;
    g = g < 0 ? g * -1 : g;
    b = b < 0 ? b * -1 : b;
    if((r <= MAX_RGB) && (g <= MAX_RGB) && (b <= MAX_RGB)) {
        rgb -> r = r; 
        rgb -> g = g;
        rgb -> b = b;
        return true;
    }
    else return false;
}

void rgb_invert(struct RGB *rgb) {
    rgb_set(
        rgb, 
        MAX_RGB - rgb -> r,
        MAX_RGB - rgb -> g,
        MAX_RGB - rgb -> b
    );
}
