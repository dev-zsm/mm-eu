// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"
extern void func_8008A780(void *a0, s32 a1);
extern void osInvalICache(void *a0, s32 a1);
extern void osStartThread(void *a0);
typedef struct { u8 pad0[0x11C]; s32 *unk11C; s32 unk120; u8 pad124[8]; s32 unk12C; } Obj;

void Fault_ResumeThread(Obj *arg0) { arg0->unk120 = 0; arg0->unk12C = 0; arg0->unk11C += 1; *arg0->unk11C = 0xD; func_8008A780(arg0->unk11C, 4); osInvalICache(arg0->unk11C, 4); osStartThread(arg0); }
