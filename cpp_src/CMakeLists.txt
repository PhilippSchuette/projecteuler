cmake_minimum_required (VERSION 3.0.2)

# Enable optimization and link OpenMP
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fopenmp")

file( GLOB problems problem*.cpp  )
foreach( problem ${problems} )    
    # Store relative filename without ".cpp" in outname
    get_filename_component(outname ${problem} NAME_WE)


	add_executable( ${outname}.out ${problem}  )    
endforeach()
