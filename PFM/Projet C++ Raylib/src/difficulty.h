#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include "raylib.h"
#include "game.h"


class Difficulty {
public:
    Difficulty(); 
    ~Difficulty();

    GameScreen Update(); 
    void Draw();         

private:
    Rectangle easyButton;    
    Rectangle mediumButton;   
    Rectangle hardButton;     
    Rectangle returnButton;  

    Texture2D easyTexture;    
    Texture2D mediumTexture;  
    Texture2D hardTexture;  
    Texture2D returnTexture; 
};

#endif // DIFFICULTY_H
