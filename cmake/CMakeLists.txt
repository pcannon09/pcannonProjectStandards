# PCANNON CMAKELISTS.TXT v1.0S - FROM PCANNON PROJECT STANDARDS
# STANDARD: 20250608
# https://github.com/pcannon09/pcannonProjectStandards

cmake_minimum_required(VERSION 3.24)

# Link exec if only changed
cmake_policy(SET CMP0147 NEW)

# Read metadata
file(READ ".private/project.json" projectInfo)
string(JSON projectName GET "${projectInfo}" exeName)
string(JSON projectVersion GET "${projectInfo}" version)
string(JSON projectVersionState GET "${projectInfo}" versionState)
string(JSON projectVersionSTD GET "${projectInfo}" versionSTD)

set(VERSION "${projectVersion} ${version}")
set(VERSION_STATE "${projectVersionState} ${versionState}")
set(VERSION_STD "${projectVersionSTD}")

project(${projectName} VERSION ${projectVersion})

# Compiler flags
set(programCompileFlags
	-fsanitize=address,leak
    -g
    -Wunused
    -Wall
    -Wno-range-loop-analysis
)

set(programLinkFlags
	-fsanitize=address,leak
    -g
)

set(CPP_STD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)

set(CMAKE_AUTOGEN_VERBOSE ON)

set(CMAKE_CXX_STANDARD ${CPP_STD})
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

# Directory setup
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INC_DIR "${CMAKE_SOURCE_DIR}/inc")
set(VENDOR_DIR "${CMAKE_SOURCE_DIR}/vendor")

# Project files
set(HEADERS
    ${incDir}/predefines.hpp
)

set(SOURCES
    ${srcDir}/main.cpp
)

# Build the main executable
add_executable(${projectName}
    ${sources}
)

target_compile_options(${projectName} PRIVATE ${programCompileFlags})
target_link_options(${projectName} PRIVATE ${programLinkFlags})

target_link_libraries(${projectName} PRIVATE 
# NOTE: ADD LINK LIBRARIES HERE
)

target_sources(${projectName} PRIVATE 
# NOTE: ADD TARGET SOURCES HERE
)

# Include directories
target_include_directories(${projectName} PRIVATE
    ${INC_DIR}
# NOTE: ADD OTHER INLCUDE DIRECTORIES HERE
)

set_target_properties(${projectName} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Show build config info
message(STATUS "${projectName} CXX Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "${projectName} version: ${VERSION}-${VERSION_STATE}")
message(STATUS "${projectName} Standard version: ${VERSION_STD}")

