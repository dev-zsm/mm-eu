#include "types.h"

typedef struct {
    u8 pad0[0xA6C];
    u32 unkA6C;
} Player420;

typedef struct {
    u8 pad0[0x1CCC];
    Player420 *unk1CCC;
} Play420;

extern void func_800B6490();

void func_80000F9C(s32 a0, Play420 *a1) {
    a1->unk1CCC->unkA6C &= ~0x20;
    func_800B6490(a0);
}
