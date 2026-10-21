# ZMM N64 Europe C

Reconstruction en C de **The Legend of Zelda: Majora's Mask** (Europe, Rev 1, code `NZSP`),
à partir de la ROM du propriétaire de ce dépôt. Objectif : un code C lisible et modifiable,
vérifié octet par octet contre la ROM, puis un port PC natif.

> **Ce projet est réalisé en grande majorité par intelligence artificielle.**
> L'IA écrit le code C, cherche les correspondances avec la ROM et construit les outils ; le résultat n'est jamais
> accepté sur parole : chaque fonction est recompilée avec le compilateur d'origine et comparée à la ROM par un
> contrôle automatique (`make verify`).

**Aucune ROM ni donnée extraite de la ROM n'est dans ce dépôt** (`baserom/`, `extracted/`, `asm/`,
`decomp/` sont ignorés par git). Il faut fournir sa propre ROM :
`baserom/The Legend of Zelda Majora's Mask (Europe).z64`, SHA-1 `bb4e4757d10727c7584c59c1f2e5f44196e9c293`.

## État

Chiffres à jour : [docs/PROGRESS.md](docs/PROGRESS.md) (`make progress`). Feuille de route : [docs/ROADMAP.md](docs/ROADMAP.md).

| Étape | Résultat |
|---|---|
| Extraction des 1573 fichiers de la ROM (`tools/extract.py`) | fait |
| `boot` et `code` découpés en assembleur et réassemblés à l'identique | fait, identique octet pour octet |
| `boot` : fonctions réécrites en C et vérifiées contre la ROM | en cours (plus de la moitié des fonctions) |
| `boot` reconstruit depuis le C + l'assembleur restant | fait, identique à la ROM |
| `code` : fonctions en C | à faire (la chaîne de construction est prête) |
| Overlays (acteurs, scènes), reconstruction de la ROM complète | à faire |
| Port PC (rendu, audio, entrées) | à faire |

## Utilisation

```bash
# Windows : python tools/extract.py
# WSL Ubuntu : sudo apt install -y binutils-mips-linux-gnu python3-venv python3-pip && make setup
. ~/zmm-venv/bin/activate
make split                 # désassemblage de boot et code
make verify SEG=boot       # chaque fonction C == octets de la ROM, et le segment reconstruit == ROM
make progress              # met à jour docs/PROGRESS.md
```

Écrire ou corriger une fonction : voir [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md).

## Crédits

Ce projet repose sur le travail de la communauté de décompilation N64. Merci aux auteurs de :

- **[splat](https://github.com/ethteck/splat)** (ethteck) : découpe d'une ROM en assembleur et en segments
- **[spimdisasm](https://github.com/Decompollaborate/spimdisasm)** et **[rabbitizer](https://github.com/Decompollaborate/rabbitizer)** (Decompollaborate) : désassembleur MIPS utilisé par splat
- **[ido-static-recomp](https://github.com/decompals/ido-static-recomp)** (decompals) : le compilateur IDO 7.1 d'origine, recompilé pour Linux, indispensable pour vérifier le C à l'octet près
- **[decomp-permuter](https://github.com/simonlindholm/decomp-permuter)** (Simon Lindholm et contributeurs) : recherche automatique de variantes de C qui correspondent à la ROM
- **[m2c](https://github.com/matt-kempster/m2c)** (Matt Kempster et contributeurs) : décompilateur MIPS vers C
- **[asm-differ](https://github.com/simonlindholm/asm-differ)** (Simon Lindholm et contributeurs) : comparaison d'assembleur
- **[Ghidra](https://github.com/NationalSecurityAgency/ghidra)** (NSA) : analyse et pseudo-C de départ
- **GNU binutils** : assembleur, éditeur de liens, `objcopy`

Les noms, les licences et les droits de ces outils restent à leurs auteurs.
The Legend of Zelda: Majora's Mask est une marque et une œuvre de Nintendo ; ce projet n'est pas affilié à Nintendo.
