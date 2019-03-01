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

add_executable(tests ${problems} test.cpp)
# Define TESTING which will disable the main() functions in the problemxxx.cpp files
target_compile_definitions(tests PRIVATE TESTING)
# Link fmt and Catch2
target_link_libraries(tests Catch2::Catch2 fmt::fmt)
set_target_properties(tests PROPERTIES EXCLUDE_FROM_ALL TRUE)
set_target_properties(tests PROPERTIES OUTPUT_NAME tests.out)
add_custom_command(TARGET tests POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests.out
    COMMENT "Running Tests..."
)
