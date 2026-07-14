#!/bin/sh

mkdir build0
meson setup build0
meson compile -C build0

mkdir build-w64
meson setup build-w64 --cross-file x86_64-w64-mingw32.txt
meson compile -C build-w64

cd build-w64
if [ ! -e "wine" ]; then
  ln -sf tools/wine/wine wine
fi
cd ..
