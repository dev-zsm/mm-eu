// FLAGS: -O2 -g0
#include "types.h"
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; u8 unk4; u8 unk5; s8 unk6; s8 unk7; } Entry;
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; u8 unk4; u8 unk5; } Out;
extern Entry D_8009D2A0[];
extern u8 D_8009D2E1;

void func_8008A1B4(Out *out) { s32 i; Entry tmp; Entry *src; src = D_8009D2A0; i = 0; while (i < D_8009D2E1) { tmp = *src; out->unk4 = (tmp.unk2 & 0xC0) >> 4; if (out->unk4 == 0) { *(u16 *)&out->unk0 = *(u16 *)&tmp.unk4; out->unk2 = tmp.unk6; out->unk3 = tmp.unk7; } src++; out++; i++; } }
