/*
 * Copyright (C) 2024-2026, Kazankov Nikolay
 * <nik.kazankov.05@mail.ru>
 */

#include "data/app.hpp"
#include "cycles/selectCycle.hpp"
#include "cycles/server.hpp"
#include "cycles/clientLobby.hpp"
#include "cycles/clientMain.hpp"


// Starting cycle
Cycle App::nextCycle = Cycle::Select;

void App::run(Window& _window) {
    logAdditional("\nStart selecting loop");

    // Starting loop of selecting cycles
    while (running) {
        // Selecting new
        switch (nextCycle) {
        case Cycle::Select:
            runCycle<SelectCycle>(_window);
            break;

        case Cycle::Server:
            runCycle<ServerCycle>(_window);
            break;

        case Cycle::ClientLobby:
            runCycle<ClientLobbyCycle>(_window);
            break;

        case Cycle::ClientMain:
            runCycle<ClientMainCycle>(_window);
            break;
        
        default:
            break;
        }
    }
}
