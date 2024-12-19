#include "menu.h"

Menu::Menu() {

    soloTexture = LoadTexture("buttons/butto/SOLO.png");
    settingsTexture = LoadTexture("buttons/butto/SETTINGS.png");
    exitTexture = LoadTexture("buttons/butto/exit.png");

    float buttonWidth = soloTexture.width;
    float buttonHeight = soloTexture.height;
    float spacing = 20;

    soloButton = { (GetScreenWidth() - buttonWidth) / 2, GetScreenHeight() - (buttonHeight * 4 + spacing * 3) - 100, buttonWidth, buttonHeight };
    settingsButton = { (GetScreenWidth() - buttonWidth) / 2, soloButton.y + buttonHeight + spacing, buttonWidth, buttonHeight };
    exitButton = { (GetScreenWidth() - buttonWidth) / 2, settingsButton.y + buttonHeight + spacing, buttonWidth, buttonHeight };
}

Menu::~Menu() {

    UnloadTexture(soloTexture);
    UnloadTexture(settingsTexture);
    UnloadTexture(exitTexture);
}

GameScreen Menu::Update() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, soloButton)) return DIFFICULTY;
        if (CheckCollisionPointRec(mousePos, settingsButton)) return SETTINGS; 
        if (CheckCollisionPointRec(mousePos, exitButton)) CloseWindow(); 
    }

    return MENU;
}

void Menu::Draw() {
    DrawTextureRec(soloTexture, { 0, 0, (float)soloTexture.width, (float)soloTexture.height }, { soloButton.x, soloButton.y }, WHITE);
    DrawTextureRec(settingsTexture, { 0, 0, (float)settingsTexture.width, (float)settingsTexture.height }, { settingsButton.x, settingsButton.y }, WHITE);
    DrawTextureRec(exitTexture, { 0, 0, (float)exitTexture.width, (float)exitTexture.height }, { exitButton.x, exitButton.y }, WHITE);
}
