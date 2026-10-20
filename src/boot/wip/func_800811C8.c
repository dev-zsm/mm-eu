// FLAGS: -O2 -g0
#include "types.h"

void func_80087BBC(s32);
void func_80087A44();
void func_80083E54(void *, void *);
s32 func_80080E80(void);
s32 func_80081040(s32, s32);

extern void *D_8009C1E8;
extern s32 D_8009C1EC;
extern s32 D_8009C1F0;
extern u8 D_800984B0[];
extern u8 D_800984CC[];

void func_800811C8(s32 arg0, s32 arg1, s32 arg2) {
    void *lock;
    u8 sp80[0x50];
    u8 sp30[0x50];
    s32 temp_v0;

    if ((D_8009C1E8 != NULL) && (D_8009C1E8 != NULL)) {
        do {
            func_80087BBC(0xA);
        } while (D_8009C1E8 != NULL);
    }
    lock = &D_8009C1E8;
    D_8009C1E8 = lock;
    D_8009C1EC = arg0;
    D_8009C1F0 = arg2;
    temp_v0 = func_80081040(func_80080E80(), arg1);
    if (temp_v0 != 0) {
        func_80087A44(sp80, D_800984B0, temp_v0);
        func_80087A44(sp30, D_800984CC, arg0, arg1, arg2);
        func_80083E54(sp80, sp30);
    }
    D_8009C1E8 = NULL;
}
