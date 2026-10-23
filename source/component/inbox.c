#include <stdlib.h>
#include "inbox.h"

int createInbox(char* title, char* description) {
    InitWindow(INBOX_WIDTH, INBOX_HEIGHT, "TileGrid");
    SetTargetFPS(60);

    char field[3] = { 0 };
    int count = 0;

    while (!WindowShouldClose()) {
        int key = GetCharPressed();

        if (key >= '0' && key <= '9' && count < 2) {
            field[count++] = (char)key;
            field[count] = '\0';
        }

        if (IsKeyPressed(KEY_BACKSPACE) && count > 0) {
            field[--count] = '\0';
        }

        if (IsKeyPressed(KEY_ENTER) && count > 0) {
            CloseWindow();
            return atoi(field);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(title, 10, 10, 20, BLACK);
        DrawText(description, 10, 40, 15, BLACK);
        DrawText(field, 10, 70, 20, DARKBLUE);
        EndDrawing();
    }

    CloseWindow();
    return -1;
}