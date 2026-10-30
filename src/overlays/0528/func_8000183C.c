#include "types.h"
typedef struct { u8 pad[0x2F2]; u16 unk2F2; u8 pad2[4]; void *unk2F8; } A;
extern u8 D_80B7CA8C;
extern void func_80B7B90C();
void func_8000183C(A *a, s32 b) {
    if (a->unk2F2 & 0x40) {
        a->unk2F8 = &D_80B7CA8C;
        func_80B7B90C(a, 3, 0);
    }
}
