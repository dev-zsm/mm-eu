// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x24];
    u16 unk24;
    u8 pad26[2];
    u8 *unk28;
} Box;

typedef struct {
    u8 pad0[2];
    s16 unk2;
    u8 pad4[12];
} Ent;

typedef struct {
    u8 pad0[4];
    u16 unk4;
    u8 pad6[0x5E];
} Row;

typedef struct {
    Box *unk0;
    u8 pad4[0x5E];
    Row rows[1];
    u8 pad_[0x144C - 0x62 - 0x64];
    Ent *unk144C;
} Ctx;

Box *BgCheck_GetCollisionHeader(void *, s32);

f32 WaterBox_GetSurface(Ctx *arg0, s32 arg1, s32 arg2) {
    Box *box = BgCheck_GetCollisionHeader(arg0, arg2);

    if (box == 0 || arg1 < 0 || arg1 >= box->unk24) {
        return 0.0f;
    }
    if (arg2 == 0x32) {
        return ((Ent *)arg0->unk0->unk28)[arg1].unk2;
    }
    return (arg0->unk144C + arg0->rows[arg2].unk4)[arg1].unk2;
}
