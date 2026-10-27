// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern s32 D_80000300;
extern M2C_UNK D_800981B0;
extern M2C_UNK D_80098200;
extern M2C_UNK D_80098320;
extern s32 D_801C9E30;
extern s32 D_801C9E34;
extern M2C_UNK D_801F3400;
extern M2C_UNK *D_801F3408;
extern s32 D_801F340C;
extern s32 D_801F3410;
extern s32 D_801F3414;
extern s32 D_801F3418;
extern s32 D_801F341C;
extern s32 D_801F3420;
extern s32 D_801F3424;
extern s32 D_801F3428;
extern s32 D_801F342C;
extern s32 D_801F3430;
extern s16 D_801F344C;
extern s16 D_801F344E;
extern s16 D_801F3450;
extern s16 D_801F3452;
extern s8 D_801F3454;

void func_80179930(void) {
    M2C_FIELD(&D_801F3400, s32 *, 4) = (s32) D_801F341C;
    M2C_FIELD(&D_801F3400, s32 *, 0) = (s32) D_801F3420;
    D_801F340C = D_801F3424;
    D_801F3410 = D_801F3428;
    D_801F3414 = D_801F342C;
    D_801F3418 = D_801F3430;
    D_801F344C = 0x140;
    D_801F344E = 0xF0;
    D_801F3450 = 0;
    D_801F3452 = 0;
    D_801F3454 = 0;
    D_801C9E30 = (s32) D_801F344C;
    D_801C9E34 = (s32) D_801F344E;
    switch (D_80000300) {                           /* irregular */
    case 1:
        D_801F3408 = &D_800981B0;
        return;
    case 2:
        D_801F3408 = &D_80098200;
        /* fallthrough */
    case 0:
        D_801F3408 = &D_80098320;
        return;
    }
}
