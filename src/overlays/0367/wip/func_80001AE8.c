typedef struct { char pad[0x2A8]; void *unk2A8; char pad2[6]; short unk2B2; } A;
extern char D_80A63134[];
void func_80A61610();
void func_80001AE8(A *a) { func_80A61610(a, 2); a->unk2A8 = D_80A63134; a->unk2B2 = 5; }
