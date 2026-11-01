#include "types.h"

extern u8 D_801CEA30[];
extern s32 AudioScript_ScriptReadU8(s32 a0);
extern s32 AudioScript_ScriptReadS16(s32 a0);

u16 AudioScript_GetScriptControlFlowArgument(s32 a0, u8 index) {
    u16 result = 0;
    u8 flags = D_801CEA30[index];

    if ((flags & 3) == 1) {
        if (!(flags & 0x80)) {
            result = AudioScript_ScriptReadU8(a0);
        } else {
            result = AudioScript_ScriptReadS16(a0);
        }
    }
    return result;
}
