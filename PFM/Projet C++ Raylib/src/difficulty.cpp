#include "difficulty.h"

Difficulty::Difficulty() {
    easyTexture = LoadTexture("buttons/butto/EASY.png");
    mediumTexture = LoadTexture("buttons/butto/MEDIUM.png");
    hardTexture = LoadTexture("buttons/butto/HARD.png");
    returnTexture = LoadTexture("buttons/butto/Back2.png");


    float buttonWidth = easyTexture.width;
    float buttonHeight = easyTexture.height;
    float spacing = 20;

    easyButton = { (GetScreenWidth() - buttonWidth) / 2, GetScreenHeight() - (buttonHeight * 4 + spacing * 3) - 100, buttonWidth, buttonHeight };
    mediumButton = { (GetScreenWidth() - buttonWidth) / 2, easyButton.y + buttonHeight + spacing, buttonWidth, buttonHeight };
    hardButton = { (GetScreenWidth() - buttonWidth) / 2, mediumButton.y + buttonHeight + spacing, buttonWidth, buttonHeight };
    returnButton = { (GetScreenWidth() - buttonWidth) / 2, hardButton.y + buttonHeight + spacing, buttonWidth, buttonHeight };
}

Difficulty::~Difficulty() {
    UnloadTexture(easyTexture);
    UnloadTexture(mediumTexture);
    UnloadTexture(hardTexture);
    UnloadTexture(returnTexture);
}

GameScreen Difficulty::Update() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, easyButton)) return EASYSOLOMODE;
        if (CheckCollisionPointRec(mousePos, mediumButton)) return MEDIUMSOLOMODE;
        if (CheckCollisionPointRec(mousePos, hardButton)) return HARDSOLOMODE;
        if (CheckCollisionPointRec(mousePos, returnButton)) return MENU;
    }

    return DIFFICULTY;
}

void Difficulty::Draw() {
    DrawTextureRec(easyTexture, { 0, 0, (float)easyTexture.width, (float)easyTexture.height }, { easyButton.x, easyButton.y }, WHITE);
    DrawTextureRec(mediumTexture, { 0, 0, (float)mediumTexture.width, (float)mediumTexture.height }, { mediumButton.x, mediumButton.y }, WHITE);
    DrawTextureRec(hardTexture, { 0, 0, (float)hardTexture.width, (float)hardTexture.height }, { hardButton.x, hardButton.y }, WHITE);
    DrawTextureRec(returnTexture, { 0, 0, (float)returnTexture.width, (float)returnTexture.height }, { returnButton.x, returnButton.y }, WHITE);
}
