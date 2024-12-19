#include "raylib.h" 
#include "Joueur.h"

GameScreen Joueur::Update(Labyrinthe& labyrinthe) {
    const int speedMultiplier = 2; 


    if (IsKeyDown(KEY_RIGHT)) {
        for (int i = 0; i < speedMultiplier; i++) {
            deplacer('R', labyrinthe); 
        }
    }
    if (IsKeyDown(KEY_LEFT)) {
        for (int i = 0; i < speedMultiplier; i++) {
            deplacer('L', labyrinthe); 
        }
    }
    if (IsKeyDown(KEY_DOWN)) {
        for (int i = 0; i < speedMultiplier; i++) {
            deplacer('D', labyrinthe);
        }
    }
    if (IsKeyDown(KEY_UP)) {
        for (int i = 0; i < speedMultiplier; i++) {
            deplacer('U', labyrinthe);
        }
    }
    return SOLOCONTROLS;
}

void Joueur::deplacer(char direction, Labyrinthe& labyrinthe) {
    if (direction == 'R' && labyrinthe.grille[y][x + 1] == 0) x++;
    if (direction == 'L' && labyrinthe.grille[y][x - 1] == 0) x--;
    if (direction == 'D' && labyrinthe.grille[y + 1][x] == 0) y++;
    if (direction == 'U' && labyrinthe.grille[y - 1][x] == 0) y--;
}
 

void Joueur::Draw(float mazeOffsetX, float mazeOffsetY) {
    const int cellSize = 20;
    const Color playerColor = BLUE;  
    DrawRectangle(x * cellSize + mazeOffsetX, y * cellSize + mazeOffsetY, cellSize, cellSize, playerColor);
}
