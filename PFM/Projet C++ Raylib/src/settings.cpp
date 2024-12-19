#include "settings.h"

Settings::Settings() {
    backTexture = LoadTexture("buttons/butto/Back2 - Copie.png");
    volumeTexture = LoadTexture("buttons/butto/volume.png");
    resolutionTexture = LoadTexture("buttons/butto/res.png");
    player1Texture = LoadTexture("buttons/butto/control.png");

    float buttonWidth = volumeTexture.width;
    float buttonHeight = volumeTexture.height;
    float spacing = 20;

    float startY = 600;

    player1Button = { (GetScreenWidth() - buttonWidth) / 2, startY, buttonWidth, buttonHeight };
    volumeButton = { player1Button.x, player1Button.y + buttonHeight + spacing, buttonWidth, buttonHeight };
    resolutionButton = { volumeButton.x, volumeButton.y + buttonHeight + spacing, buttonWidth, buttonHeight };
    backButton = { resolutionButton.x, resolutionButton.y + buttonHeight + spacing, buttonWidth, buttonHeight };
}

Settings::~Settings() {
    UnloadTexture(backTexture);
    UnloadTexture(volumeTexture);
    UnloadTexture(resolutionTexture);
    UnloadTexture(player1Texture);
}

GameScreen Settings::Update() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, backButton)) return MENU;
        if (CheckCollisionPointRec(mousePos, volumeButton)) return VOLUME;
        if (CheckCollisionPointRec(mousePos, resolutionButton)) return RESOLUTION;
        if (CheckCollisionPointRec(mousePos, player1Button)) return SOLOCONTROLS;
    }

    return SETTINGS;
}

void Settings::Draw() {
    DrawTextureRec(player1Texture, { 0, 0, (float)player1Texture.width, (float)player1Texture.height }, { player1Button.x, player1Button.y }, WHITE);
    DrawTextureRec(volumeTexture, { 0, 0, (float)volumeTexture.width, (float)volumeTexture.height }, { volumeButton.x, volumeButton.y }, WHITE);
    DrawTextureRec(resolutionTexture, { 0, 0, (float)resolutionTexture.width, (float)resolutionTexture.height }, { resolutionButton.x, resolutionButton.y }, WHITE);
    DrawTextureRec(backTexture, { 0, 0, (float)backTexture.width, (float)backTexture.height }, { backButton.x, backButton.y }, WHITE);
}
