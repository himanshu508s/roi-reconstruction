cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(upsample)

find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set( GSL_FOUND OFF )
set( GSL_CBLAS_FOUND OFF )
 

 
    find_program( GSL_CONFIG_EXECUTABLE gsl-config
      /usr/bin/
      /usr/local/bin
    )
     
    if( GSL_CONFIG_EXECUTABLE )
      set( GSL_FOUND ON )
       
      # run the gsl-config program to get cxxflags
      execute_process(
        COMMAND sh "${GSL_CONFIG_EXECUTABLE}" --cflags
        OUTPUT_VARIABLE GSL_CFLAGS
        RESULT_VARIABLE RET
        ERROR_QUIET
        )
      if( RET EQUAL 0 )
        string( STRIP "${GSL_CFLAGS}" GSL_CFLAGS )
        separate_arguments( GSL_CFLAGS )
 
        # parse definitions from cflags; drop -D* from CFLAGS
        string( REGEX MATCHALL "-D[^;]+"
          GSL_DEFINITIONS  "${GSL_CFLAGS}" )
        string( REGEX REPLACE "-D[^;]+;" ""
          GSL_CFLAGS "${GSL_CFLAGS}" )
 
        # parse include dirs from cflags; drop -I prefix
        string( REGEX MATCHALL "-I[^;]+"
          GSL_INCLUDE_DIRS "${GSL_CFLAGS}" )
        string( REPLACE "-I" ""
          GSL_INCLUDE_DIRS "${GSL_INCLUDE_DIRS}")
        string( REGEX REPLACE "-I[^;]+;" ""
          GSL_CFLAGS "${GSL_CFLAGS}")
 
        message("GSL_DEFINITIONS=${GSL_DEFINITIONS}")
        message("GSL_INCLUDE_DIRS=${GSL_INCLUDE_DIRS}")
        message("GSL_CFLAGS=${GSL_CFLAGS}")
      else( RET EQUAL 0 )
        set( GSL_FOUND FALSE )
      endif( RET EQUAL 0 )
 
      # run the gsl-config program to get the libs
      execute_process(
        COMMAND sh "${GSL_CONFIG_EXECUTABLE}" --libs
        OUTPUT_VARIABLE GSL_LIBRARIES
        RESULT_VARIABLE RET
        ERROR_QUIET
        )
      if( RET EQUAL 0 )
        string(STRIP "${GSL_LIBRARIES}" GSL_LIBRARIES )
        separate_arguments( GSL_LIBRARIES )
 
        # extract linkdirs (-L) for rpath (i.e., LINK_DIRECTORIES)
        string( REGEX MATCHALL "-L[^;]+"
          GSL_LIBRARY_DIRS "${GSL_LIBRARIES}" )
        string( REPLACE "-L" ""
          GSL_LIBRARY_DIRS "${GSL_LIBRARY_DIRS}" )
      else( RET EQUAL 0 )
        set( GSL_FOUND FALSE )
      endif( RET EQUAL 0 )
       
      MARK_AS_ADVANCED(
        GSL_CFLAGS
      )
      message( STATUS "Using GSL from ${GSL_PREFIX}" )
    else( GSL_CONFIG_EXECUTABLE )
      message( STATUS "FindGSL: gsl-config not found.")
    endif( GSL_CONFIG_EXECUTABLE )


 

 
if( GSL_FOUND )
  if( NOT GSL_FIND_QUIETLY )
    message( STATUS "FindGSL: Found both GSL headers and library" )
	add_executable (upsample upsample.cpp)
	target_link_libraries (upsample ${PCL_LIBRARIES} ${GSL_LIBRARIES})
  endif( NOT GSL_FIND_QUIETLY )
else( GSL_FOUND )
  if( GSL_FIND_REQUIRED )
    message( FATAL_ERROR "FindGSL: Could not find GSL headers or library" )
  endif( GSL_FIND_REQUIRED )
endif( GSL_FOUND )

