#include "types.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
} Struct_80171CA0;

extern void func_80171150(Struct_80171CA0 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);

void func_80171CA0(Struct_80171CA0 *a0, s32 a1, s32 a2) {
    func_80171150(a0, a1, a0->unk14, a0->unk10, 0xFF, 0xFF, 0xFF, a2);
}
