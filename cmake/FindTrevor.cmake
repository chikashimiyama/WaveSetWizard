find_library(TREVOR_CORE_DEBUG
        NAMES libtrevor_core.a
        PATHS ${CMAKE_CURRENT_LIST_DIR}/../core/target/debug
        NO_DEFAULT_PATH)

find_library(TREVOR_CORE_RELEASE
        NAMES libtrevor_core.a
        PATHS ${CMAKE_CURRENT_LIST_DIR}/../core/target/release
        NO_DEFAULT_PATH)

add_library(Trevor::Core INTERFACE IMPORTED)

target_include_directories(Trevor::Core
        INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/../core/include")

target_link_libraries(Trevor::Core
        INTERFACE
        "$<$<CONFIG:Debug>:${TREVOR_CORE_DEBUG}>"
        "$<$<CONFIG:Release>:${TREVOR_CORE_RELEASE}>")
