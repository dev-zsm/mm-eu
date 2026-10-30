typedef struct { char pad[0x1C]; short unk1C; } A;
typedef struct { char pad[0x1F34]; unsigned short unk1F34; } G;
void func_800B8C4C();
void func_80000764(A *a, G *g) { if (a->unk1C != 0 && g->unk1F34 == 0x1D3) { func_800B8C4C(a, 0x2924); } }
