// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Entrance_Create(u32, s32, M2C_UNK);           /* extern */
extern u32 D_801E6EF0;

u16 Entrance_CreateFromSpawn(s32 spawn) {
    Entrance_Create((u32) D_801E6EF0 >> 9, spawn, 0);
}
