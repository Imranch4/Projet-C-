#include "raylib.h"
#include "menu.h"
#include "settings.h"
#include "difficulty.h"
#include "solocontrols.h"
#include "easysolomode.h"
#include "mediumsolomode.h"
#include "hardsolomode.h"
#include "volume.h"
#include "resolution.h"

int main() {
    
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Maze");
    InitAudioDevice();
    SetTargetFPS(240); 

    Texture2D background = LoadTexture("images/Background.jpg");
    if (background.width == 0 || background.height == 0) {
        return -1;
    }

    Music music = LoadMusicStream("Sounds/music.mp3");
    if (music.stream.buffer == nullptr) { 
        UnloadTexture(background);
        CloseAudioDevice();
        CloseWindow();
        return -1;
    }
    PlayMusicStream(music);
    SetMusicVolume(music, 0.5f);

    Font customFont = LoadFont("Font/monogram.ttf");  

    GameScreen currentScreen = MENU;
    Menu menu;
    Settings settings;
    Difficulty difficulty;
    Solocontrols solocontrols;
    Easysolomode easysolomode;
    Mediumsolomode mediumsolomode;
    Hardsolomode hardsolomode;
    Volume volume;
    Resolution resolution;

    while (!WindowShouldClose()) {
        
  
        UpdateMusicStream(music);

        if (GetMusicTimePlayed(music) >= GetMusicTimeLength(music)) {
            StopMusicStream(music);
            PlayMusicStream(music);
        }

        switch (currentScreen) {
            case MENU:
                currentScreen = menu.Update();
                break;
            case SETTINGS:
                currentScreen = settings.Update();
                break;
            case DIFFICULTY:
                currentScreen = difficulty.Update();
                break;
            case SOLOCONTROLS:
                currentScreen = solocontrols.Update();
                break;
            case EASYSOLOMODE:
                currentScreen = easysolomode.Update();
                break;
            case MEDIUMSOLOMODE:
                currentScreen = mediumsolomode.Update();
                break;
            case HARDSOLOMODE:
                currentScreen = hardsolomode.Update();
                break;                                                
            case VOLUME:
                currentScreen = volume.Update(music); 
                break;
            case RESOLUTION:
                currentScreen = resolution.Update();
                break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        switch (currentScreen) {
            case MENU:
                menu.Draw();
                break;
            case SETTINGS:
                settings.Draw();
                break;
            case DIFFICULTY:
                difficulty.Draw();
                break;
            case SOLOCONTROLS:
                solocontrols.Draw();
                break;
            case EASYSOLOMODE:
                easysolomode.Draw();
                break;
            case MEDIUMSOLOMODE:
                mediumsolomode.Draw();
                break;
            case HARDSOLOMODE:
                hardsolomode.Draw();
                break;                                                
            case VOLUME:
                volume.Draw();
                break;
            case RESOLUTION:
                resolution.Draw();
                break;
        }

        EndDrawing();
    }

    UnloadTexture(background); 
    UnloadMusicStream(music);  
    UnloadFont(customFont); 

    CloseWindow();

    return 0;
}
