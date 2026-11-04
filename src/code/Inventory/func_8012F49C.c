// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_inventory.h"

void Inventory_SaveDekuPlaygroundHighScore(s16 timerId) {
    s16 i;

    gSaveContext.save.saveInfo.dekuPlaygroundHighScores[CURRENT_DAY - 1] = gSaveContext.timerCurTimes[timerId];

    for (i = 0; i < 8; i++) {
        gSaveContext.save.saveInfo.inventory.dekuPlaygroundPlayerName[CURRENT_DAY - 1][i] =
            gSaveContext.save.saveInfo.playerData.playerName[i];
    }
}
