// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x18];
    s32 unk38;
    s32 unk3C;
} Thing;

void *_VirtualToPhysicalTask(void);
void func_8008A780(void *arg0, s32 arg1);
s32 __osSpRawStartDma(s32 arg0, u32 arg1, void *arg2, s32 arg3);
s32 __osSpDeviceBusy(void);
void __osSpSetStatus(s32 arg0);
s32 __osSpSetPc(u32 arg0);

void osSpTaskLoad(Thing *arg0) {
    Thing *temp_v0;
    s32 temp_s0;

    temp_v0 = _VirtualToPhysicalTask();
    if (temp_v0->unk4 & 1) {
        temp_v0->unk18 = temp_v0->unk38;
        temp_v0->unk1C = temp_v0->unk3C;
        arg0->unk4 &= ~1;
        if (temp_v0->unk4 & 4) {
            temp_v0->unk10 = *(s32 *)((arg0->unk38 + 0xBFC) | 0xA0000000);
        }
    }
    func_8008A780(temp_v0, 0x40);
    __osSpSetStatus(0x2B00);
    temp_s0 = 0x04000000;
    if (__osSpSetPc(0x04001000) == -1) {
        do {
        } while (__osSpSetPc(0x04001000) == -1);
    }
    temp_s0 |= 0xFC0;
    if (__osSpRawStartDma(1, temp_s0, temp_v0, 0x40) == -1) {
        do {
        } while (__osSpRawStartDma(1, temp_s0, temp_v0, 0x40) == -1);
    }
    if (__osSpDeviceBusy() != 0) {
        do {
        } while (__osSpDeviceBusy() != 0);
    }
    if (__osSpRawStartDma(1, 0x04001000, temp_v0->unk8, temp_v0->unkC) == -1) {
        do {
        } while (__osSpRawStartDma(1, 0x04001000, temp_v0->unk8, temp_v0->unkC) == -1);
    }
}
