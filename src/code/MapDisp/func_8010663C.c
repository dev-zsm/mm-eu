#include "types.h"

typedef struct {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4[0x20];
    /* 0x084 */ s32 unk84[0x20];
    /* 0x104 */ s32 unk104[0x20];
    /* 0x184 */ s32 unk184;
} MapIState;

typedef struct {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ s32 unk20;
} Struct_801BF708;

extern MapIState D_801ECF30;
extern Struct_801BF708 D_801BF708;

void MapDisp_ResetMapI(void) {
    s32 i;

    D_801ECF30.unk0 = 0;
    for (i = 0; i < 0x20; i++) {
        D_801ECF30.unk4[i] = 0;
        D_801ECF30.unk84[i] = 0;
        D_801ECF30.unk104[i] = 0;
    }
    D_801ECF30.unk184 = 0;
    D_801BF708.unk20 &= ~1;
}
