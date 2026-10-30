#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x254];
    /* 0x254 */ void *unk254;
    /* 0x258 */ u8 pad258[0x20];
    /* 0x278 */ s16 unk278;
} Ovl0597Actor;

extern u8 D_80BCDFB4[];
extern void func_80BCDE5C();

void func_800002BC(Ovl0597Actor *this) {
    func_80BCDE5C(this, 0);
    this->unk278 = 0;
    this->unk254 = D_80BCDFB4;
}
