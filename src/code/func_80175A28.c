// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Graph_UpdateGame(void *);                      /* extern */
M2C_UNK Graph_ExecuteAndDraw(s32, void *);                 /* extern */

void Graph_Update(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s8 *, 0xA3) = 0;
    Graph_UpdateGame(arg1);
    Graph_ExecuteAndDraw(arg0, arg1);
}
