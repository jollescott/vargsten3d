project(varg LANGUAGES C)

find_package(SDL2 REQUIRED)

add_executable(varg src/main.c src/wl6.h src/wl6.c "src/wolf.h" "src/wolf.c")
set_property(TARGET varg PROPERTY C_STANDARD 11)

if(MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS /SUBSYSTEM:CONSOLE)
endif()

target_link_libraries(varg PRIVATE vargsten SDL2::SDL2)
