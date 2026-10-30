#include "types.h"
typedef struct { u8 pad[0x94]; u16 unk94; } P;
typedef struct { u8 pad[0xA68]; P *unkA68; u8 pad2[0x7B]; s8 unkAE7; } A;
extern void func_800B8BDC();

void func_8001A004(A *a) {
    s32 v = a->unkAE7 ? 0x80C : 0x80A;
    func_800B8BDC(a, (s32)(v + (u32)a->unkA68->unk94) & 0xFFFF);
}
