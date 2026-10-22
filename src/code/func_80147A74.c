// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80147A30();                            /* extern */
extern s16 D_801EE380;
extern s16 D_801EE382;
extern s16 D_801EE384;
extern s16 D_801EE386;
extern s16 D_801EE388;
extern s16 D_801EE38A;
extern s16 D_801EE38C;
extern s16 D_801EE38E;
extern s16 D_801EE390;
extern s16 D_801EE392;
extern s16 D_801EE394;
extern s16 D_801EE396;

void func_80147A74(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16956) = 0xBD;
    M2C_FIELD(arg0, s16 *, 0x16958) = 0xB8;
    M2C_FIELD(arg0, s16 *, 0x1695A) = 0xB3;
    M2C_FIELD(arg0, s16 *, 0x1695C) = 0xAE;
    M2C_FIELD(arg0, s16 *, 0x1695E) = 0xA9;
    func_80147A30();
    D_801EE380 = 0x50;
    D_801EE384 = 0x96;
    D_801EE382 = 0xFF;
    D_801EE386 = 0xA;
    D_801EE38A = 0xA;
    D_801EE388 = 0xA;
    D_801EE38C = 0xFF;
    D_801EE390 = 0xFF;
    D_801EE38E = 0x32;
    D_801EE392 = 0xA;
    D_801EE396 = 0xA;
    D_801EE394 = 0xA;
}
