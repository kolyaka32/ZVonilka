/*
 * Copyright (C) 2024-2026, Kazankov Nikolay
 * <nik.kazankov.05@mail.ru>
 */

#pragma once

#include "baseCycle.hpp"


// Game cycle (for single player (special animation))
class ClientMainCycle : public BaseCycle {
 private:
    // Additional text
    GUI::TwoOptionBox disconnectedBox;  // Box with message of disconnection and attemps to reconnect
    GUI::OneOptionBox termianatedBox;   // Box, that connection was closed

    // Main run functions
    bool inputMouseDown() override;
    void update() override;
    void draw() const override;

 public:
    ClientMainCycle(Window& _window);
    ~ClientMainCycle();
};
