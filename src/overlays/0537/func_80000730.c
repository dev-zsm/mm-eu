// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B849C(u8 *, u8 *);              /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
M2C_UNK func_80B84584(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B849AC(u8 *);                      /* extern */
extern M2C_UNK D_80B854C8;

void func_80000730(u8 *arg0, u8 *arg1) {
    func_80147CC4(arg1);
    M2C_FIELD(arg1, s16 *, 0x16936) = 4;
    func_80B849AC(arg0);
    M2C_FIELD(arg0, u16 *, 0x2F4) = (u16) (M2C_FIELD(arg0, u16 *, 0x2F4) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x314) = &D_80B854C8;
    M2C_FIELD(arg0, s16 *, 0x304) = 0;
    func_80B84584(arg0, 6, 2);
    func_800B849C(arg0, arg1);
}
