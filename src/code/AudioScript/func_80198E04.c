// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 *pc;
} Script;

u16 AudioScript_ScriptReadCompressedU16(Script *arg0) {
    u16 ret = *arg0->pc++;

    if (ret & 0x80) {
        ret = (ret << 8) & 0x7F00;
        ret = *arg0->pc++ | ret;
    }
    return ret;
}
