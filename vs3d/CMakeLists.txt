project(vs3d LANGUAGES C)

add_executable(vs3d src/main.c)
target_link_libraries(vs3d libvs3d)
