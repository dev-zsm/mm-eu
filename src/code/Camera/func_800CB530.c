#include "types.h"

typedef struct {
    u8 pad0[0x1CCC];
    void *unk1CCC;
} Player0;

typedef struct {
    u8 pad0[0x8C];
    Player0 *unk8C;
    void *unk90;
} Camera0;

extern f32 func_800B6E14(void *arg);

f32 Camera_GetRunSpeedLimit(Camera0 *camera) {
    f32 limit;

    if (camera->unk8C->unk1CCC == camera->unk90) {
        limit = func_800B6E14(camera->unk90);
    } else {
        limit = 10.0f;
    }
    return limit;
}
