project(varg LANGUAGES C)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(varg src/main.c src/wl6.h src/wl6.c)
set_property(TARGET varg PROPERTY C_STANDARD 11)

target_link_libraries(varg vargsten ${SDL2_INCLUDE_LIBS})
