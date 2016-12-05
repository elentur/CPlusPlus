cmake_minimum_required (VERSION 3.2)
project(A3_1)

# options for the C++ compiler 
set(CMAKE_CXX_STANDARD 14)

# find the SDL2 framework and set include and library path accordingly 
if (WIN32) 
   link_directories(SDL2-2.0.5/lib/x86)  # customize your path here, this must be specified before add_executable
else()
    #link_directories(SDL2-2.0.5/lib/x64)
    find_package(SDL2 REQUIRED)
endif()


# which sources to parse (only .cpp, no .h)
set(SOURCE_FILES  main.cpp Application.h)

add_executable        ( A3_1 ${SOURCE_FILES} )
target_link_libraries ( A3_1 LINK_PUBLIC sdl2 )

if (WIN32)
   target_include_directories( A3_1 PUBLIC SDL2-2.0.5/ )      # customize your path here
   target_link_libraries ( A3_1 LINK_PUBLIC sdl2 kernel32 user32 Wldap32 shell32
                                                 winmm imm32 ole32 oleaut32 gdi32 Version )
endif()
