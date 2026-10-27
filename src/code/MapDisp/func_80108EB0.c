// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x44];
    s16 *unk48;
} MapDispBuf;

extern MapDispBuf D_801BF708;
extern s32 D_801BF76C;

s32 MapDisp_IsValidStorey(s32 arg0) {
    if (D_801BF708.unk0 == 0 || D_801BF76C == 0) {
        return 0;
    }
    if (arg0 < 0 || arg0 >= 6) {
        return 0;
    }
    if (D_801BF708.unk48[arg0] != -0x7FFF) {
        return 1;
    }
    return 0;
}
