#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <utility>

class Labyrinthe {
public:
    int largeur, hauteur;
    std::vector<std::vector<int>> grille;
    int finishX, finishY;

    Labyrinthe(int l, int h);
    void genererLabyrinthe();
    void setFinishPoint(int x, int y);
};

#endif // LABYRINTHE_H
