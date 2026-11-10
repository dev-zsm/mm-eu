#include "types.h"
typedef struct { char pad0[0x32]; s16 unk32; char pad34[0x8A]; s16 unkBE; char pad[0x110]; void *unk1D0; char pad1D4[6]; s16 unk1DA; } S;
extern s32 D_808ACDAC;
void func_80000D4C(S *arg0) {
    arg0->unk1DA = 0;
    arg0->unk32 = arg0->unkBE;
    arg0->unk1D0 = &D_808ACDAC;
}
