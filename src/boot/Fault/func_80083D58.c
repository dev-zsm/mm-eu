// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 D_80098E70[];
extern u8 D_80098E88[];
extern u8 D_80098E8C[];
extern u8 D_80098E94[];
extern u8 D_80098E98[];
extern u8 D_80098EA0[];
extern u8 D_80098EB8[];
extern u8 D_80098EBC[];
extern u8 D_80098EC4[];
extern u8 D_80098EC8[];

extern s32 osGetThreadId(s32 a0);
extern void func_8008198C(void *a0, s32 a1);
extern void FaultDrawer_Printf(void *a0, s32 a1);

void Fault_HangupFaultClient(s32 a0, s32 a1) {
    func_8008198C(D_80098E70, osGetThreadId(0));
    func_8008198C(D_80098E88, a0 ? a0 : (s32)D_80098E8C);
    func_8008198C(D_80098E94, a1 ? a1 : (s32)D_80098E98);
    FaultDrawer_Printf(D_80098EA0, osGetThreadId(0));
    FaultDrawer_Printf(D_80098EB8, a0 ? a0 : (s32)D_80098EBC);
    FaultDrawer_Printf(D_80098EC4, a1 ? a1 : (s32)D_80098EC8);
}
