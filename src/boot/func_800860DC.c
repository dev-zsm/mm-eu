#include "types.h"

extern void func_800855E0(void);

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[7];
    u8 unkF;
} Func800860DCStruct;

void func_800860DC(Func800860DCStruct *arg0, s32 arg1) {
    u8 temp_v0;

    temp_v0 = arg0->unkF;
    if (!(temp_v0 & 0x80)) {
        arg0->unkF = temp_v0 | 0x80;
        arg0->unk4 = arg1;
        func_800855E0();
    }
}

