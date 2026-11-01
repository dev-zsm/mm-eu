#include "types.h"
typedef struct { u8 pad[0x3F4E]; u16 unk3F4E; } G;
extern G D_801E6EF0;
void Audio_PlaySfx(s32);
void Audio_PlaySfx_2(s32);
void Environment_UpdateNextDayTime(void) {
    u16 v;
    s32 t;
    s32 t6;
    v = D_801E6EF0.unk3F4E;
    if (((s32)v >= 0xFF00) && (v != 0xFFFF)) {
        t6 = v - 0x10;
        t = t6 & 0xFFFF;
        D_801E6EF0.unk3F4E = t6;
        if (t == 0xFF0E) {
            Audio_PlaySfx(0x2813);
            D_801E6EF0.unk3F4E = 0xFFFF;
            return;
        }
        if (t == 0xFF0D) {
            Audio_PlaySfx_2(0x28AE);
            D_801E6EF0.unk3F4E = 0xFFFF;
        }
    }
}
