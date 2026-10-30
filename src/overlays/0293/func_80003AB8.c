#include "types.h"

typedef struct { u8 pad[0x1EE]; s16 unk1EE; } A;
extern void func_80181508(s16, s32);

s32 func_80003AB8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, A *a5) {
    if (a1 == 0xF) {
        func_80181508(a5->unk1EE, 1);
    }
    return 0;
}
