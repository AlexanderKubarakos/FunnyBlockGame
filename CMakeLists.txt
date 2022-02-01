cmake_minimum_required(VERSION 3.10)

project("FunnyBlockGame")

#GLFW
set(GLFW3_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/includes)
set(GLFW3_LIBRARY ${PROJECT_SOURCE_DIR}/libs/libglfw3.a)
include_directories(${GLFW3_INCLUDE_DIR}) 

link_directories(${PROJECT_SOURCE_DIR}/libs)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "funnyblockgame/*.c" "funnyblockgame/*.h" "funnyblockgame/*.cpp" "funnyblockgame/*.hpp")
file(GLOB SRC2 CONFIGURE_DEPENDS "*.c" "*.h" "*.cpp" "*.hpp")
list(APPEND SRC ${SRC2})
add_executable(FunnyBlockGame ${SRC})

target_link_libraries(
        ${PROJECT_NAME}
        ${GLFW3_LIBRARY}   
)
message("HELLO ITS ME")
message(${GLFW3_INCLUDE_DIR})


set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++17 standard compliance
    CXX_STANDARD 17
)