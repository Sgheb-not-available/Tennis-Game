#pragma once

struct ButtonState {
    bool isDown;
    bool changed;
};

enum {
    BUTTON_F11, 
    LEFT_MOUSE,

    BUTTON_COUNT
};

struct Input {
    ButtonState buttons[BUTTON_COUNT];
};