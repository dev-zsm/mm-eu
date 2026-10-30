typedef struct { char pad[0x15C]; int unk15C; } A;
extern void (*D_808F92F4[])();
void func_80000FE8(A *a) { if (D_808F92F4[a->unk15C] != 0) { D_808F92F4[a->unk15C](); } }
