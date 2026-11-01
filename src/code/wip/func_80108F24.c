#include "types.h"
typedef struct { s32 unk0; u8 pad4[0x3C]; s16 unk40; u8 pad42[6]; s16 *unk48; } MapS;
extern MapS D_801BF708;
extern s32 D_801BF76C;
s32 MapDisp_GetPlayerStorey(s16 a) {
    s16 i;
    s32 n;
    s16 *p;
    if (D_801BF708.unk0 == 0 || D_801BF76C == 0) {
        return -1;
    }
    n = D_801BF708.unk40;
    if (n < 2) {
        return 0;
    }
    p = D_801BF708.unk48;
    if (p[1] - 5 >= a) {
        return 0;
    }
    for (i = 1; i < n; i++) {
        if (p[i] - 5 < a && p[i + 1] - 5 >= a) {
            return i;
        }
    }
    return n - 1;
}
