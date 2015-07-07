cmake_minimum_required(VERSION 3.2)
project(Calculator_ProofOfConcept)

# Find the GTK module using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER} -std=c++11)
# Add an executable compiled from hello.c
set(SOURCE_FILES hello.cpp control/Handlers.cpp control/Handlers.h view/MainFrame.cpp view/MainFrame.h model/Calculator.cpp model/Calculator.h)
add_executable(Calculator_ProofOfConcept ${SOURCE_FILES} model/Operation.cpp model/Operation.h model/MODES.h)
target_link_libraries(Calculator_ProofOfConcept ${GTK3_LIBRARIES})
