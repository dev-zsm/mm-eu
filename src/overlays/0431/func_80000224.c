#include "types.h"

typedef struct { u8 pad[0x226]; s16 unk226; } A;
extern void func_80181508(s16, s32);

s32 func_80000224(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, A *a5) {
    if (a1 == 0x12) {
        func_80181508(a5->unk226, 1);
    }
    return 0;
}
