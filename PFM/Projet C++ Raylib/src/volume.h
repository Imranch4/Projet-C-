#ifndef VOLUME_H
#define VOLUME_H

#include "raylib.h"
#include "game.h"

class Volume {
public:
    Volume();
    ~Volume(); 
    
    void Init();   
    GameScreen Update(Music &music);
    void Draw();  
    
    float GetVolume() const; 
    bool IsMuted() const;
    
    void SetVolume(float volume);
    void ToggleMute();   

private:
    float volume;  
    bool muted;
    Font customFont;
    Rectangle volumeBar;
    Texture2D saveButtonImage, returnButtonImage;  
    Rectangle muteButton; 
    Texture2D muteIcon;
    Texture2D unmuteIcon; 
    Rectangle saveButton, returnButton;
        float Clamp(float value, float min, float max) const {
        return (value < min) ? min : (value > max) ? max : value;
    }
};

#endif // VOLUME_H
