// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u32 type;
    /* 0x04 */ u32 flags;
    /* 0x08 */ u64 *ucode_boot;
    /* 0x0C */ u32 ucode_boot_size;
    /* 0x10 */ u64 *ucode;
    /* 0x14 */ u32 ucode_size;
    /* 0x18 */ u64 *ucode_data;
    /* 0x1C */ u32 ucode_data_size;
    /* 0x20 */ u8 pad20[0x18];
    /* 0x38 */ u64 *yield_data_ptr;
    /* 0x3C */ u32 yield_data_size;
} OSTask;

OSTask *_VirtualToPhysicalTask(OSTask *intp);
void func_8008A780(void *a, s32 n);
void __osSpSetStatus(u32 a);
s32 __osSpSetPc(u32 a);
s32 __osSpRawStartDma(s32 dir, u32 devAddr, void *dramAddr, u32 size);
s32 __osSpDeviceBusy(void);

void osSpTaskLoad(OSTask *intp) {
    OSTask *tp;

    tp = _VirtualToPhysicalTask(intp);
    if (tp->flags & 1) {
        tp->ucode_data = tp->yield_data_ptr;
        tp->ucode_data_size = tp->yield_data_size;
        intp->flags &= ~1;
        if (tp->flags & 4) {
            tp->ucode = (u64 *)(*(u32 *)(((u32)intp->yield_data_ptr + 0xBFC) | 0xA0000000));
        }
    }
    func_8008A780(tp, 0x40);
    __osSpSetStatus(0x2B00);
    while (__osSpSetPc(0x04001000) == -1) {
    }
    while (__osSpRawStartDma(1, 0x04001000 - 0x40, tp, 0x40) == -1) {
    }
    while (__osSpDeviceBusy()) {
    }
    while (__osSpRawStartDma(1, 0x04001000, tp->ucode_boot, tp->ucode_boot_size) == -1) {
    }
}
