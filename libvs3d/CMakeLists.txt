project(libvs3d)

set(LIBVS3D_SOURCES
    src/vs3d.c)

set(LIBVS3D_HEADERS
    include/vs3d.h)

add_library(libvs3d SHARED ${LIBVS3D_SOURCES} ${LIBVS3D_HEADERS})
target_include_directories(libvs3d PUBLIC include)
