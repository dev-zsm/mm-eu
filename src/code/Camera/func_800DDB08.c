#include "types.h"
#include "generated/code_funcs.h"


void *Camera_Create(void *a, void *b, void *c) {
    void *camera = ZeldaArena_Malloc(0x178);

    if (camera != NULL) {
        Camera_Init(camera, a, b, c);
    }
    return camera;
}
