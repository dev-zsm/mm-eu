#include "types.h"

void func_80147D28(void *arg0, s32 arg1, s16 arg2, s16 arg3);

typedef struct {
    u8 pad0[0x16900];
    s16 unk16900;
} A;

typedef struct {
    u8 pad0[0x11FF8];
    s16 unk11FF8;
    s16 unk11FFA;
    u8 pad11FFC[0x12002 - 0x11FFC];
    s16 unk12002[1];
    s16 unk12004[1];
    u8 pad12006[0x12025 - 0x12006];
    u8 unk12025;
} B;

void func_801491CC(A *arg0, s32 arg1, u8 arg2) {
    B *p;
    arg0->unk16900 = 0x30;
    p = (B *)((u8 *)arg0 + 0x4908);
    if (arg2 == 1) {
        p->unk11FFA = *(s16 *)((u8 *)p + p->unk12025 * 2 + 0x12004);
    } else {
        p->unk11FFA = *(s16 *)((u8 *)p + p->unk12025 * 2 + 0x12002);
    }
    func_80147D28(arg0, arg1, p->unk11FF8, p->unk11FFA);
}
