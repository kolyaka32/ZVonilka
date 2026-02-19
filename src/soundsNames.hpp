/*
 * Copyright (C) 2024-2026, Kazankov Nikolay
 * <nik.kazankov.05@mail.ru>
 */

#pragma once

#include "define.hpp"

#if (PRELOAD_SOUNDS)


// Names of sound effects
enum class Sounds : unsigned {
    gabrielBehold,
    gabrielFooleshness,
    gabrielMonetki,
    gabrielParry,
    gabrielDevil,

    highFleetEnd,
    highFleetEvacuation,
    highFleetKill,
    highFleetMissle,
    highFleetNewContact,
    highFleetStop,

    kikorikiButerbrod,
    kikorikiMelody,
    kikorikiFreezer,
    kikorikiHrap,
    kikorikiPogonia,
    kikorikiSkafandr,

    mgrInvisible,
    mgrNanomachine,
    mgrRules,
    mgrBlood,

    mininosDie,
    mininosJudgement,
    mininosPrepare,
    mininosEnd,
    mininosUseless,
    mininosWeak,

    otherKolbasenko,
    otherGoida,
    otherHello,
    otherIcq,
    otherPipe,
    otherNuclearControl,

    sisiphusGone,
    sisiphusDestroy,
    sisiphusHurt,
    sisiphusIt,
    sisiphusEscape,

    windows7Insert,
    windows7Notify,
    windows7Remove,
    windows7Shutdown,
    windows7Startup,
    windows7Stop,

    windowsXPCriticalStop,
    windowsXPDing,
    windowsXPError,
    windowsXPInsert,
    windowsXPRemove,
    windowsXPShutdown,
    windowsXPStartup,

    // Global counter of all loaded sounds
    Count,

    // Shortcut for changing slider sound in settings
    SliderSound = windowsXPCriticalStop,
};

// File names of the corresponding sounds
extern const char* soundsFilesNames[unsigned(Sounds::Count)];

#endif  // (PRELOAD_SOUNDS)
