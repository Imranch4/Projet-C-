#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include <string>

class Button {
public:
    Button(const std::string& text, int x, int y, int width, int height);

    bool IsHovered() const;
    bool IsClicked() const;
    void Draw();
    Rectangle GetRect() const;

private:
    std::string text;
    Rectangle rect;
    Color defaultColor;
    Color hoverColor;
    Color currentColor;
};

#endif // BUTTON_H