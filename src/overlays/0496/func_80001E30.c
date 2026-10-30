#include "types.h"

typedef struct { u8 p[0x293]; u8 unk293; } A;
extern void func_80B47CFC();
extern void func_800B6490();

void func_80001E30(A *a0, s32 a1) {
    func_80B47CFC(a0, -13);
    if (a0->unk293 == 0) {
        func_800B6490(a0);
    }
}
