#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    u8 pad0[0xC];
    u16 unkC;
    u8 pad0E[6];
    u16 unk14;
    u8 pad16[0xE];
    u16 unk24;
} Info;
typedef struct {
    u8 pad0[8];
    Info *info;
    u8 pad0C[0x58];
} Slot;
void func_800C72FC(u8 *a0, s32 *a1, s32 *a2, s32 *a3) {
    u8 *p;
    s32 i;
    int f;
    Info *info;
    *a1 = 0;
    *a2 = 0;
    *a3 = 0;
    i = 0;
    p = a0;
    for (; i != 0x32; i += 2) {
        f = *((u16 *) (p + 0x138C));
        if (((f & 1) && (!(f & 2))) && (!(f & 4))) {
            info = ((Slot *) a0)[i].info;
            *a1 += info->unk14;
            *a2 += info->unkC;
            *a3 += info->unk24;
        }
        f = *((u16 *) (p + 0x138E));
        if (((f & 1) && (!(f & 2))) && (!(f & 4))) {
            info = ((Slot *) a0)[i + 1].info;
            *a1 += info->unk14;
            *a2 += info->unkC;
            *a3 += info->unk24;
        }
        p += 4;
    }

}
