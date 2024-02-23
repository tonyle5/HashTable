cmake_minimum_required(VERSION 3.24)
project(my_project)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find all source files in src directory and its subdirectories
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Include directories
include_directories(include)

# Get a list of subdirectories in the 'src' directory
file(GLOB SUBDIRECTORIES LIST_DIRECTORIES true src/*)

# Iterate over each subdirectory
foreach(subdir ${SUBDIRECTORIES})
    # Check if it is a directory
    if(IS_DIRECTORY ${subdir})
        # Extract the directory name from the full path
        get_filename_component(subdir_name ${subdir} NAME)
        # Add the subdirectory
        add_subdirectory(src/${subdir_name})
    endif()
endforeach()

# Create the executable
add_executable(my_project ${SOURCES})

# Link the libraries
target_link_libraries(my_project myUtil Table Website)

# Specify the source directory where your .txt files are located
set(SOURCE_TXT_DIR ${CMAKE_SOURCE_DIR})

# Use the file(GLOB ...) command to find and copy all .txt files to the build directory
file(GLOB TXT_FILES ${SOURCE_TXT_DIR}/*.txt)

# Specify the destination directory where you want to copy the .txt files in the build directory
set(DEST_TXT_DIR ${CMAKE_BINARY_DIR})

# Use the file(COPY ...) command to copy the .txt files to the build directory
file(COPY ${TXT_FILES} DESTINATION ${DEST_TXT_DIR})
