// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

u32 GameState_IsRunning(struct GameState *gameState) {
    return M2C_FIELD(gameState, u8 *, 0x9B);
}
