cmake_minimum_required (VERSION 3.11)
project(onfi_analyzer)
# enable generation of compile_commands.json, helpful for IDEs to locate include files.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# custom CMake Modules are located in the cmake directory.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include_directories(AnalyzerSDK/include)
include_directories(AnalyzerSDK/lib)

set(SOURCES
        source/ONFIAnalyzer.cpp
        source/ONFIAnalyzer.h
        source/ONFIAnalyzerResults.cpp
        source/ONFIAnalyzerResults.h
        source/ONFIAnalyzerSettings.cpp
        source/ONFIAnalyzerSettings.h
        source/ONFISimulationDataGenerator.cpp
        source/ONFISimulationDataGenerator.h
        )

#add_analyzer_plugin(onfi_analyzer SOURCES ${SOURCES})