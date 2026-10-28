#include "types.h"

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    u8 pad0E[0xA];
    u64 unk18;
} S;

extern s32 SysFlashrom_IsBusy(void);
extern s32 SysFlashrom_AwaitResult(void);
extern u64 func_800905C0(void);
extern u64 func_80088B48(u64, u64);
extern u64 func_80088A48(u64, u64);

void func_8014756C(S *s) {
    u64 t;

    if (s->unkC == 2) {
        if (SysFlashrom_IsBusy()) {
            if (!SysFlashrom_AwaitResult()) { // both arms store 4, kept as the ROM branches
                s->unkC = 4;
            } else {
                s->unkC = 4;
            }
        }
    } else {
        t = func_80088B48(func_800905C0() - s->unk18, 0x40);
        t = func_80088A48(t, 0xBB8);
        t = func_80088A48(t, 0x2710);
        if (t >= 200) {
            s->unkC = 0;
        }
    }
}
