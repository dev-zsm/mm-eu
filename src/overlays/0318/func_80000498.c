#include "types.h"
typedef struct { u8 pad[0x26C]; s16 unk26C; } B;
typedef struct { u8 pad[0x120]; B *unk120; } A;
void func_80A1B210(void);
void func_80000498(A *a0, s32 a1) {
    B *p = a0->unk120;
    if (p->unk26C >= 0x46) {
        func_80A1B210();
    }
}
