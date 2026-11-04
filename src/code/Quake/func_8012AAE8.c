// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_quake.h"

QuakeRequest* Quake_RequestImpl(Camera* camera, u32 type) {
    s16 index = Quake_GetFreeIndex();
    QuakeRequest* req = &sQuakeRequests[index];

    memset(req, 0, sizeof(QuakeRequest));

    req->camera = camera;
    req->camId = camera->camId;
    req->type = type;
    req->isRelativeToScreen = true;

    
    
    req->index = index + (TRUNCF_BINANG(Rand_ZeroOne() * 0x10000) & ~3);

    sQuakeRequestCount++;

    return req;
}
