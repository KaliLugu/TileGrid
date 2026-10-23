#include <stdio.h>
#include "component/inbox.h"
#include "input.h"

int textureResolution;
int zoomLevel = 1;
int textureRenderSize;

int main() {
    textureResolution = createInbox("TileGrid", "enter resolution per texture");

    if (textureResolution < 1) {
        printf("Invalid texture resolution: %d\n", textureResolution);
        return 1;
    }

    printf("Texture resolution: %d\n", textureResolution);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "Ma fenêtre");
    SetWindowMinSize(320, 240);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        int w = GetScreenWidth();
        int h = GetScreenHeight();

        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < h; i += 10) {
                DrawLine(0, i, (w - 400) - 0, i, LIGHTGRAY);
                i += textureRenderSize;
            }
            for (int i = 0; i < (w - 400); i += 10) {
                DrawLine(i, 0, i, h, LIGHTGRAY);
                i += textureRenderSize;
            }

            DrawLine((w - 400), 0, (w - 400), h, LIGHTGRAY);

            DrawText(TextFormat("Zoom : %d", zoomLevel), 10, 10, 20, BLACK);

            zoomLevel += zoomAction();
            textureRenderSize = textureResolution * zoomLevel;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
