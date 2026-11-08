#include "types.h"
#include "generated/overlays/0389.h"
void ObjTokeidai_TerminaFieldWalls_Collapse(ObjTokeidai *this, PlayState *play) {
    if (*(s16 *)((u8 *)this + 0xBC) < 0x4000) {
        *(s16 *)((u8 *)this + 0xBC) += 0x28;
    }
}
