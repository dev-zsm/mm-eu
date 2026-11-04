// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lupygamelift.h"

void ObjLupygamelift_UpdateShadow(ObjLupygamelift* this) {
    static f32 sShadowAlphaMin = 100.0f;
    static f32 sShadowAlphaMax = 255.0f;
    static f32 sShadowScaleMin = 5.0f;
    static f32 sShadowScaleMax = 10.0f;
    static f32 sLiftHeightMin = -240.0f;
    static f32 sLiftHeightMax = 30.0f;
    f32 shadowAlphaRange = sShadowAlphaMax - sShadowAlphaMin;
    f32 liftHeightRange = sLiftHeightMax - sLiftHeightMin;
    f32 shadowScaleRange = sShadowScaleMax - sShadowScaleMin;
    f32 liftHeight;
    f32 percent;

    liftHeight = this->dyna.actor.world.pos.y - sLiftHeightMin;
    if (liftHeight < 0.0f) {
        percent = 0.0f;
    } else if (liftHeightRange < liftHeight) {
        percent = 1.0f;
    } else {
        percent = liftHeight / liftHeightRange;
    }
    this->dyna.actor.shape.shadowAlpha = sShadowAlphaMax - (percent * shadowAlphaRange);
    this->dyna.actor.shape.shadowScale = sShadowScaleMax - (percent * shadowScaleRange);
}
