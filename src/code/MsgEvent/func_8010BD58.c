// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_RunScript(Actor* actor, PlayState* play, MsgScript* script, MsgScriptCallback callback, s32* pos) {
    u8* start;
    u8* cur;
    s32 scriptDone = false;
    s32 i;
    s32 cmdLen;
    u8 cmdId;
    s32 stop;

    start = script;
    script += *pos;

    if (sREG(95) != 0) {}

    cmdLen = 0;
    do {
        
        script += cmdLen;

        
        cmdId = *script;

        
        if (cmdId < ARRAY_COUNTU(sMsgScriptCmdSizes)) {
            cmdLen = sMsgScriptCmdSizes[cmdId];
        } else {
            cmdLen = -1;
            
        }

        
        if (sREG(95) != 0) {
            for (i = 0; i < cmdLen; i++) {}
        }

        stop = sMsgScriptCmdHandlers[cmdId](actor, play, &script, callback, &scriptDone);
    } while (!stop);

    cur = script;
    if (!scriptDone) {
        *pos = cur - start;
    } else {
        *pos = 0;
    }
    return scriptDone;
}
