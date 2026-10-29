#include "types.h"

extern s32 Player_InCsMode();
extern s32 LifeMeter_IsCritical();
extern s32 Play_InCsMode();
extern void Audio_PlaySfx();

void LifeMeter_UpdateSizeAndBeep(u8 *a0) {
    s16 *p = (s16 *)(a0 + 0x169E8);

    if (*(s16 *)(a0 + 0x16C3C) != 0) {
        p[0x252 / 2] -= 1;
        if (p[0x252 / 2] <= 0) {
            p[0x252 / 2] = 0;
            p[0x254 / 2] = 0;
            if (Player_InCsMode() == 0 && *(u16 *)(a0 + 0x16F1C) == 0 && *(u16 *)(a0 + 0x16F1E) == 0 &&
                LifeMeter_IsCritical(a0) != 0 && Play_InCsMode(a0) == 0) {
                Audio_PlaySfx(0x481B);
            }
        }
    } else {
        p[0x252 / 2] += 1;
        if (p[0x252 / 2] >= 10) {
            p[0x252 / 2] = 10;
            p[0x254 / 2] = 1;
        }
    }
}
