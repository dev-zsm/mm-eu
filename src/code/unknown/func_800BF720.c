#include "types.h"

typedef struct {
    u8 pad0[8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 pad14[0xA];
    s8 unk1E;
    u8 pad1F;
} Ent;

extern void func_800843FC(s32, s32);
extern void func_8008482C(void *, ...);
extern s32 D_801B5140;
extern Ent D_801AFB00[];
extern u8 D_801D4C40[];
extern u8 D_801D4C54[];
extern u8 D_801D4C74[];
extern u8 D_801D4C8C[];

void func_800BF720(s32 a0, s32 a1) {
    s32 i;
    Ent *e;
    s32 size;

    func_800843FC(-2, 0);
    func_8008482C(D_801D4C40, D_801B5140);
    func_8008482C(D_801D4C54);
    e = D_801AFB00;
    for (i = 0; i < D_801B5140; i++, e++) {
        size = e->unkC - e->unk8;
        if (e->unk10 != 0) {
            func_8008482C(D_801D4C74, i, e->unk10, e->unk10 + size, e->unk1E, D_801D4C8C);
        }
    }
}
