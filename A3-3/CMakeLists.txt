cmake_minimum_required (VERSION 3.2)
project(A3-3)

# options for the C++ compiler 
set(CMAKE_CXX_STANDARD 14)

# find the SDL2 framework and set include and library path accordingly
if (WIN32)
   link_directories(../SDL2-2.0.5/lib/x86)  # customize your path here, this must be specified before add_executable
else()
   find_package(SDL2 REQUIRED)
endif()


# which sources to parse (only .cpp, no .h)
set(sources main.cpp Application.h Window.h Surface.h Widget.h Button.h ImgButton.h Tile.h Canvas.h)

add_executable        ( A3-3 ${sources} )
target_link_libraries ( A3-3 LINK_PUBLIC SDL2 )

if (WIN32)
   target_include_directories( A3-3 PUBLIC ../SDL2-2.0.5/ )      # customize your path here
   target_link_libraries ( A3-3 LINK_PUBLIC sdl2 kernel32 user32 Wldap32 shell32
                                                 winmm imm32 ole32 oleaut32 gdi32 Version )
endif()
