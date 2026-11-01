#include "types.h"

extern void *ZeldaArena_Malloc(u32 size);
extern void Camera_Init(void *camera, void *a, void *b, void *c);

void *Camera_Create(void *a, void *b, void *c) {
    void *camera = ZeldaArena_Malloc(0x178);

    if (camera != NULL) {
        Camera_Init(camera, a, b, c);
    }
    return camera;
}
