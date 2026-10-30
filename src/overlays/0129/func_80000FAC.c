#include "types.h"
typedef struct { u8 pad0[0x15C]; s32 unk15C; } A;
extern void (*D_808F92CC[])();
void func_80000FAC(A *a0) {
    void (*f)() = D_808F92CC[a0->unk15C];
    if (f != 0) {
        f();
    }
}
