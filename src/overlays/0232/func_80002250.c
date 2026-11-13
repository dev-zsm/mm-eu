#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0232.h"

M2C_UNK func_8096DE80(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_8096E708(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8096E7DC(u8 *, f32);             /* extern */
extern M2C_UNK D_8096FB98;
extern M2C_UNK D_8096FFCC;
extern M2C_UNK D_8097109C;

void func_80002250(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x98) < 150.0f) {
        func_8096DE80(arg0 + 0x14C, &D_8097109C, 0xB);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096FFCC;
    } else if (M2C_FIELD(arg0, f32 *, 0x98) > 200.0f) {
        func_8096DE80(arg0 + 0x14C, &D_8097109C, 1);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096FB98;
    }
    func_8096E7DC(arg0, 0);
    func_8096E7DC(arg0, 1.0f);
    func_8096E7DC(arg0, 2.0f);
    func_8096E7DC(arg0, 3.0f);
    func_8096E708(arg0, 0x40A00000);
}
