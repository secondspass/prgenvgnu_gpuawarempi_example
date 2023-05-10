module load PrgEnv-gnu
module load craype-accel-amd-gfx90a
module load amd-mixed

export MPICH_GPU_SUPPORT_ENABLED=1

CC -I. -c gpuawarempignu.cpp

hipcc --amdgpu-target=gfx90a  -I${MPICH_DIR}/include -I. -c hipstuff.cpp

CC -L${ROCM_PATH}/lib -lamdhip64  ${PE_MPICH_GTL_DIR_amd_gfx90a} ${PE_MPICH_GTL_LIBS_amd_gfx90a} -o gpuawarempignu gpuawarempignu.o hipstuff.o
