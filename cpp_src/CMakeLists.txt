cmake_minimum_required (VERSION 3.0.2)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)

option(GCOV "GCOV" OFF)
if(GCOV) 
    set(CMAKE_CXX_FLAGS "--coverage ${OpenMP_CXX_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS "-O2 -march=native -fopenmp ${OpenMP_CXX_FLAGS}")
endif()

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Include fmt libary
if(NOT EXISTS include/fmt/include)
    message("Fmt library not found, initializing git submodule...")
    execute_process(COMMAND git submodule update --init -- include/fmt WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
add_subdirectory(include/fmt)

# Include Catch2 library
if(NOT EXISTS include/Catch2/include)
    message("Catch2 not found, initializing git submodule...")
    execute_process(COMMAND git submodule update --init -- include/Catch2 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
add_subdirectory(include/Catch2)

# prime_utils.cpp is used in multiple executables, 
# so by making it a static library we only have to 
# build it once, thus reducing compilation time
add_library(prime_utils STATIC prime_utils.cpp)

file( GLOB problems problem*.cpp  )
foreach( problem ${problems} )    
    # Store relative filename without ".cpp" in outname
    get_filename_component(outname ${problem} NAME_WE)

	add_executable( ${outname}.out ${problem} )    

    # Link fmt
    target_link_libraries(${outname}.out fmt::fmt prime_utils)
endforeach()

add_executable(tests ${problems} tests-main.cpp tests.cpp prime_utils.cpp)
# Define TESTING which will disable the main() functions in the problemxxx.cpp files
target_compile_definitions(tests PRIVATE TESTING)
# Link fmt, Catch2 and prime_utils
target_link_libraries(tests Catch2::Catch2 fmt::fmt prime_utils)
set_target_properties(tests PROPERTIES EXCLUDE_FROM_ALL TRUE)
set_target_properties(tests PROPERTIES OUTPUT_NAME tests.out)
