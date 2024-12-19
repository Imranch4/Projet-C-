#ifndef RESOLUTION_H
#define RESOLUTION_H

#include "raylib.h"
#include "game.h" 

class Resolution {
public:
    Resolution();
    void setFullscreen(bool isFullscreen);
    void printSettings() const;
    void Draw();
    GameScreen Update();

private:
    int resolutionWidth;
    int resolutionHeight;
    bool fullscreen;
    Texture2D fullscreenButtonTexture;
    Texture2D windowedButtonTexture;
    Texture2D saveButtonTexture;
    Texture2D returnButtonTexture;
    Rectangle fullscreenButtonRect;
    Rectangle windowedButtonRect;
    Rectangle saveButtonRect;
    Rectangle returnButtonRect;
};

#endif // RESOLUTION_H
