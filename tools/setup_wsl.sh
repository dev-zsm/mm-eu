#!/bin/bash
# One-time setup inside WSL Ubuntu. Needs: sudo apt install -y binutils-mips-linux-gnu python3-venv python3-pip
set -e
cd "$(dirname "$0")/.."
mkdir -p tools/vendor build && cd tools/vendor
[ -d m2c ] || git clone --depth 1 https://github.com/matt-kempster/m2c.git
[ -d asm-differ ] || git clone --depth 1 https://github.com/simonlindholm/asm-differ.git
if [ ! -d ido71 ]; then
  mkdir ido71
  curl -sL https://github.com/decompals/ido-static-recomp/releases/download/v1.2/ido-7.1-recomp-linux.tar.gz | tar -xz -C ido71
fi
cd ../..
[ -d ~/zmm-venv ] || python3 -m venv ~/zmm-venv
. ~/zmm-venv/bin/activate
pip -q install "splat64[mips]" pycparser
pip -q install -r tools/vendor/m2c/requirements.txt 2>/dev/null || true
