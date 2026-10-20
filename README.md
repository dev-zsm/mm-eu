# ZMM N64 Europe C

Reconstruction en C de **The Legend of Zelda: Majora's Mask** (Europe, Rev 1, code `NZSP`),
à partir de la ROM du propriétaire de ce dépôt. Objectif : un code C lisible et modifiable,
vérifié octet par octet contre la ROM, puis un port PC natif.

**Aucune ROM ni donnée extraite de la ROM n'est dans ce dépôt** (`baserom/`, `extracted/`, `asm/`,
`decomp/` sont ignorés par git). Il faut fournir sa propre ROM :
`baserom/The Legend of Zelda Majora's Mask (Europe).z64`, SHA-1 `bb4e4757d10727c7584c59c1f2e5f44196e9c293`.

## État

| Étape | Résultat |
|---|---|
| Extraction des 1573 fichiers (`tools/extract.py`) | fait |
| Pseudo-C Ghidra de `boot` et `code` (`tools/decomp.py`) | fait (353 + 3164 fonctions) |
| `boot` et `code` découpés en assembleur et réassemblés à l'identique (`tools/verify_asm.sh`) | **identique, octet pour octet** |
| Remplacer l'assembleur par du C, fonction par fonction, vérifié avec IDO 7.1 | à faire |
| Overlays (acteurs, scènes), reconstruction de la ROM complète | à faire |
| Port PC (rendu, audio, entrées) | à faire |

## Utilisation

```bash
# Windows : python tools/extract.py
# WSL Ubuntu : sudo apt install -y binutils-mips-linux-gnu python3-venv python3-pip && bash tools/setup_wsl.sh
. ~/zmm-venv/bin/activate
splat split config/boot.yaml && splat split config/code.yaml
bash tools/verify_asm.sh boot build/boot.bin
bash tools/verify_asm.sh code extracted/0049_00C8A000.bin
```

## Crédits

Ce projet repose sur le travail de la communauté de décompilation N64. Merci aux auteurs de :

- **[splat](https://github.com/ethteck/splat)** (ethteck) : découpe d'une ROM en assembleur et en segments
- **[spimdisasm](https://github.com/Decompollaborate/spimdisasm)** et **[rabbitizer](https://github.com/Decompollaborate/rabbitizer)** (Decompollaborate) : désassembleur MIPS utilisé par splat
- **[ido-static-recomp](https://github.com/decompals/ido-static-recomp)** (decompals) : le compilateur IDO 7.1 d'origine, recompilé pour Linux, indispensable pour vérifier le C à l'octet près
- **[m2c](https://github.com/matt-kempster/m2c)** (Matt Kempster et contributeurs) : décompilateur MIPS vers C
- **[asm-differ](https://github.com/simonlindholm/asm-differ)** (Simon Lindholm et contributeurs) : comparaison d'assembleur
- **[Ghidra](https://github.com/NationalSecurityAgency/ghidra)** (NSA) : analyse et pseudo-C de départ
- **GNU binutils** : assembleur, éditeur de liens, `objcopy`

Les noms, les licences et les droits de ces outils restent à leurs auteurs.
The Legend of Zelda: Majora's Mask est une marque et une œuvre de Nintendo ; ce projet n'est pas affilié à Nintendo.
