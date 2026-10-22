// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 D_8009C850[];
extern u8 D_8009C230[0x600]; /* thread stack, ends at D_8009C830 */
extern u8 D_8009C830[];
extern u8 D_80098E68[];
extern void *D_8009C220;
extern u8 D_8009D01E;

extern void func_800897D0(void *a0, s32 a1);
extern void func_80084918(void);
extern void func_80084904(void *a0);
extern void func_8008F3E0(void *a0, void *a1, s32 a2);
extern void func_80085390(void *a0, void *a1, void *a2, s32 a3, s32 a4, void *a5);
extern void func_80089FE0(void *a0, s32 a1, void *a2, s32 a3, void *a4, s32 a5);
extern void func_80095950(void *a0);
extern void func_8008209C(void);
extern void func_80081EC8(void);
extern void func_80083888(void);

void func_80083C24(void) {
    func_800897D0(D_8009C220 = D_8009C850, 0x848);
    func_80084918();
    func_80084904(func_8008209C);
    *(u8 *)((u8 *)D_8009C220 + 0x7CC) = 0;
    *(u8 *)((u8 *)D_8009C220 + 0x7CD) = 0;
    *(u8 *)((u8 *)D_8009C220 + 0x7CE) = 0;
    *(u32 *)((u8 *)D_8009C220 + 0x7D0) = 0;
    *(void **)((u8 *)D_8009C220 + 0x7D4) = func_80081EC8;
    *(u32 *)((u8 *)D_8009C220 + 0x7D8) = 0;
    *(u8 *)((u8 *)D_8009C220 + 0x7CF) = 0;
    D_8009D01E = 1;
    func_8008F3E0((u8 *)D_8009C220 + 0x7B0, (u8 *)D_8009C220 + 0x7C8, 1);
    func_80085390(D_8009C830, D_8009C230, D_8009C230 + sizeof(D_8009C230), 0, 0x100, D_80098E68);
    func_80089FE0(D_8009C220, 2, func_80083888, 0, D_8009C830, 0x7F);
    func_80095950(D_8009C220);
}
