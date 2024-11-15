#!/bin/bash

source ./build-opts.sh

## This script builds LuaJIT using the luajit git repo.

# Install prefix
PREFIX=$GKYL/luajit

# delete old checkout and builds
rm -rf $PREFIX

git clone https://luajit.org/git/luajit.git
cd luajit
make PREFIX=$PREFIX CC=$CC CFLAGS=-fPIC
make XCFLAGS=-DLUAJIT_ENABLE_GC64 install PREFIX=$PREFIX

# softlink to make finding easier
#ln -sfn $PREFIX $GKYL/luajit

# soft-link executable name "lua". This allows running various tools
# (luarocks) needing lua executable to run
ln -sfn $PREFIX/bin/luajit $PREFIX/bin/lua


