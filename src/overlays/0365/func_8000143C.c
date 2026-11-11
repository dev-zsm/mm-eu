#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A5C360(u8 *, M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_80A5D4E8;

void func_8000143C(u8 *arg0, u8 *arg1) {
    u8 *sp1C;

    sp1C = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_80A5C360(arg0, 8, arg1);
    M2C_FIELD(arg0, s16 *, 0x286) = (s16) M2C_FIELD(sp1C, s16 *, 0xBE);
    M2C_FIELD(arg0, s16 *, 0x288) = 0x258;
    M2C_FIELD(arg0, s16 *, 0x284) = 3;
    M2C_FIELD(arg0, s8 *, 0x370) = 0;
    M2C_FIELD(arg0, u8 *, 0xF05) = (u8) (M2C_FIELD(arg0, u8 *, 0xF05) | 4);
    M2C_FIELD(arg0, M2C_UNK **, 0x278) = &D_80A5D4E8;
}
