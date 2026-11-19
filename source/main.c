#include <stdio.h>
#include "component/inbox.h"
#include "input.h"
#include "engine/graphic.h"

int textureResolution;
int zoomLevel = 1;
int textureRenderSize;
Vector2 clickedTile;

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

    // load image
    Texture2D tilesheet = initTexture("assets/room.png", 816, 1004);

    while (!WindowShouldClose())
    {
        int w = GetScreenWidth();
        int h = GetScreenHeight();
        int tileMenu = 400;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePos = GetMousePosition();
            int x = (int)mousePos.x;
            //int y = (int)mousePos.y;

            if (x < (w - tileMenu)) {
                printf("click on tilemap\n");
            } else {
                printf("click on tileMenu\n");
                Vector2 clickedTile = choseTile(textureResolution, tilesheet.width, mousePos);
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            if (IsKeyPressed(KEY_H))
            {
                if (IsCursorHidden()) ShowCursor();
                else HideCursor();
            }

            for (int i = 0; i < h; i += 10) {
                DrawLine(0, i, (w - tileMenu) - 0, i, LIGHTGRAY);
                i += textureRenderSize;
            }
            for (int i = 0; i < (w - tileMenu); i += 10) {
                DrawLine(i, 0, i, h, LIGHTGRAY);
                i += textureRenderSize;
            }

            short nbTxtHeight = tilesheet.height / textureResolution;

            for (int i = 0; i < nbTxtHeight; i++) {
                for (int x = 0; x < (tileMenu / textureResolution); x++) {
                    Rectangle toRender = {
                        (x * textureResolution),
                        i * textureResolution,
                        textureResolution,
                        textureResolution
                    };

                    DrawTextureRec(tilesheet, toRender, (Vector2){ (w - tileMenu + x + (x * textureResolution)), (i + (i * textureResolution)) }, WHITE);
                };
            };

            DrawLine((w - tileMenu), 0, (w - tileMenu), h, LIGHTGRAY);

            DrawText(TextFormat("Zoom : %d", zoomLevel), 10, 10, 20, BLACK);

            zoomLevel += zoomAction();
            textureRenderSize = textureResolution * zoomLevel;



        EndDrawing();
    }

    CloseWindow();
    return 0;
}
