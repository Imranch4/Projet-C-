#include "Labyrinthe.h"

Labyrinthe::Labyrinthe(int l, int h) : largeur(l), hauteur(h) {
    srand(time(0));
    grille.resize(hauteur, std::vector<int>(largeur, 1)); 
    genererLabyrinthe();
}

void Labyrinthe::genererLabyrinthe() {
    int x = 1, y = 1;
    grille[y][x] = 0;

    std::stack<std::pair<int, int>> pile;
    pile.push({x, y});

    std::vector<std::pair<int, int>> directions = {{2, 0}, {0, 2}, {-2, 0}, {0, -2}};

    while (!pile.empty()) {
        auto current = pile.top();
        int cx = current.first;
        int cy = current.second;
        std::vector<std::pair<int, int>> voisins;

        for (auto& dir : directions) {
            int nx = cx + dir.first;
            int ny = cy + dir.second;
            if (nx > 0 && ny > 0 && nx < largeur - 1 && ny < hauteur - 1 && grille[ny][nx] == 1) {
                voisins.push_back({nx, ny});
            }
        }

        if (!voisins.empty()) {
            auto next = voisins[rand() % voisins.size()];
            int nx = next.first;
            int ny = next.second;
            grille[cy + (ny - cy) / 2][cx + (nx - cx) / 2] = 0;
            grille[ny][nx] = 0;
            pile.push(next);
        } else {
            pile.pop();
        }
    }

    setFinishPoint(largeur - 2, hauteur - 2);
}

void Labyrinthe::setFinishPoint(int x, int y) {
    finishX = x;
    finishY = y;
    grille[y][x] = 2;
}