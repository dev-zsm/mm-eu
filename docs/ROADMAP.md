# Feuille de route

État chiffré : `docs/PROGRESS.md` (`make progress`). Vérification : `make verify`.

## 1. `boot` à 100 % (en cours)
- [x] Extraction, découpage splat, reconstruction identique, outil de correspondance IDO, permuter.
- [ ] Toutes les fonctions faisables en C (passes : agents, permuter, 2e passage par modèle plus fort).
- [ ] Fonctions écrites en assembleur à l'origine : listées dans `config/boot.asm_only.txt`, gardées en `.s` (`asm/boot/`), non comptées.
- [ ] Noms : SDK (libultra / libc / libm) certains, sinon déduits, avec preuve dans `config/boot.names.txt`.
- [ ] Organisation par modules (`src/libultra/os/…`, `src/libc/…`, `src/libm/…`) et en-têtes partagés (`OSThread`, `OSMesgQueue`, registres matériels).
- [ ] Données (`.data` / `.rodata` / jump tables / chaînes) reprises en C avec leurs types.
- [ ] Segment reconstruit sans aucun assembleur sauf les fonctions d'origine, identique à la ROM.

## 2. `code` (moteur principal, 3 576 fonctions) — même méthode
## 3. Overlays (acteurs, scènes, menus) : découpage de la table de fichiers, un fichier par overlay
## 4. ROM complète : recompression Yaz0 identique, reconstruction de la table de fichiers
## 5. Port PC : couche rendu / audio / entrées au-dessus du C
