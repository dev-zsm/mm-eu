#include "types.h"
#include "actor.h"
#include "generated/overlays/0162.h"

extern void func_800B6564();
extern u8 D_8092A024;

void ItemInbox_Init(Actor *thisx, PlayState *play) {
    *(u8 **)((u8 *)thisx + 0x144) = &D_8092A024;
    func_800B6564(thisx, 0x3E4CCCCD);
}
