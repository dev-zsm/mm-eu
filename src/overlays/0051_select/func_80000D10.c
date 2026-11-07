// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_select.h"

void MapSelect_PrintAgeSetting(MapSelectState* this, GfxPrint* printer, s32 playerForm) {
    s32 pad;
    const char* age;
    const char*(*ageTemp)[2];
    const char*(*phi_v1)[2];
    s32 phi_v0;

    if ((playerForm >= PLAYER_FORM_FIERCE_DEITY) && (playerForm < PLAYER_FORM_MAX)) {
        ageTemp = &sFormLabel[playerForm];
        phi_v1 = ageTemp + 1;

        
        for (phi_v0 = 8; phi_v0 >= 0; phi_v0 -= 8) {
            if (phi_v1 != 0) {
                break;
            }
            phi_v1--;
        }
        if (phi_v1) {}

        age = (*ageTemp)[0];
    } else {
        age = NULL;
    }

    GfxPrint_SetPos(printer, 4, 26);
    GfxPrint_SetColor(printer, 255, 255, 55, 255);
    if (age != NULL) {
        GfxPrint_Printf(printer, "Age:%s", age);
    } else {
        
        GfxPrint_Printf(printer, "Age:???" "(%d)", playerForm);
        
    }
}
