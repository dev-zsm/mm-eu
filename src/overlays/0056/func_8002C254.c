#include "types.h"

extern void func_8082DBC4();
extern void func_8082D16C();
extern void *D_8085B97C[];

typedef struct { u8 pad0[0x14F]; u8 unk14F; } A;

void func_8002C254(s32 a0, A *a, s32 a2) {
    func_8082DBC4(a0, a, D_8085B97C[a->unk14F]);
    func_8082D16C(a);
}
