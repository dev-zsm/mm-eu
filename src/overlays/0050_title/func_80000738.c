#include "types.h"
#include "generated/overlays/0050.h"

extern void func_80147344();
extern void func_80161E44();
extern void func_80081878();

void ConsoleLogo_Destroy(void *thisx) {
    func_80147344(thisx, (u8 *)thisx + 0x210);
    func_80161E44();
    func_80081878();
}
