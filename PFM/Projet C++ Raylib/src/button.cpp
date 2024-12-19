#include "button.h"
#include "raylib.h"
#include <string>

Button::Button(const std::string& text, int x, int y, int width, int height) 
    : text(text), rect{ (float)x, (float)y, (float)width, (float)height },
      defaultColor(DARKGRAY), hoverColor(LIGHTGRAY), currentColor(DARKGRAY) {}

bool Button::IsHovered() const {
    Vector2 mousePoint = GetMousePosition();
    return CheckCollisionPointRec(mousePoint, rect);
}

bool Button::IsClicked() const {
    return IsHovered() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Button::Draw() {
    currentColor = IsHovered() ? hoverColor : defaultColor;

    DrawRectangleRec(rect, currentColor);

    int fontSize = 20;
    int textWidth = MeasureText(text.c_str(), fontSize);
    int textHeight = fontSize;
    Vector2 textPosition = {
        rect.x + rect.width / 2 - textWidth / 2,
        rect.y + rect.height / 2 - textHeight / 2
    };

    DrawText(text.c_str(), textPosition.x, textPosition.y, fontSize, BLACK);
}
Rectangle Button::GetRect() const {
    return rect;
}