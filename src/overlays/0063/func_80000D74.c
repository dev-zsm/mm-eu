#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0063.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60050B8;
extern M2C_UNK D_8086A288;

void func_80000D74(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_60050B8, arg0);
    M2C_FIELD(arg0, s16 *, 0x2B6) = 0xA;
    M2C_FIELD(arg0, s16 *, 0x1C) = 4;
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x124), s16 *, 0x32);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086A288;
}
