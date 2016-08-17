cmake_minimum_required(VERSION 3.5)
project(base_platform)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB MIPS mips/*.cpp)
FILE(GLOB BUS bus/*.cpp)
FILE(GLOB MMU mmu/*.cpp)
FILE(GLOB MEMORY memory/*.cpp)
FILE(GLOB GPTIMER gptimer/*.cpp)
FILE(GLOB IRQMP irqmp/*.cpp)
SET(SOURCE_FILES ${MIPS} ${BUS} ${MEMORY} ${GPTIMER} ${IRQMP} ${TLB} main.cpp)

file(GLOB_RECURSE AC_HEADERS "../acinstall/include/*.H")
file(GLOB_RECURSE SC_HEADERS "../systemcinstall/include/*.h")
set(Foo_HEADERS ${AC_HEADERS} ${SC_HEADERS})

set (Foo_INCLUDE_DIRS "")
foreach (_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

include_directories(${Foo_INCLUDE_DIRS})
add_executable(eocs-mips-platform ${SOURCE_FILES} main.cpp)