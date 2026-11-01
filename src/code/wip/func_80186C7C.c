#include "types.h"

extern s32 D_801F4848;
typedef struct { s32 a; s32 b; } Pair;
extern Pair D_801F4850;
extern s32 D_801F4858;
extern u8 D_801F485C[];
extern u8 D_801F4874[];
extern u8 D_801F4678[];
extern u8 D_801F3678[];
extern u8 D_801F4698[];
extern u8 D_801D7AFC[];

extern s32 SysFlashrom_IsInit();
extern void SysFlashrom_ThreadEntry();
extern void func_8008F3E0();
extern void func_80085390();
extern void func_80089FE0();
extern void func_80095950();

void SysFlashrom_WriteAsync(s32 a0, s32 a1, s32 a2) {
    if (SysFlashrom_IsInit() != 0) {
        D_801F4848 = 1;
        D_801F4850.a = a0;
        D_801F4850.b = a1;
        D_801F4858 = a2;
        func_8008F3E0(D_801F485C, D_801F4874, 1);
        func_80085390(D_801F4678, D_801F3678, D_801F4678, 0, 0x100, D_801D7AFC);
        func_80089FE0(D_801F4698, 0xD, SysFlashrom_ThreadEntry, &D_801F4848, D_801F4678, 0xD);
        func_80095950(D_801F4698);
    }
}
