#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x16810]; u16 unk16810; u8 pad16812[0xA]; s32 unk1681C; } S_arg1;

M2C_UNK D_80BA026C(u8 *, u8 *);                 /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
M2C_UNK func_80151E7C(u8 *, M2C_UNK);             /* extern */
s32 func_801529DC(u8 *);                          /* extern */
M2C_UNK func_80B9FC24(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80B9FD9C(u8 *, u8 *);                  /* extern */
M2C_UNK func_80BA00F4(u8 *, u8 *);              /* extern */

void func_800008D4(u8 *arg0, S_arg1 *arg1) {
    u16 temp_v0;
    u32 temp_v0_2;

    if (!(M2C_FIELD(arg0, u16 *, 0x2B6) & 0x10)) {
        func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 2, 0x1000, 0x200);
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    }
    if (func_80B9FD9C(arg0, arg1) != 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x2B6);
        if (temp_v0 & 0x20) {
            M2C_FIELD(arg0, u16 *, 0x2B6) = (u16) (temp_v0 & 0xFFDF);
            func_80151E7C(arg1, 0x124C);
        }
    }
    if ((func_801529DC((u8 *)arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        temp_v0_2 = arg1->unk16810;
        switch (temp_v0_2) {                        /* irregular */
            case 0x124B:
                if (M2C_FIELD(arg0, s16 *, 0x2B8) == 9) {
                arg1->unk1681C = 0;
                M2C_FIELD(arg0, u16 *, 0x2B6) = (u16) (M2C_FIELD(arg0, u16 *, 0x2B6) | 0x20);
                return;
                }
                func_80151E7C(arg1, 0x124C);
                return;
            case 0x124C:
                arg1->unk1681C = 0;
                M2C_FIELD(arg0, M2C_UNK (**)(u8 *, u8 *), 0x2C0) = D_80BA026C;
                func_80B9FC24(arg0, 0xA, 0);
                return;
            case 0x124D:
                M2C_FIELD(arg0, u16 *, 0x2B6) = (u16) (M2C_FIELD(arg0, u16 *, 0x2B6) & 0xFFEF);
                func_80B9FC24(arg0, 6, 0);
                func_80151E7C(arg1, 0x124E);
                return;
            case 0x124E:
                func_80147CC4(arg1);
                M2C_FIELD(arg0, M2C_UNK (**)(u8 *, u8 *), 0x2C0) = func_80BA00F4;
                func_80BA00F4(arg0, arg1);
                break;
        }
    }
}
