#include "types.h"
typedef struct { u8 pad[0x164]; void (*unk164)(); } A;
extern void func_80BA9550();
void func_800005A4(A *a, s32 b) {
    func_80BA9550(a, b);
    a->unk164(a, b);
}
