#include "types.h"
typedef struct {
    u8 pad0[0x20C];
    void *unk20C;
    u8 pad210[0xC];
    s16 unk21C;
} A;
extern u8 D_80AA0004[];
void func_80A9FF40();
void func_800001BC(A *a0) {
    func_80A9FF40(a0, 0);
    a0->unk21C = 0;
    a0->unk20C = D_80AA0004;
}
