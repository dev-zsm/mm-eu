#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 pad8;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0xC];
    s32 unk3C;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s32 unk48;
    s16 unk4C;
    u8 pad4E[2];
    s32 unk50;
    s32 unk54;
    u8 pad58[2];
    s16 unk5A;
} MapDisp;

extern MapDisp D_801BF708;
extern s32 D_801BF76C;
extern void MapDisp_DestroyRoomStoreyRecord();
extern void MapDisp_DestroyMapI();

void MapDisp_Destroy(s32 a0) {
    s32 i;
    s32 off;

    D_801BF708.unk0 = 0;
    D_801BF708.unk4 = -1;
    D_801BF708.unkC = 0xD2;
    D_801BF708.unkE = 0x8C;
    D_801BF708.unk10 = 0;
    D_801BF708.unk14 = -1;
    D_801BF708.unk18 = 0;
    D_801BF708.unk1C = 0;
    D_801BF708.unk1E = 0;
    D_801BF708.unk20 = 0;
    D_801BF708.unk24 = 0;
    D_801BF708.unk28 = 0;
    D_801BF708.unk2C = 0;
    i = 0;
    if (D_801BF76C > 0) {
        off = 0;
        do {
            MapDisp_DestroyRoomStoreyRecord(a0, off + D_801BF708.unk3C);
            i++;
            off += 2;
        } while (i < D_801BF76C);
    }
    D_801BF708.unk3C = 0;
    D_801BF708.unk40 = 0;
    D_801BF708.unk42 = 0;
    D_801BF708.unk44 = 0;
    D_801BF708.unk4C = 0;
    D_801BF708.unk48 = 0;
    D_801BF708.unk50 = 0;
    D_801BF708.unk54 = 0;
    MapDisp_DestroyMapI(a0);
    D_801BF708.unk5A = 0;
}
