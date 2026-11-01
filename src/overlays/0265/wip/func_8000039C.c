// matching: only the parent/value register pair is swapped (v0/t6)
#include "types.h"

typedef struct {
    u8 pad0[0x4];
    u32 flags;
    u8 pad8[0x118];
    u8 *parent;
    u8 pad124[0x154];
    void *unk278;
    s16 unk27C;
    u8 pad27E[0xCF];
    u8 unk34D;
    u8 pad34E[0x16A];
    s16 unk4B8;
} A;

extern u8 D_809929F8[];

void func_8000039C(A *this) {
    s16 v = *(s16 *)(this->parent + 0x15A);

    this->unk34D = 5;
    this->unk27C = 0;
    this->flags |= 0x100000;
    this->unk278 = D_809929F8;
    this->unk4B8 = v;
}
