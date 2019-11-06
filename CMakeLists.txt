cmake_minimum_required(VERSION 3.0)
project(pika-assembly)

set(CMAKE_CXX_STANDARD 17)


######
# Download and unpack googletest at configure time

configure_file(CmakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

include_directories(${CMAKE_BINARY_DIR}/googletest-src/googletest/include)
include_directories(${CMAKE_BINARY_DIR}/googletest-src/googlemock/include)

######

add_subdirectory(poem-sorting)
add_subdirectory(unbreakable-stack)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(poem-sorting/headers)
include_directories(unbreakable-stack/headers)
include_directories(headers)

execute_process(COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/instructions_handler.py ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(pika-assembly
               headers/PikaCompiler.h
               main.cpp sources/PikaCompiler.cpp
        headers/Instructions.h
        sources/Instructions.cpp headers/PikaExecutor.h sources/PikaExecutor.cpp headers/InstructionsDefines.h sources/GeneratedInstructions.cpp headers/GeneratedInstructions.h)



target_link_libraries(pika-assembly gtest gtest_main poem-sorting unbreakable_stack)
