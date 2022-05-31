cmake_minimum_required(VERSION 3.12.2)

project(2DGameEngine)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release"
    CACHE STRING "Configuration types" FORCE)

add_executable(2DGameEngine
  2DGameEngine.rc
  Assets/player.png
  Assets/sky.jpg
  resource.h
  Sources/Game.cpp
  Sources/GameObject.cpp
  Sources/Headers/Game.h
  Sources/Headers/GameObject.h
  Sources/Headers/Rectangle.h
  Sources/Headers/TexGameObject.h
  Sources/Headers/TextureManager.h
  Sources/main.cpp
  Sources/Rectangle.cpp
  Sources/TexGameObject.cpp
  Sources/TextureManager.cpp
)
# Preprocessor definitions
target_compile_definitions(2DGameEngine PRIVATE
  $<$<CONFIG:Debug>:_MBCS;>
  $<$<CONFIG:Release>:_MBCS;>
)

# SDL check
target_compile_options(2DGameEngine PRIVATE
  "$<$<CONFIG:Debug>:/sdl>"
  "$<$<CONFIG:Release>:/sdl>"
)

# Minimal rebuild
if (MSVC)
  target_compile_options(2DGameEngine PRIVATE
    "$<$<CONFIG:Debug>:/Gm->"
    "$<$<CONFIG:Release>:/Gm->"
  )
endif ()

# Precompiled header files
if (MSVC)
  target_compile_options(2DGameEngine PRIVATE
    ""
  )
endif ()
