cmake_minimum_required(VERSION 3.20)

#  @file test/CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
#  @brief Tests for the vix_ai_nn module.
#
#  Minimal assert-based tests for the neural network module.
#  Each test is built as a small executable and registered with CTest.

add_executable(vix_ai_nn_test_layers
  layers_tests.cpp
)
target_link_libraries(vix_ai_nn_test_layers
  PRIVATE
    vix::ai::nn
)
target_compile_features(vix_ai_nn_test_layers PRIVATE cxx_std_20)
add_test(NAME nn_layers COMMAND vix_ai_nn_test_layers)
set_tests_properties(nn_layers PROPERTIES LABELS "nn;layers")

add_executable(vix_ai_nn_test_optimizers
  optimizers_tests.cpp
)
target_link_libraries(vix_ai_nn_test_optimizers
  PRIVATE
    vix::ai::nn
)
target_compile_features(vix_ai_nn_test_optimizers PRIVATE cxx_std_20)
add_test(NAME nn_optimizers COMMAND vix_ai_nn_test_optimizers)
set_tests_properties(nn_optimizers PROPERTIES LABELS "nn;optimizers")

add_executable(vix_ai_nn_test_network
  network_tests.cpp
)
target_link_libraries(vix_ai_nn_test_network
  PRIVATE
    vix::ai::nn
)
target_compile_features(vix_ai_nn_test_network PRIVATE cxx_std_20)
add_test(NAME nn_network COMMAND vix_ai_nn_test_network)
set_tests_properties(nn_network PROPERTIES LABELS "nn;network")
