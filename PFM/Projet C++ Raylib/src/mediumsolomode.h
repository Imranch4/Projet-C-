#ifndef MEDIUMSOLOMODE_H
#define MEDIUMSOLOMODE_H

#include "raylib.h"
#include "game.h"
#include "Labyrinthe.h"
#include "Joueur.h" 

class Mediumsolomode {
public:
    Mediumsolomode(); 
    ~Mediumsolomode();
    Labyrinthe maze;
    Joueur player; 
    const int cellSize = 20;
    GameScreen Update(); 
    void Draw();  

private:
    Texture2D backgroundTexture;  
    Texture2D settingsButtonTexture; 
    Texture2D chronoIconTexture; 

    Rectangle settingsButton;   
    Vector2 chronoPosition;  
    Rectangle mazeArea;    
    double startTime;  
    bool gameWon;    
    double endTime;   
    double finalTime;  
};

#endif // MEDIUMSOLOMODE_H
