#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x14];
    /* 0x0014 */ s16 unk14;
    /* 0x0016 */ u8 pad16[0x463E];
    /* 0x4654 */ void *unk4654;
} Ovl0468Actor;

extern u8 D_80B085C4[];
extern void func_80B083F8();

void func_80000CD4(Ovl0468Actor *this) {
    func_80B083F8(this);
    if (this->unk14 == 0) {
        this->unk4654 = D_80B085C4;
    }
}
