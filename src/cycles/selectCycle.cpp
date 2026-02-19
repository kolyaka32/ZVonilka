/*
 * Copyright (C) 2024-2026, Kazankov Nikolay
 * <nik.kazankov.05@mail.ru>
 */

#include "selectCycle.hpp"


// Starting basic template with main theme
SelectCycle::SelectCycle(Window& _window)
: BaseCycle(_window),
titleText(window, 0.5, 0.15, {"ZVonilka", "ZVонилка", "ZVonilka", "ZVонилка"}, 3, Height::Title),
serverButton(window, 0.5, 0.7, {"Create server", "Создать сервер", "Server erstellen", "Стварыць сервер"}),
connectButton(window, 0.5, 0.9, {"Connect", "Присоединиться", "Beitreten", "Далучыцца"}) {
    // Starting menu song (if wasn't started)
    logAdditional("Start select cycle");
}

// Getting selected button
bool SelectCycle::inputMouseDown() {
    if (settings.click(mouse)) {
        return true;
    }
    if (serverButton.in(mouse)) {
        App::setNextCycle(Cycle::Server);
        return true;
    }
    if (connectButton.in(mouse)) {
        App::setNextCycle(Cycle::ClientLobby);
        return true;
    }
    return false;
}

void SelectCycle::inputKeys(SDL_Keycode _key) {
    switch (_key) {
    case SDLK_ESCAPE:
        settings.activate();
        return;
    }
}

void SelectCycle::update() {
    BaseCycle::update();
}

void SelectCycle::draw() const {
    // Bliting background
    window.setDrawColor(BLACK);
    window.clear();

    // Bliting title
    titleText.blit();

    // Blitting start buttons
    serverButton.blit();
    connectButton.blit();

    // Settings menu
    settings.blit();

    // Bliting all to screen
    window.render();
}
