#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0546.h"
typedef struct { s32 w; u8 pad[0x40]; } Stride44_s32;

M2C_UNK func_8013C01C(u8 *, M2C_UNK *, s32, u8 *); /* extern */
extern s32 D_801EFA18;
extern M2C_UNK D_80B98C94;

void func_80000950(u8 *arg0, s32 arg1) {
    D_801EFA18 = ((Stride44_s32 *)(arg1 + 0x17D98))[M2C_FIELD(arg0, s32 *, 0x248)].w + 0x80000000;
    func_8013C01C(arg0 + 0x144, &D_80B98C94, M2C_FIELD(arg0, s32 *, 0x4AC), arg0);
}
