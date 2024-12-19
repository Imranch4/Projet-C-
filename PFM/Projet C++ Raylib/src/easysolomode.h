#ifndef EASYSOLOMODE_H
#define EASYSOLOMODE_H

#include "raylib.h"
#include "game.h"
#include "Labyrinthe.h"
#include "Joueur.h" 

class Easysolomode {
public:
    Easysolomode(); 
    ~Easysolomode(); 
    Labyrinthe maze;
    Joueur player; 
    const int cellSize = 20;
    GameScreen Update(); 
    void Draw();    

private:
    Texture2D backgroundTexture;   
    Texture2D settingsButtonTexture; 
    Texture2D chronoIconTexture;   
 Texture2D playerTexture;
    Rectangle settingsButton;    
    Vector2 chronoPosition;  
    Rectangle mazeArea;

    double startTime;         
    bool gameWon;  
    double endTime;   
    double finalTime;                  
};

#endif // EASYSOLOMODE_H
