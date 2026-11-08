// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0373.h"

typedef struct Ob {
    /* 0x000 */ u8 pad0[0x118];
    /* 0x118 */ s16 unk118;
} Ob;

typedef struct Pl {
    /* 0x00000 */ u8 pad0[0x187AC];
    /* 0x187AC */ s16 unk187AC;
    /* 0x187AE */ u8 pad187AE[0x96];
    /* 0x18844 */ u8 unk18844;
} Pl;

typedef struct Pm {
    /* 0x0000 */ u8 pad0[0x1CCC];
    /* 0x1CCC */ Ob *unk1CCC;
} Pm;

void func_800F1D6C();
void func_800B701C();
void func_80A758B4();
void func_8012B3C8();
void func_800B6490();

void func_800019E8(s32 arg0, Pl *arg1) {
    Ob *o = ((Pm *)arg1)->unk1CCC;

    o->unk118 = 0;
    arg1->unk18844 = 0;
    func_800F1D6C(arg1->unk187AC);
    func_800B701C(arg1, 0, 6);
    func_80A758B4();
    func_8012B3C8(0x20);
    func_800B6490(arg0);
}
