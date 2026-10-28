// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(s32, M2C_UNK);                /* extern */
M2C_UNK func_800CABA0(s32, M2C_UNK);                /* extern */
M2C_UNK func_800CABC4(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_800E201C(s32, s32, s32, M2C_UNK *);    /* extern */
M2C_UNK func_800E731C(s32, M2C_UNK *, M2C_UNK *);   /* extern */
extern M2C_UNK D_6001BA8;
extern M2C_UNK D_80A1ABE0;
extern M2C_UNK D_80A1AC0C;
extern M2C_UNK D_80A1AC38;
extern M2C_UNK D_80A1AC44;

void func_800007A4(s32 arg0, s32 arg1) {
    func_800CABA0(arg0, 0);
    func_800CABC4(arg1, arg0, &D_6001BA8);
    func_800B6564(arg0, 0x3DA3D70A);
    func_800E201C(arg1, arg0 + 0x15C, arg0, &D_80A1ABE0);
    func_800E201C(arg1, arg0 + 0x1B4, arg0, &D_80A1AC0C);
    func_800E731C(arg0 + 0xA0, &D_80A1AC44, &D_80A1AC38);
}
