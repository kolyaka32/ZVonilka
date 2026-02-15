/*
 * Copyright (C) 2024-2026, Kazankov Nikolay
 * <nik.kazankov.05@mail.ru>
 */

#include "data/preloaded/loader/loader.hpp"
#include "data/libraries.hpp"
#include "data/initFile.hpp"
#include "internet/internet.hpp"
#include "cycles/selectCycle.hpp"  // Start game cycle


// Initialasing global objects in correct order
// Logger
#if (CHECK_ALL)
std::ofstream logFile{"log.txt"};
#endif

// All side libries
Libraries libraries{};

#if (PRELOAD_DATA)
const DataLoader dataLoader{};
#endif

#if (PRELOAD_MUSIC)
MusicData music{};
#endif

#if (PRELOAD_SOUNDS)
SoundsData sounds{};
#endif

#if (USE_NET)
Internet internet{};
#endif

// Loading/unloading all parameters
#if (USE_SETTING_FILE)
InitFile initFile{};
#endif

// Main function
int main(int argv, char **args) {
    // Creating main window
    Window window{512, 512, {"ZVonilka", "Zвонилка", "Tic-tac-toe", "Крыжыкі нулікі"}};

    // Running menu
    App::run(window);

    // Successful end of program
    return 0;
}
