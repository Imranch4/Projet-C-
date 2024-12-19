#ifndef JOUEUR_H
#define JOUEUR_H

#include "Labyrinthe.h" 
#include "game.h"

class Joueur {
public:
    Joueur(int startX, int startY, float speed) : x(startX), y(startY), speed(speed) {}
    int x, y;      
    float speed;  
    static constexpr float initSpeed = 1.0f;
    Joueur(int startX, int startY) : x(startX), y(startY), speed(initSpeed) {}
    GameScreen Update(Labyrinthe& labyrinthe);
    void deplacer(char direction, Labyrinthe& labyrinthe);
void Draw(float mazeOffsetX, float mazeOffsetY);
};

#endif // JOUEUR_H
