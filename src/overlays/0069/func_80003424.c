#include "types.h"
typedef struct { u8 pad[0x148]; s32 unk148; s32 unk14C; } A;
extern void func_8087E298(A *);
void func_80003424(A *a) {
    a->unk148 = 0;
    a->unk14C = 0;
    func_8087E298(a);
}
