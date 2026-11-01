#ifndef GU_H
#define GU_H

#include "types.h"

/* Fixed-point matrix as the RSP reads it: the integer parts of the 16 elements, then their fractional parts. */
typedef struct {
    /* 0x00 */ s16 intPart[4][4];
    /* 0x20 */ u16 fracPart[4][4];
} Mtx;

/* Floating-point matrix. */
typedef f32 MtxF[4][4];

/* Light directions the RSP uses to compute specular highlights. */
typedef struct {
    /* 0x00 */ u8 col[3];
    /* 0x03 */ s8 pad1;
    /* 0x04 */ u8 colc[3];
    /* 0x07 */ s8 pad2;
    /* 0x08 */ s8 dir[3];
    /* 0x0B */ s8 pad3;
    /* 0x0C */ s32 pad4;
} LookAtDir;

typedef struct {
    /* 0x00 */ LookAtDir l[2];
} LookAt;

typedef struct {
    /* 0x00 */ s32 x1;
    /* 0x04 */ s32 y1;
    /* 0x08 */ s32 x2;
    /* 0x0C */ s32 y2;
} Hilite;

/* Background object of the 2D microcode. */
typedef struct {
    /* 0x00 */ u16 imageX;
    /* 0x02 */ u16 imageW;
    /* 0x04 */ s16 frameX;
    /* 0x06 */ u16 frameW;
    /* 0x08 */ u16 imageY;
    /* 0x0A */ u16 imageH;
    /* 0x0C */ s16 frameY;
    /* 0x0E */ u16 frameH;
    /* 0x10 */ void *imagePtr;
    /* 0x14 */ u16 imageLoad;
    /* 0x16 */ u8 imageFmt;
    /* 0x17 */ u8 imageSiz;
    /* 0x18 */ u16 imagePal;
    /* 0x1A */ u16 imageFlip;
    /* 0x1C */ u16 tmemW;
    /* 0x1E */ u16 tmemH;
    /* 0x20 */ u16 tmemLoadSH;
    /* 0x22 */ u16 tmemLoadTH;
    /* 0x24 */ u16 tmemSizeW;
    /* 0x26 */ u16 tmemSize;
} uObjBg;

void guMtxIdentF(MtxF mf);
void guMtxF2L(MtxF mf, Mtx *m);
void guMtxL2F(MtxF mf, Mtx *m);
void guNormalize(f32 *x, f32 *y, f32 *z);

void func_8008ABF0(MtxF mf, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale); /* guPerspectiveF */
void guPerspective(Mtx *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void guLookAtF(MtxF mf, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void guLookAt(Mtx *m, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void guLookAtHiliteF(MtxF mf, LookAt *l, Hilite *h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                     f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 twidth, s32 theight);
void guLookAtHilite(Mtx *m, LookAt *l, Hilite *h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                    f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 twidth, s32 theight);
void guPositionF(MtxF mf, f32 roll, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z);
void guPosition(Mtx *m, f32 roll, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z);
void guRotateF(MtxF mf, f32 a, f32 x, f32 y, f32 z);
void guRotate(Mtx *m, f32 a, f32 x, f32 y, f32 z);
void guOrthoF(MtxF mf, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale);
void guOrtho(Mtx *m, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale);
void guS2DInitBg(uObjBg *bg);

extern f32 D_80098180; /* pi/180 */

void MtxConv_F2L(Mtx *mtx, MtxF mf);
void MtxConv_L2F(MtxF mf, Mtx *mtx);

#endif
