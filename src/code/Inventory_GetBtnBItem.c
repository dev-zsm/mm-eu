#include "types.h"

typedef struct {
    u8 pad0[0x20];
    u8 unk20;
} SD;

typedef struct {
    u8 pad0[0x16C04];
    s16 unk16C04;
    s16 unk16C06;
} Ctx;

extern SD D_801E6EF0;

s32 Inventory_GetBtnBItem(Ctx *arg0) {
    s32 i;
    s16 t;

    if (*(u8 *)((u8 *)&D_801E6EF0 + 0x3F18) == 0xFF) {
        return 0xFF;
    }
    if (*(u8 *)((u8 *)&D_801E6EF0 + 0x1015) == 0xFF) {
        return 0xFF;
    }
    i = (D_801E6EF0.unk20 == 4) ? 0 : D_801E6EF0.unk20;
    if (*((u8 *)&D_801E6EF0 + 0x4C + i * 4) == 0xFF) {
        if (arg0->unk16C04 != 0) {
            t = arg0->unk16C06;
            if (t != 0) {
                return t;
            }
        }
        return 0xFF;
    }
    i = (D_801E6EF0.unk20 == 4) ? 0 : D_801E6EF0.unk20;
    return *((u8 *)&D_801E6EF0 + 0x4C + i * 4);
}
