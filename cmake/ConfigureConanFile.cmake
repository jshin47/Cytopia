# Comment-out uneeded libs
if (NOT ENABLE_AUDIO)
    set(_CC_SDL2_MIXER "# ")
endif ()

if (NOT ENABLE_AUDIO)
    set(_CC_OPENAL_SOFT "# ")
endif ()

if (NOT BUILD_TEST)
    set(_CC_CATCH2 "# ")
endif ()

if (NOT ENABLE_ANGELSCRIPT)
    set(_CC_ANGELSCRIPT "# ")
endif ()

if (NOT ENABLE_MOFILEREADER)
    set(_CC_MOFILEREADER "# ")
endif ()

if (WIN32)
    set(_CC_WIN32 "# ")
else()
    set(_CC_LINUX "# ")
endif ()

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/conanfile.txt.in" "${CMAKE_CURRENT_SOURCE_DIR}/conanfile.txt")