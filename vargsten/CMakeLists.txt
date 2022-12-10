project(vargsten LANGUAGES C)

set(VARGSTEN_SOURCES
    src/vargsten.c)

set(VARGSTEN_HEADERS
    include/vargsten.h)

add_library(vargsten SHARED ${VARGSTEN_SOURCES} ${VARGSTEN_HEADERS})
set_property(TARGET vargsten PROPERTY C_STANDARD 11)

target_include_directories(vargsten PUBLIC include)

