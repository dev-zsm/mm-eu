// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"
extern void func_8008A780(void *a0, s32 a1);
extern void func_8008F410(void *a0, s32 a1);
extern void func_80095950(void *a0);
typedef struct { u8 pad0[0x11C]; s32 *unk11C; s32 unk120; u8 pad124[8]; s32 unk12C; } Obj;

void func_800834B0(Obj *arg0) { arg0->unk120 = 0; arg0->unk12C = 0; arg0->unk11C += 1; *arg0->unk11C = 0xD; func_8008A780(arg0->unk11C, 4); func_8008F410(arg0->unk11C, 4); func_80095950(arg0); }
