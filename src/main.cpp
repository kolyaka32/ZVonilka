/*
 * Copyright (C) 2024-2026, Kazankov Nikolay
 * <nik.kazankov.05@mail.ru>
 */

#include "data/app.hpp"


// Main function
int main(int argv, char **args) {
    // Creating main window
    Window window{512, 512, {"ZVonilka", "ZVонилка", "ZVonilka", "ZVонилка"}};

    // Running menu
    App::run(window);

    // Successful end of program
    return 0;
}
