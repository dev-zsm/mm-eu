// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_sram_NES.h"

void Sram_GenerateRandomSaveFields(void) {
    s32 randBombers;
    s16 sp2A;
    s16 pad;
    s16 i;
    s16 j;
    s32 k;
    s16 randSpiderHouse;

    Sram_ClearHighscores();

    gSaveContext.save.saveInfo.lotteryCodes[0][0] = Rand_S16Offset(0, 10);
    gSaveContext.save.saveInfo.lotteryCodes[0][1] = Rand_S16Offset(0, 10);
    gSaveContext.save.saveInfo.lotteryCodes[0][2] = Rand_S16Offset(0, 10);
    gSaveContext.save.saveInfo.lotteryCodes[1][0] = Rand_S16Offset(0, 10);
    gSaveContext.save.saveInfo.lotteryCodes[1][1] = Rand_S16Offset(0, 10);
    gSaveContext.save.saveInfo.lotteryCodes[1][2] = Rand_S16Offset(0, 10);
    gSaveContext.save.saveInfo.lotteryCodes[2][0] = Rand_S16Offset(0, 10);
    gSaveContext.save.saveInfo.lotteryCodes[2][1] = Rand_S16Offset(0, 10);
    gSaveContext.save.saveInfo.lotteryCodes[2][2] = Rand_S16Offset(0, 10);

    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {}
    }

    i = 0;
    sp2A = Rand_S16Offset(0, 16) & 3;
    k = 6;
    while (i != k) {
        randSpiderHouse = Rand_S16Offset(0, 16) & 3;
        if (sp2A != randSpiderHouse) {
            gSaveContext.save.saveInfo.spiderHouseMaskOrder[i] = randSpiderHouse;
            i++;
            sp2A = randSpiderHouse;
        }
    }

    do {
        randBombers = Rand_S16Offset(0, 6);
    } while ((randBombers <= 0) || (randBombers >= 6));

    gSaveContext.save.saveInfo.bomberCode[0] = randBombers;

    i = 1;
    while (i != 5) {
        k = false;

        do {
            randBombers = Rand_S16Offset(0, 6);
        } while ((randBombers <= 0) || (randBombers >= 6));

        sp2A = 0;
        do {
            if (randBombers == gSaveContext.save.saveInfo.bomberCode[sp2A]) {
                k = true;
            }
            sp2A++;
        } while (sp2A < i);

        if (k == false) {
            gSaveContext.save.saveInfo.bomberCode[i] = randBombers;
            i++;
        }
    }
}
