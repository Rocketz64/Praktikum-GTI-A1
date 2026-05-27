#include "input.h"
#include "types.h"
#include <ctype.h>

bool keys[256] = {false};

void keyDown(unsigned char key, int x, int y) {
    key = tolower(key);
    keys[key] = true;
}

void keyUp(unsigned char key, int x, int y) {
    key = tolower(key);
    keys[key] = false;
}
