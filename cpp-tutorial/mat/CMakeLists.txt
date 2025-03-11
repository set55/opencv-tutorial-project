cmake_minimum_required(VERSION 3.10)
project( mat )

# Tell CMake to look for OpenCV in Conda
# set(OpenCV_DIR $ENV{CONDA_PREFIX}/lib/cmake/opencv4)
set(OpenCV_DIR /home/set/local/lib/cmake/opencv4) # use native OpenCV
find_package( OpenCV REQUIRED )

message(STATUS "OpenCV Include Path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV Library Path: ${OpenCV_LIBS}")

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( mat mat.cpp )
target_link_libraries( mat ${OpenCV_LIBS} )