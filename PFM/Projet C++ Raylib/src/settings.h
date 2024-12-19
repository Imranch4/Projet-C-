#ifndef SETTINGS_H
#define SETTINGS_H

#include "raylib.h"
#include "game.h"

class Settings {
public:
    Settings(); 
    ~Settings(); 
    GameScreen Update();
    void Draw();   

private:
    Rectangle backButton;
    Rectangle volumeButton;
    Rectangle resolutionButton;
    Rectangle player1Button;

    Texture2D backTexture;
    Texture2D volumeTexture;
    Texture2D resolutionTexture;
    Texture2D player1Texture;
};

#endif // SETTINGS_H