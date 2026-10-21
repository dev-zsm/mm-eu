// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"
extern void func_8008A780(void *a0, s32 a1);
extern void func_8008F410(void *a0, s32 a1);
extern void func_80095950(void *a0);
typedef struct { u8 pad0[0x11C]; s32 *unk11C; s32 unk120; u8 pad124[8]; s32 unk12C; } Obj;
typedef struct { s32 unk0; s32 unk4; } Node;

void func_800834B0(Obj *arg0) {
    Node *temp_t6;
    Node *temp_t7;
    temp_t6 = (Node *)arg0->unk11C;
    arg0->unk120 = 0;
    arg0->unk12C = 0;
    temp_t7 = (Node *)((u8 *)temp_t6 + 4);
    arg0->unk11C = (s32 *)temp_t7;
    temp_t7->unk0 = 0xD;
    func_8008A780(arg0->unk11C, 4);
    func_8008F410(arg0->unk11C, 4);
    func_80095950(arg0);
}
