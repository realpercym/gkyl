#!/bin/bash

# Build directory
OUT=build

# Install location
GKYL=$HOME/Desktop/PROJECT_DR_YAN/gkyl

# Compile flags (set optimization/debug flags here)
CC=/usr/bin/clang
CXX=/usr/bin/clang++
CXXFLAGS='-O3,-std=c++17'

# LuaJIT options
LUAJIT_INC_DIR=$GKYL/luajit/include/luajit-2.1
LUAJIT_LIB_DIR=$GKYL/luajit/lib
LUAJIT_SHARE_DIR=$GKYL/luajit/share

## MPI options
MPICC=/opt/homebrew/bin/mpicc
MPICXX=/opt/homebrew/bin/mpicxx
ENABLE_MPI="--enable-mpi"
MPI_INC_DIR=/opt/homebrew/include
MPI_LIB_DIR=/opt/homebrew/lib
MPI_LINK_LIBS="mpi"

# ADIOS options
ENABLE_ADIOS="--enable-adios"
ADIOS_INC_DIR=$GKYL/adios2/include
ADIOS_LIB_DIR=$GKYL/adios2/lib
ADIOS_LINK_LIBS="adios2_cxx11_mpi"

#OPENBLAS_INC_DIR=$GKYLSOFT/OpenBLAS/include
#OPENBLAS_LIB_DIR=$GKYLSOFT/OpenBLAS/lib

SUPERLU_INC_DIR=$GKYL/superlu_mt-4.0.0/include/superlu_mt
SUPERLU_LIB_DIR=$GKYL/superlu_mt-4.0.0/lib

GKYLZERO_INC_DIR=$GKYL/gkylzero/include
GKYLZERO_LIB_DIR=$GKYL/gkylzero/lib

PREFIX=$GKYL
# You probably do not need to modify the command itself
#cmd="./waf CC=$CC CXX=$CXX MPICC=$MPICC MPICXX=$MPICXX --out=$OUT -p $GKYL --prefix=$PREFIX --cxxflags=$CXXFLAGS --luajit-inc-dir=$LUAJIT_INC_DIR --luajit-lib-dir=$LUAJIT_LIB_DIR --luajit-share-dir=$LUAJIT_SHARE_DIR $ENABLE_MPI --mpi-inc-dir=$MPI_INC_DIR --mpi-lib-dir=$MPI_LIB_DIR --mpi-link-libs=$MPI_LINK_LIBS $ENABLE_ADIOS --adios-inc-dir=$ADIOS_INC_DIR --adios-lib-dir=$ADIOS_LIB_DIR --adios-link-libs=$ADIOS_LINK_LIBS --enable-gkylzero --gkylzero-inc-dir=$GKYLZERO_INC_DIR --gkylzero-lib-dir=$GKYLZERO_LIB_DIR --enable-superlu --superlu-inc-dir=$SUPERLU_INC_DIR --superlu-lib-dir=$SUPERLU_LIB_DIR --enable-openblas --openblas-inc-dir=$OPENBLAS_INC_DIR --openblas-lib-dir=$OPENBLAS_LIB_DIR configure"
cmd="./waf CC=$CC CXX=$CXX MPICC=$MPICC MPICXX=$MPICXX --out=$OUT -p $GKYL --prefix=$PREFIX --cxxflags=$CXXFLAGS --luajit-inc-dir=$LUAJIT_INC_DIR --luajit-lib-dir=$LUAJIT_LIB_DIR --luajit-share-dir=$LUAJIT_SHARE_DIR $ENABLE_MPI --mpi-inc-dir=$MPI_INC_DIR --mpi-lib-dir=$MPI_LIB_DIR --mpi-link-libs=$MPI_LINK_LIBS $ENABLE_ADIOS --adios-inc-dir=$ADIOS_INC_DIR --adios-lib-dir=$ADIOS_LIB_DIR --adios-link-libs=$ADIOS_LINK_LIBS --enable-gkylzero --gkylzero-inc-dir=$GKYLZERO_INC_DIR --gkylzero-lib-dir=$GKYLZERO_LIB_DIR --enable-superlu --superlu-inc-dir=$SUPERLU_INC_DIR --superlu-lib-dir=$SUPERLU_LIB_DIR configure"

# if we are in machines directory, go up a directory before executing cmd
if [ `dirname "$0"` == "." ] 
  then
    cd ..
fi
echo $cmd
$cmd


