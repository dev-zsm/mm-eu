#include "types.h"
typedef struct { u8 pad0[0x134]; s16 unk134, unk136, unk138, unk13A, unk13C, unk13E, unk140; u8 pad142[6]; s16 unk148; s16 unk14A; } G;
extern G *D_801EB7E0;
extern u8 D_80097780[];
extern u8 D_80098320[];
extern void ViMode_LogPrint(void *, s32);
void ViMode_Save(u8 *arg0) {
    s16 mode;
    D_801EB7E0->unk134 = *(s32 *)(arg0 + 0x68);
    D_801EB7E0->unk136 = *(s32 *)(arg0 + 0x54);
    D_801EB7E0->unk138 = *(s32 *)(arg0 + 0x50);
    D_801EB7E0->unk13A = *(s32 *)(arg0 + 0x64);
    D_801EB7E0->unk13C = *(s32 *)(arg0 + 0x60);
    D_801EB7E0->unk13E = *(s32 *)(arg0 + 0x5C);
    D_801EB7E0->unk140 = *(s32 *)(arg0 + 0x58);
    if (D_801EB7E0->unk148 == 1) {
        D_801EB7E0->unk148 = 0;
        mode = D_801EB7E0->unk14A;
        switch (mode) {
            case 1:
                ViMode_LogPrint(D_80097780, mode);
                break;
            case 2:
                ViMode_LogPrint(D_80098320, mode);
                break;
            default:
                ViMode_LogPrint(arg0, mode);
                break;
        }
    }
}
