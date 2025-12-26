#pragma once

struct ButtonState {
    bool isDown;
    bool changed;
};

enum {
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    LEFT_MOUSE,

    BUTTON_COUNT
};

struct Input {
    ButtonState buttons[BUTTON_COUNT];
};