#ifndef SOLOCONTROLS_H
#define SOLOCONTROLS_H

#include "raylib.h"
#include "game.h"

class Solocontrols {
public:
    Solocontrols(); 
    ~Solocontrols(); 

    GameScreen Update(); 
    void Draw();  
    void SaveKeyBindings();
    void LoadKeyBindings();
    void SetPlayer(int playerMode);

private:
    Rectangle backButton, forwardButton, leftButton, rightButton;
    Rectangle saveButton, returnButton;

    int forwardKey, backKey, leftKey, rightKey;

    Texture2D saveButtonImage, returnButtonImage;
    Texture2D backButtonImage, forwardButtonImage, leftButtonImage, rightButtonImage;

    Font customFont;

    bool waitingForKey;
    Rectangle* waitingButton; 

    int player1;
};

#endif // SOLOCONTROLS_H

