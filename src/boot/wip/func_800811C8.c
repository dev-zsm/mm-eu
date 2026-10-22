// FLAGS: -O2 -g0
#include "types.h"

void usleep(s32);
void sprintf();
void Fault_AddHungupAndCrashImpl(void *, void *);
s32 Yaz0_FirstDMA(void);
s32 Yaz0_DecompressImpl(s32, s32);

extern void *D_8009C1E8;
extern s32 D_8009C1EC;
extern s32 D_8009C1F0;
extern u8 D_800984B0[];
extern u8 D_800984CC[];

void Yaz0_Decompress(s32 arg0, s32 arg1, s32 arg2) {
    void *lock;
    u8 sp80[0x50];
    u8 sp30[0x50];
    s32 temp_v0;

    if ((D_8009C1E8 != NULL) && (D_8009C1E8 != NULL)) {
        do {
            usleep(0xA);
        } while (D_8009C1E8 != NULL);
    }
    lock = &D_8009C1E8;
    D_8009C1E8 = lock;
    D_8009C1EC = arg0;
    D_8009C1F0 = arg2;
    temp_v0 = Yaz0_DecompressImpl(Yaz0_FirstDMA(), arg1);
    if (temp_v0 != 0) {
        sprintf(sp80, D_800984B0, temp_v0);
        sprintf(sp30, D_800984CC, arg0, arg1, arg2);
        Fault_AddHungupAndCrashImpl(sp80, sp30);
    }
    D_8009C1E8 = NULL;
}
