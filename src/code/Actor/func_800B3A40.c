#include "types.h"

extern void func_800843FC(s32, s32);
extern void func_8008482C(void *, ...);
extern s32 D_801B5140;
extern u8 D_801D4A60[];
extern u8 D_801D4A68[];
extern u8 D_801D4A88[];
extern u8 D_801D4AA0[];

typedef struct Ent {
    s16 unk0;
    u8 unk2;
    u8 pad3[0x129];
    struct Ent *next;
} Ent;

void Actor_PrintLists(u8 *ctx) {
    s32 i;
    Ent *e;
    u8 *p;

    func_800843FC(-2, 0);
    func_8008482C(D_801D4A60, D_801B5140);
    func_8008482C(D_801D4A68);

    for (i = 0, p = ctx + 0x10; i != 0xC; i++, p += 0xC) {
        for (e = *(Ent **)(p + 4); e != 0; e = e->next) {
            func_8008482C(D_801D4A88, i, e, e->unk0, e->unk2, D_801D4AA0);
        }
    }
}
