cmake_minimum_required (VERSION 3.0.2)

# Enable optimization and link OpenMP
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fopenmp")

if(NOT EXISTS include/fmt)
    message("Fmt library not found, initializing git submodule...")
    execute_process(COMMAND git submodule update --init -- include/fmt WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

add_subdirectory(include/fmt)

file( GLOB problems problem*.cpp  )
foreach( problem ${problems} )    
    # Store relative filename without ".cpp" in outname
    get_filename_component(outname ${problem} NAME_WE)


	add_executable( ${outname}.out ${problem}  )    
    target_link_libraries(${outname}.out fmt::fmt)
endforeach()
