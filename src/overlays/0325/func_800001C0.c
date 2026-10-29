#include "types.h"

typedef struct {
    u8 pad0[0x398];
    s32 unk398;
} S;

extern void func_80A213A8();
extern void func_80A212B0();

void func_800001C0(S *s) {
    s->unk398 = 0;
    func_80A213A8(s);
    func_80A212B0(s);
}
