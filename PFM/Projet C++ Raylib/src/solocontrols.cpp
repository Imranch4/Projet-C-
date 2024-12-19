#include "solocontrols.h"
#include "raylib.h"
#include <fstream>  

Solocontrols::Solocontrols() {
    player1 = 0;

    backButton = { 540, 590, 280, 300 }; 
    forwardButton = { 540, 660, 290, 300 }; 
    leftButton = { 540, 730, 290, 300 }; 
    rightButton = { 540, 800, 290, 300 }; 
    saveButton = { 1120, 900, 300, 300 };  
    returnButton = { 510, 900, 300, 300 };

    forwardKey = KEY_Z;
    backKey = KEY_S;
    leftKey = KEY_Q;
    rightKey = KEY_D;

    waitingForKey = false;
    waitingButton = nullptr;

    saveButtonImage = LoadTexture("buttons/butto/SAVE.png"); 
    returnButtonImage = LoadTexture("buttons/butto/Back in game.png"); 
    forwardButtonImage = LoadTexture("buttons/Hover2.png"); 
    backButtonImage = LoadTexture("buttons/Hover2.png");  
    leftButtonImage = LoadTexture("buttons/Hover2.png");  
    rightButtonImage = LoadTexture("buttons/Hover2.png"); 
    
    customFont = LoadFont("Font/monogram.ttf"); 
}

GameScreen Solocontrols::Update() {
    if (waitingForKey) {
        int pressedKey = GetKeyPressed();
        if (pressedKey != 0) { 
            if (pressedKey == forwardKey) forwardKey = 0;
            if (pressedKey == backKey) backKey = 0;
            if (pressedKey == leftKey) leftKey = 0;
            if (pressedKey == rightKey) rightKey = 0;
            if (waitingButton == &forwardButton) forwardKey = pressedKey;
            else if (waitingButton == &backButton) backKey = pressedKey;
            else if (waitingButton == &leftButton) leftKey = pressedKey;
            else if (waitingButton == &rightButton) rightKey = pressedKey;

            waitingForKey = false;
            waitingButton = nullptr;
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        waitingForKey = true;
        waitingButton = &backButton;
    }

    if (CheckCollisionPointRec(GetMousePosition(), forwardButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        waitingForKey = true;
        waitingButton = &forwardButton;
    }

    if (CheckCollisionPointRec(GetMousePosition(), leftButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        waitingForKey = true;
        waitingButton = &leftButton;
    }

    if (CheckCollisionPointRec(GetMousePosition(), rightButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        waitingForKey = true;
        waitingButton = &rightButton;
    }

    if (CheckCollisionPointRec(GetMousePosition(), saveButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        SaveKeyBindings(); 
    }

    if (CheckCollisionPointRec(GetMousePosition(), returnButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        return SETTINGS; 
    }

    return SOLOCONTROLS; 
}

void Solocontrols::Draw() {

    DrawTexture(saveButtonImage, saveButton.x, saveButton.y, WHITE); 
    DrawTexture(returnButtonImage, returnButton.x, returnButton.y, WHITE);

    DrawTexture(forwardButtonImage, forwardButton.x, forwardButton.y, WHITE); 
    DrawTextEx(customFont, "Forward", { forwardButton.x + 10, forwardButton.y + 10 }, 20, 2, WHITE);

    DrawTexture(backButtonImage, backButton.x, backButton.y, WHITE); 
    DrawTextEx(customFont, "Back", { backButton.x + 10, backButton.y + 10 }, 20, 2, WHITE);

    DrawTexture(leftButtonImage, leftButton.x, leftButton.y, WHITE); 
    DrawTextEx(customFont, "Left", { leftButton.x + 10, leftButton.y + 10 }, 20, 2, WHITE);

    DrawTexture(rightButtonImage, rightButton.x, rightButton.y, WHITE); 
    DrawTextEx(customFont, "Right", { rightButton.x + 10, rightButton.y + 10 }, 20, 2, WHITE);

    DrawTextEx(customFont, TextFormat("Back Key: %c", backKey), { 1160, 590 }, 40, 3, GREEN);
    DrawTextEx(customFont, TextFormat("Forward Key: %c", forwardKey), { 1160, 660 }, 40, 3, GREEN);
    DrawTextEx(customFont, TextFormat("Left Key: %c", leftKey), { 1160, 730 }, 40, 3, GREEN);
    DrawTextEx(customFont, TextFormat("Right Key: %c", rightKey), { 1160, 800 }, 40, 3, GREEN);
}

void Solocontrols::SaveKeyBindings() {
    if (forwardKey == 0) forwardKey = KEY_Z;
    if (backKey == 0) backKey = KEY_S;
    if (leftKey == 0) leftKey = KEY_Q;
    if (rightKey == 0) rightKey = KEY_D;

    std::ofstream outFile("keybindings.txt");

    outFile << "ForwardKey: " << forwardKey << "\n";
    outFile << "BackKey: " << backKey << "\n";
    outFile << "LeftKey: " << leftKey << "\n";
    outFile << "RightKey: " << rightKey << "\n";

    outFile.close();
}

void Solocontrols::LoadKeyBindings() {
    std::ifstream inFile("keybindings.txt");
    
    forwardKey = KEY_W;
    backKey = KEY_S;
    leftKey = KEY_A;
    rightKey = KEY_D;

    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            if (line.find("ForwardKey:") != std::string::npos) {
                forwardKey = line.back(); 
            } else if (line.find("BackKey:") != std::string::npos) {
                backKey = line.back();
            } else if (line.find("LeftKey:") != std::string::npos) {
                leftKey = line.back();
            } else if (line.find("RightKey:") != std::string::npos) {
                rightKey = line.back();
            }
        }
        inFile.close();
    }
}

void Solocontrols::SetPlayer(int playerMode) {
    player1 = playerMode; 
}

Solocontrols::~Solocontrols() {
    UnloadTexture(saveButtonImage);
    UnloadTexture(returnButtonImage);
    UnloadTexture(forwardButtonImage);
    UnloadTexture(backButtonImage);
    UnloadTexture(leftButtonImage);
    UnloadTexture(rightButtonImage);
}
