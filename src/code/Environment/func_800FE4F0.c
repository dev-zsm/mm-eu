#include "types.h"

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} E4F0Ptr;

typedef struct {
    u8 pad0[0xC];
    u16 unkC;
    u8 padE[6];
    s32 unk14;
} E4F0Data;

extern E4F0Ptr *D_801EB7E0;
extern E4F0Data D_801E6EF0;

s32 func_800FE4F0(s32 arg0, s16 arg1, s16 arg2) {
    s32 ret = 0;
    s32 v = D_801EB7E0->unk32; /* s32 (not s16) and the separate c local only fix register allocation */
    u16 c;
    u16 limit;
    if (v != 0) {
        c = D_801E6EF0.unkC;
        limit = (D_801E6EF0.unk14 + v) * arg1 * 20 + c;
        if (arg2 < limit) {
            ret = 1;
        }
    }
    return ret;
}
