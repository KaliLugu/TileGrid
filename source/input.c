#include "component/inbox.h"

#define INCREASE_ZOOM 1
#define DECREASE_ZOOM -1

int zoomAction() {
    int ctrl  = IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);
    int plus  = IsKeyPressed(KEY_EQUAL) || IsKeyPressed(KEY_KP_ADD);
    int minus = IsKeyPressed(KEY_MINUS) || IsKeyPressed(KEY_KP_SUBTRACT);

    if (ctrl && plus) {
        return INCREASE_ZOOM;
    }
    if (ctrl && minus) {
        return DECREASE_ZOOM;
    }
    return 0;
}

Vector2 choseTile(int tileRes, int tileSheetRes, Vector2 mousePos) {

    int tilex = mousePos.x - (GetScreenWidth() - 400) / tileRes;
    int tiley = mousePos.y / tileRes;

    return (Vector2){tilex, tiley};
}
