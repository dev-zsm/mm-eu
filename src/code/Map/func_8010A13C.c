#include "types.h"

extern u16 D_801EAE26;
extern s16 D_801EAE48;
extern u32 D_801C29F0[];
extern u8 D_801E6EF0[];
extern void MapDisp_SwapRooms(s16);
extern s32 Map_IsInDungeonOrBossScene(u8 *);
extern s32 func_8016AE44(s16);
typedef struct {
    u8 pad0[0x27A];
    u16 unk27A;
    s16 unk27C;
} Sub;
void Map_InitRoomData(u8 *ctx, s16 arg1) {
    s32 sp1C = D_801EAE26;
    Sub *new_var;
    u8 *e;
    short new_var2;
    Sub *sub = (Sub *) (ctx + 0x169E8);
    MapDisp_SwapRooms(arg1);
    if (arg1 >= 0) {
        if (Map_IsInDungeonOrBossScene(ctx) != 0) {
            e = D_801E6EF0 + (func_8016AE44(*((s16 *) (ctx + 0xA4))) * 0x1C);
            *((u32 *) (e + 0x110)) |= D_801C29F0[arg1];
            new_var = sub;
            sub->unk27C = arg1;
            new_var->unk27A = sp1C;
        }
    } else {
        *((s16 *) (ctx + 0x16C64)) = 0;
    }
    new_var2 = 0;
    if (D_801EAE48 != 2) {
        D_801EAE48 = new_var2;
    }
}
