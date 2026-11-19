#include <stdlib.h>
#include "graphic.h"

Texture2D initTexture(const char *path, int sx, int sy)
{
    Image img = LoadImage(path);
    if (img.data == NULL)
    {
        TraceLog(LOG_ERROR, "error when loading %s", path);
        return (Texture2D){ 0 };
    }

    ImageResizeNN(&img, sx, sy);

    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);

    return tex;
}
