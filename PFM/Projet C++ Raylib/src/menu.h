#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "game.h"

class Menu {
public:
    Menu(); 
    ~Menu();

    GameScreen Update();
    void Draw();        

private:
    Rectangle soloButton;     
    Rectangle settingsButton;    
    Rectangle exitButton;   

    Texture2D soloTexture;   
    Texture2D settingsTexture;
    Texture2D exitTexture;
};

#endif // MENU_H
