cmake_minimum_required (VERSION 3.0.2)

# Enable optimization and link OpenMP
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -fopenmp")

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

file( GLOB problems problem*.cpp  )
foreach( problem ${problems} )    
    # Store relative filename without ".cpp" in outname
    get_filename_component(outname ${problem} NAME_WE)

	add_executable( ${outname}.out ${problem}  )    

    # Link fmt
    target_link_libraries(${outname}.out fmt::fmt)
endforeach()

# Include "Catch" library 
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/Catch2)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

add_executable(test ${problems} test.cpp)
# Define TESTING which will disable the main() functions in the problemxxx.cpp files
target_compile_definitions(test PRIVATE TESTING)
target_link_libraries(test Catch fmt::fmt)
set_target_properties(test PROPERTIES EXCLUDE_FROM_ALL TRUE)
set_target_properties(test PROPERTIES OUTPUT_NAME test.out)
add_custom_command(TARGET test POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/test.out
    COMMENT "Running Tests..."
)
