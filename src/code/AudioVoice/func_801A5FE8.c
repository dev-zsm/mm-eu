// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xA];
    u16 unkA;
} Ent;

extern u8 D_801D176C;
extern Ent *D_801D1770;
extern u16 D_801D1774;
extern u8 D_801D1778;
extern void func_801A5D88(void);
extern Ent *func_801A6260(void);
extern s32 func_801A66D8(void);

void AudioVoice_Update(void) {
    if (D_801D176C & 2) {
        D_801D176C = D_801D176C & 1;
        func_801A5D88();
    }
    if (D_801D176C != 0) {
        if (func_801A66D8() != 0) {
            D_801D1778++;
            if (D_801D1778 == 10) {
                D_801D176C = 0;
                D_801D1774 = 0xFFFF;
                return;
            }
        } else {
            D_801D1778 = 0;
        }
        D_801D1770 = func_801A6260();
        if (D_801D1770 != NULL) {
            D_801D1774 = D_801D1770->unkA;
        } else {
            D_801D1774 = 0xFFFF;
        }
    }
}
