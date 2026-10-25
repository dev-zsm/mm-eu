#include "types.h"

typedef struct {
    u8 pad0[0x800];
    void *cameras[1];
} Struct_8016AAB0;
extern s32 Camera_SetViewParam(void *camera, s32 param, void *value);
s32 Play_SetCameraFov(Struct_8016AAB0 *arg0, s16 arg1, f32 arg2) {
    s32 ret = Camera_SetViewParam(arg0->cameras[arg1], 0x20, &arg2) & 1;
    s32 *new_var;
    new_var = &ret;
    return *new_var;
}
