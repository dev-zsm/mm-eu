#include "types.h"

typedef struct {
    s32 v[5];
} Arr5;

extern struct { s32 unk0; u8 pad[0x54]; s16 unk58; } D_801BF708;
extern Arr5 D_801BF7C0;
extern s32 D_801BF76C;

s32 MapDisp_GetBossIconY(void) {
    Arr5 arr = D_801BF7C0;

    if (D_801BF708.unk0 == 0 || D_801BF708.unk58 < 0 || D_801BF708.unk58 >= 5 || D_801BF76C == 0) {
        return 0x7B;
    }
    return arr.v[D_801BF708.unk58];
}
