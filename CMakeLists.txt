#  @file CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
#  @brief Vix AI NN module.
#
#  Header-only neural network module for Vix.
#  Provides neural network primitives such as layers, networks,
#  and optimizers.
#
#  Public targets:
#    - vix_ai_nn
#    - vix::ai::nn
#
#  Installation:
#    Installs headers, exported targets, and CMake package files
#    for find_package(vix_ai_nn CONFIG REQUIRED).

cmake_minimum_required(VERSION 3.20)

project(vix_ai_nn VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(VIX_AI_NN_BUILD_TESTS "Build vix_ai_nn tests" OFF)
option(VIX_AI_NN_INSTALL "Install vix_ai_nn targets" ON)
option(VIX_AI_NN_WARNINGS "Enable extra warnings for vix_ai_nn" ON)

if(DEFINED VIX_AI_VERSION)
  set(PROJECT_VERSION ${VIX_AI_VERSION})
endif()

add_library(vix_ai_nn INTERFACE)
add_library(vix::ai::nn ALIAS vix_ai_nn)

target_include_directories(vix_ai_nn INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(vix_ai_nn INTERFACE cxx_std_20)

target_compile_definitions(vix_ai_nn INTERFACE
  VIX_AI_NN_VERSION="${PROJECT_VERSION}"
)

if(VIX_AI_NN_WARNINGS)
  if(MSVC)
    target_compile_options(vix_ai_nn INTERFACE /W4 /permissive-)
  else()
    target_compile_options(vix_ai_nn INTERFACE
      -Wall
      -Wextra
      -Wpedantic
    )
  endif()
endif()

if(VIX_AI_NN_BUILD_TESTS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()

if(VIX_AI_NN_INSTALL)
  install(TARGETS vix_ai_nn
    EXPORT vix_ai_nnTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

  install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
  )

  install(EXPORT vix_ai_nnTargets
    FILE vix_ai_nnTargets.cmake
    NAMESPACE vix::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nn
  )

  configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/vix_ai_nnConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nnConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nn"
  )

  write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nnConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

  install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nnConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nnConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nn"
  )
endif()

message(STATUS "vix::ai::nn configured (${PROJECT_VERSION})")
message(STATUS "Include dir: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install: ${VIX_AI_NN_INSTALL}")
message(STATUS "Tests: ${VIX_AI_NN_BUILD_TESTS}")
