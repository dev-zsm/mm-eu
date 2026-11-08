#include "types.h"

typedef struct {
    s32 unk0;
    u8 pad4[4];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0xC];
    s32 unk24;
} Fn80105934State;

typedef struct {
    u8 pad0[0x16F86];
    s16 unk16F86;
} Fn80105934Ctx;

extern Fn80105934State D_801BF708;
extern s16 D_801BF74A;
extern s32 D_801BF76C;

void MapDisp_Update(Fn80105934Ctx *arg0) {
    if (D_801BF708.unk0 != 0 && D_801BF76C != 0) {
        D_801BF74A = 8 - arg0->unk16F86;
        if (D_801BF708.unk14 != -1) {
            if (D_801BF708.unk24 > 0) {
                if (D_801BF708.unkC != D_801BF708.unk8) {
                    D_801BF708.unkC = (s32)((f32)(D_801BF708.unk8 - D_801BF708.unkC) / (f32)D_801BF708.unk24 +
                                            (f32)D_801BF708.unkC);
                }
                if (D_801BF708.unkE != D_801BF708.unkA) {
                    D_801BF708.unkE = (s32)((f32)(D_801BF708.unkA - D_801BF708.unkE) / (f32)D_801BF708.unk24 +
                                            (f32)D_801BF708.unkE);
                }
                D_801BF708.unk24 = D_801BF708.unk24 - 1;
                return;
            }
            D_801BF708.unk14 = -1;
            D_801BF708.unk24 = 0;
            D_801BF708.unkC = D_801BF708.unk8;
            D_801BF708.unkE = D_801BF708.unkA;
            return;
        }
        D_801BF708.unk24 = 0;
    }
}
