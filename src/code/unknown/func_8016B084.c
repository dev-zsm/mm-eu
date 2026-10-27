#include "types.h"

typedef struct {
    /* 0x00000 */ u8 pad0[0x1E60];
    /* 0x01E60 */ s32 unk1E60;
    /* 0x01E64 */ u8 pad1E64[0x14];
    /* 0x01E78 */ s32 unk1E78;
    /* 0x01E7C */ s32 unk1E7C;
    /* 0x01E80 */ u8 pad1E80[0x169F5];
    /* 0x18875 */ u8 unk18875;
    /* 0x18876 */ u8 pad18876[4];
    /* 0x1887A */ s16 unk1887A;
    /* 0x1887C */ u8 pad1887C[3];
    /* 0x1887F */ u8 unk1887F;
} PlayState;

typedef struct {
    /* 0x0000 */ u8 pad0[0x3CB0];
    /* 0x3CB0 */ s32 unk3CB0;
    /* 0x3CB4 */ u8 pad3CB4[0x10];
    /* 0x3CC4 */ u16 unk3CC4;
    /* 0x3CC8 */ s32 unk3CC8;
    /* 0x3CCC */ s32 unk3CCC;
    /* 0x3CD0 */ s32 unk3CD0;
} Struct_801E6EF0;

extern void func_8016B054(PlayState *);
extern Struct_801E6EF0 D_801E6EF0;

void func_8016B084(PlayState *play) {
    D_801E6EF0.unk3CC8 = play->unk1E60;
    D_801E6EF0.unk3CCC = play->unk1E78;
    D_801E6EF0.unk3CD0 = play->unk1E7C;
    play->unk1887A = D_801E6EF0.unk3CC4;
    D_801E6EF0.unk3CB0 = 1;
    func_8016B054(play);
    play->unk18875 = 0x14;
    play->unk1887F = 2;
}
