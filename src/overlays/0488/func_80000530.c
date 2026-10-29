#include "types.h"

typedef struct {
    u32 unk0;
    u8 pad4[0x18];
} Ovl0488Ent;

typedef struct {
    u8 pad0[0x10C];
    Ovl0488Ent ent[1];
} Ovl0488Tbl;

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
} Ovl0488Actor;

extern Ovl0488Tbl D_801E6EF0;

void func_80000530(Ovl0488Actor *a) {
    D_801E6EF0.ent[a->unkA4].unk0 &= ~7;
}
