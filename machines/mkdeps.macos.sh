# if we are in machines directory, go up a directory
if [ `dirname "$0"` == "." ] 
  then
    cd ..
fi

export GKYL=$HOME/Desktop/PROJECT_DR_YAN/gkyl
export MACHINE_NAME='macos'
cd install-deps

# 1) Build OpenMPI.
#./mkdeps.sh CC=/usr/bin/clang CXX=/usr/bin/clang++ --build-openmpi=no --build-luajit=no  --prefix=$GKYL

# 2) Build gkylzero (already compiled independently) and adios.
./mkdeps.sh \
CC=clang CXX=clang++ \
MPICC=/opt/homebrew/bin/mpicc \
MPICXX=/opt/homebrew/bin/mpicxx \
--prefix=$GKYL \
--build-adios=yes 
# --build-gkylzero=no 
# --build-luajit=no
# --build-openmpi=no

# 3) Build luajit. Some Macs (newer ones) have to comment out the next 2 lines.
# Get OSX version (XX.XX.X) and remove patch version so that only XX.X is
# assigned to MACOSX_DEPLOYMENT_TARGET.
vers=`sw_vers -productVersion`
export MACOSX_DEPLOYMENT_TARGET=${vers%.*}
./mkdeps.sh \
CC=/usr/bin/clang \
CXX=/usr/bin/clang++ \
MPICC=/opt/homebrew/bin/mpicc \
MPICXX=/opt/homebrew/bin/mpicxx \
--prefix=$GKYL \
--build-luajit=yes
# --build-openmpi=no 


