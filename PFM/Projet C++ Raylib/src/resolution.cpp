#include "resolution.h"
#include <iostream>

Resolution::Resolution() : resolutionWidth(1920), resolutionHeight(1080), fullscreen(true) {
    fullscreenButtonTexture = LoadTexture("buttons/butto/Toggle.png");
    saveButtonTexture = LoadTexture("buttons/butto/SAVE.png");
    returnButtonTexture = LoadTexture("buttons/butto/Back in game.png");

    fullscreenButtonRect = { 640.0f, 650.0f, (float)fullscreenButtonTexture.width, (float)fullscreenButtonTexture.height };
    saveButtonRect = { 1165.0f, 900.0f, (float)saveButtonTexture.width, (float)saveButtonTexture.height };
    returnButtonRect = { 465.0f, 900.0f, (float)returnButtonTexture.width, (float)returnButtonTexture.height };

    SetWindowSize(resolutionWidth, resolutionHeight);
    if (fullscreen) {
        ToggleFullscreen(); 
    }
}

void Resolution::setFullscreen(bool isFullscreen) {
    fullscreen = isFullscreen;
    if (fullscreen) {
        SetWindowSize(resolutionWidth, resolutionHeight);
        ToggleFullscreen();
    } else {
        SetWindowSize(resolutionWidth, resolutionHeight);
        ToggleFullscreen(); 
    }
}

void Resolution::printSettings() const {
    std::cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << std::endl;
    std::cout << "Fullscreen: " << (fullscreen ? "ON" : "OFF") << std::endl;
}

void Resolution::Draw() {
    if (fullscreen) {
        DrawTexture(fullscreenButtonTexture, (int)fullscreenButtonRect.x, (int)fullscreenButtonRect.y, WHITE);
    } else {
        DrawTexture(windowedButtonTexture, (int)windowedButtonRect.x, (int)windowedButtonRect.y, WHITE);
    }

    DrawTexture(saveButtonTexture, (int)saveButtonRect.x, (int)saveButtonRect.y, WHITE);
    DrawTexture(returnButtonTexture, (int)returnButtonRect.x, (int)returnButtonRect.y, WHITE);
}

GameScreen Resolution::Update() {
    if (CheckCollisionPointRec(GetMousePosition(), fullscreenButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        setFullscreen(true); 
    }

    if (CheckCollisionPointRec(GetMousePosition(), windowedButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        setFullscreen(false); 
    }

    if (CheckCollisionPointRec(GetMousePosition(), saveButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        printSettings();
    }

    if (CheckCollisionPointRec(GetMousePosition(), returnButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return SETTINGS;
    }

    return RESOLUTION; 
}
