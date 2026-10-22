// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8008209C();                            /* extern */
M2C_UNK func_8008487C(M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_8008B7F0(s32);                         /* extern */
M2C_UNK func_80090000(s32);                         /* extern */
M2C_UNK func_800922A0(M2C_UNK);                     /* extern */
s32 func_80179C60(M2C_UNK);                         /* extern */
extern M2C_UNK D_801D7570;
extern s32 D_801F3408;

void Graph_FaultClient(void) {
    func_8008487C(0x1E, 0x64, &D_801D7570);
    func_80090000(func_80179C60(0));
    func_8008B7F0(D_801F3408);
    func_800922A0(0x42);
    func_8008209C();
    func_80090000(func_80179C60(1));
    func_8008B7F0(D_801F3408);
    func_800922A0(0x42);
}
