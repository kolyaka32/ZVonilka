/*
 * Copyright (C) 2024-2026, Kazankov Nikolay
 * <nik.kazankov.05@mail.ru>
 */

#include "clientMain.hpp"
#include "../internet/internet.hpp"


ClientMainCycle::ClientMainCycle(Window& _window)
: BaseCycle(_window),
disconnectedBox(window, {"Connection lost", "Соединение потярено", "Verbindung verloren", "Злучэнне страчана"},
    {"Reconnect", "Переприсоединится", "Wiederverbinden", "Паўторна падлучыцца"},
    {"Close", "Закрыть", "Schließen", "Зачыніць"}),
termianatedBox(window, {"Connection terminated", "Соединение разорвано", "Verbindung unterbrochen", "Злучэнне разарвана"},
    {"Close", "Закрыть", "Schließen", "Зачыніць"}) {
    // Resetting flag
    if (!isRestarted()) {
        disconnectedBox.reset();
        termianatedBox.reset();
    }
    logAdditional("Start client main cycle");
}

ClientMainCycle::~ClientMainCycle() {
    if (!isRestarted()) {
        // Sending message of disconect
        internet.disconnect();
        // Clear getting socket
        internet.close();
    }
}

bool ClientMainCycle::inputMouseDown() {
    if (BaseCycle::inputMouseDown()) {
        return true;
    }
    if (int code = termianatedBox.click(mouse)) {
        if (code == 2) {
            // Quiting to menu
            App::setNextCycle(Cycle::Select);
        }
        // Not allowing to any another actions
        return true;
    }
    if (int code = disconnectedBox.click(mouse)) {
        if (code == 2) {
            // Trying to reconnect
            internet.sendAll({ConnectionCode::ApplyConnection});
        } else if (code == 3) {
            // Going to menu
            App::setNextCycle(Cycle::Select);
        }
        // Not allowing to any another actions
        return true;
    }
    return false;
}

void ClientMainCycle::update() {
    // Basic update
    BaseCycle::update();
    // Getting messages
    while (const GetPacket* packet = internet.getNewMessages()) {
        // Getting internet messages
        switch (ConnectionCode(packet->getData<Uint8>(0))) {
        case ConnectionCode::Quit:
            termianatedBox.activate();
            break;

        default:
            return;
        }
    }
    // Checking applied messages
    internet.checkResendMessages();

    // Appling status
    internet.checkNeedApplyConnection();

    // Checking status
    if (internet.checkStatus()) {
        disconnectedBox.activate();
    } else {
        disconnectedBox.reset();
    }
}

void ClientMainCycle::draw() const {
    // Bliting background
    window.setDrawColor(BLACK);
    window.clear();

    // Drawing upper dashboard
    exitButton.blit();
    settings.blit();

    // Messages
    disconnectedBox.blit();
    termianatedBox.blit();

    // Bliting all to screen
    window.render();
}
