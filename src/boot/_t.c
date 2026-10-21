// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "types.h"

void func_8008B7A0(void);
float sqrtf(float);
#pragma intrinsic (sqrtf)

#define FTOFRAC8(x) ((s32)((((x) * 128.0f) < 127.0f) ? ((x) * 128.0f) : 127.0f))

void func_8008D970(f32 (*mf)[4], u8 *l, s32 *h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 twidth, s32 theight) {
    f32 len, xLook, yLook, zLook, xRight, yRight, zRight;
    f32 xHilite, yHilite, zHilite;

    func_8008B7A0();

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    len = -1.0 / sqrtf(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    len = 1.0 / sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = 1.0 / sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    len = 1.0 / sqrtf(xl1 * xl1 + yl1 * yl1 + zl1 * zl1);
    xl1 *= len;
    yl1 *= len;
    zl1 *= len;

    xHilite = xl1 + xLook;
    yHilite = yl1 + yLook;
    zHilite = zl1 + zLook;
    len = sqrtf(xHilite * xHilite + yHilite * yHilite + zHilite * zHilite);
    if (len > 0.1) {
        len = 1.0 / len;
        xHilite *= len;
        yHilite *= len;
        zHilite *= len;
        h[0] = twidth * 4 + ((xHilite * xRight + yHilite * yRight + zHilite * zRight) * twidth * 2);
        h[1] = theight * 4 + ((xHilite * xUp + yHilite * yUp + zHilite * zUp) * theight * 2);
    } else {
        h[0] = twidth * 2;
        h[1] = theight * 2;
    }

    len = 1.0 / sqrtf(xl2 * xl2 + yl2 * yl2 + zl2 * zl2);
    xl2 *= len;
    yl2 *= len;
    zl2 *= len;

    xHilite = xl2 + xLook;
    yHilite = yl2 + yLook;
    zHilite = zl2 + zLook;
    len = sqrtf(xHilite * xHilite + yHilite * yHilite + zHilite * zHilite);
    if (len > 0.1) {
        len = 1.0 / len;
        xHilite *= len;
        yHilite *= len;
        zHilite *= len;
        h[2] = twidth * 4 + ((xHilite * xRight + yHilite * yRight + zHilite * zRight) * twidth * 2);
        h[3] = theight * 4 + ((xHilite * xUp + yHilite * yUp + zHilite * zUp) * theight * 2);
    } else {
        h[2] = twidth * 2;
        h[3] = theight * 2;
    }

    l[8] = FTOFRAC8(xRight);
    l[9] = FTOFRAC8(yRight);
    l[10] = FTOFRAC8(zRight);
    l[0x18] = FTOFRAC8(xUp);
    l[0x19] = FTOFRAC8(yUp);
    l[0x1A] = FTOFRAC8(zUp);

    l[0x15] = 0x80;
    l[2] = 0;
    l[3] = 0;
    l[4] = 0;
    l[6] = 0;
    l[7] = 0;
    l[0x10] = 0;
    l[0x11] = 0x80;
    l[5] = 0;
    l[0] = 0;
    l[0x13] = 0;
    l[0x14] = 0;
    l[0x12] = 0;
    l[0x16] = 0;
    l[0x17] = 0;
    l[1] = 0;

    mf[0][0] = xRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);
    mf[0][3] = 0.0f;
    mf[1][0] = yRight;
    mf[0][1] = xUp;
    mf[2][2] = zLook;
    mf[3][3] = 1.0f;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);
    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][1] = zUp;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);
    mf[1][3] = 0.0f;
    mf[2][0] = zRight;
    mf[2][3] = 0.0f;
    mf[1][1] = yUp;
}
