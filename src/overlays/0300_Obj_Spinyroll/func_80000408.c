#include "types.h"
#include "generated/overlays/0300.h"

extern void func_80A02B40();
extern void func_80A02A48();

void func_80000408(ObjSpinyroll *this) {
    *(s32 *)((u8 *)this + 0x4A8) = 0;
    func_80A02B40(this);
    func_80A02A48(this);
}
