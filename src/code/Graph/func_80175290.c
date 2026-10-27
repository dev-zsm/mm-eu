#include "types.h"

typedef struct {
    u8 pad0[0x274];
    s32 unk274;
    u8 pad278[0x50];
    s32 unk2C8;
    u8 pad2CC[8];
    s32 unk2D4;
    u8 pad2D8[3];
    u8 unk2DB;
    u8 pad2DC[8];
    f32 unk2E4;
    f32 unk2E8;
} Gfx;

extern s32 D_80096CCC;
extern f32 D_80096CD0;
extern f32 D_80096CD4;
extern u8 D_801EF968[];
extern u8 D_801EF978[];

void func_800897D0(void *p, s32 n);
void func_8008F3E0(void *a, void *b, s32 c, void *d);
void func_80081A50(void *a, void *b, s32 c, s32 d);
void func_80081C2C(void *a, void *b, s32 c);
void Graph_FaultClient(void);
void Graph_FaultAddrConv(void);

void Graph_Init(Gfx *gfx) {
    func_800897D0(gfx, 0x2F0);
    gfx->unk2C8 = 0;
    gfx->unk2DB = 0;
    gfx->unk274 = 0;
    gfx->unk2D4 = D_80096CCC;
    gfx->unk2E4 = D_80096CD0;
    gfx->unk2E8 = D_80096CD4;
    func_8008F3E0((u8 *)gfx + 0x5C, (u8 *)gfx + 0x38, 8, gfx);
    func_80081A50(D_801EF978, Graph_FaultClient, 0, 0);
    func_80081C2C(D_801EF968, Graph_FaultAddrConv, 0);
}
