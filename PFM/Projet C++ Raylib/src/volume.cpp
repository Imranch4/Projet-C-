#include "Volume.h"
#include "raylib.h"

Volume::Volume() : volume(0.5f), muted(false) {
    volumeBar = { 580, 650, 800, 40 }; 
    muteButton = { volumeBar.x - 565 + volumeBar.width + 20, volumeBar.y + 110, 280, 80 }; 
    returnButton = { volumeBar.x, volumeBar.y + 250, 280, 80 }; 
    saveButton = { volumeBar.x - 180 + volumeBar.width - 150, volumeBar.y + 250, 280, 80 };
    muteIcon = LoadTexture("buttons/butto/MUTE.png");
    unmuteIcon = LoadTexture("buttons/butto/MUTE.png");
    saveButtonImage = LoadTexture("buttons/butto/SAVE.png");
    returnButtonImage = LoadTexture("buttons/butto/Back in game.png");
}

Volume::~Volume() {
    UnloadTexture(muteIcon);
    UnloadTexture(unmuteIcon);
    UnloadTexture(saveButtonImage);
    UnloadTexture(returnButtonImage);
}

void Volume::Init() {
    if (muteIcon.id == 0 || unmuteIcon.id == 0 || saveButtonImage.id == 0 || returnButtonImage.id == 0) {
        TraceLog(LOG_ERROR, "Failed to load button icons!");
    }
}

GameScreen Volume::Update(Music &music) {
    if (IsKeyPressed(KEY_UP) && volume < 1.0f) {
        volume += 0.05f;
    } else if (IsKeyPressed(KEY_DOWN) && volume > 0.0f) {
        volume -= 0.05f;
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if (CheckCollisionPointRec(GetMousePosition(), volumeBar)) {
            volume = (GetMouseX() - volumeBar.x) / volumeBar.width;
            volume = Clamp(volume, 0.0f, 1.0f);
        }
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), muteButton)) {
        ToggleMute();
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), returnButton)) {
        return SETTINGS;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), saveButton)) {
        TraceLog(LOG_INFO, "Settings saved.");
    }

    SetMusicVolume(music, muted ? 0.0f : volume);

    return VOLUME;
}

void Volume::Draw() {
    DrawRectangleRec(volumeBar, DARKGRAY); 
    DrawRectangle(volumeBar.x, volumeBar.y, volumeBar.width * volume, volumeBar.height, RED); 

    DrawTexture(muted ? muteIcon : unmuteIcon, muteButton.x, muteButton.y, WHITE);
    DrawTexture(returnButtonImage, returnButton.x, returnButton.y, WHITE);
    DrawTexture(saveButtonImage, saveButton.x, saveButton.y, WHITE);     
}
float Volume::GetVolume() const {
    return volume;
}

bool Volume::IsMuted() const {
    return muted;
}

void Volume::SetVolume(float newVolume) {
    volume = newVolume;
}

void Volume::ToggleMute() {
    muted = !muted;
}
