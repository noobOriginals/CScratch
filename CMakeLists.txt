cmake_minimum_required(VERSION 3.9.1)


project(CScratch)

set (OSBitness 32)
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set (OSBitness 64)
endif()

set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${OSBitness}/${CMAKE_BUILD_TYPE}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

set (SrcPath "${CMAKE_SOURCE_DIR}/src/source files")
set (IncludePath "${CMAKE_SOURCE_DIR}/src/headers")
set (ResourcePath "${CMAKE_SOURCE_DIR}/src/resource files")

include_directories(${PROJECT_NAME} ${IncludePath})
include_directories(${PROJECT_NAME} ${SrcPath})
include_directories(${PROJECT_NAME} $ENV{OPENGL_PATH})

link_directories(${FullOutputDir})

add_library(graphics SHARED ${SrcPath}/window.cpp ${SrcPath}/image.cpp ${SrcPath}/glad.c ${SrcPath}/stb_image.cpp)
target_link_libraries(graphics glfw3 opengl32)

add_library(cScratch SHARED ${SrcPath}/scratch.cpp ${SrcPath}/sprite.cpp ${SrcPath}/costume.cpp)
target_link_libraries(cScratch graphics)

add_executable(${PROJECT_NAME} ${SrcPath}/main.cpp)

add_custom_target(
    copy_res ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ResourcePath}
    ${FullOutputDir}
    COMMENT "Copying resources into binary directory"
)
add_dependencies(${PROJECT_NAME} copy_res)

target_link_libraries(${PROJECT_NAME} cScratch)
