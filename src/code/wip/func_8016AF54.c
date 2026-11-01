#include "types.h"
typedef struct { u8 pad[0x20]; } E;
typedef struct { s32 w0, w4, w8; } V3w;
typedef struct { u8 pad1E60[0x1E60]; s32 u1E60; u8 pad1E64[0x14]; s32 u1E78; s32 u1E7C; } Play;
extern E D_801E6EF0[];
s16 Entrance_Create(s32, s32, s32);
void func_8016AF54(Play *play, s32 idx, u16 a2, s32 a3, s32 a4, V3w *a5, s16 a6) {
    u8 *e;
    s16 r = Entrance_Create(a2 >> 9, 0, a2 & 0xF);
    e = (u8 *)&D_801E6EF0[idx];
    *(s16 *)(e + 0x3CC4) = r;
    *(s8 *)(e + 0x3CC6) = a3;
    *(s32 *)(e + 0x3CB4) = a5->w0;
    *(s32 *)(e + 0x3CB8) = a5->w4;
    *(s16 *)(e + 0x3CC0) = a6;
    *(s16 *)(e + 0x3CC2) = a4;
    *(s32 *)(e + 0x3CBC) = a5->w8;
    *(s32 *)(e + 0x3CC8) = play->u1E60;
    *(s32 *)(e + 0x3CCC) = play->u1E78;
    *(s32 *)(e + 0x3CD0) = play->u1E7C;
}
