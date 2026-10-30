#include "types.h"

typedef struct { u8 pad[0x170]; u16 unk170; } A;
extern u16 D_801E6EFC;
extern void func_80A97D40();
extern void func_80A989FC();

void func_800018B0(A *a0, s32 a1) {
    a0->unk170 = D_801E6EFC;
    func_80A97D40(a0, 1);
    func_80A989FC(a0, a1);
}
