// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x44];
    s16 *unk48;
} MapDispBuf;

extern MapDispBuf D_801BF708;
extern s32 D_801BF76C;

s32 MapDisp_IsValidStorey(s32 storey) {
    if (D_801BF708.unk0 == 0 || D_801BF76C == 0) {
        return 0;
    }
    if (storey < 0 || storey >= 6) {
        return 0;
    }
    if (D_801BF708.unk48[storey] != -0x7FFF) {
        return 1;
    }
    return 0;
}
