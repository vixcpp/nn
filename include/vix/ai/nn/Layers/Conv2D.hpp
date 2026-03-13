/**
 * @file Conv2D.hpp
 * @author Gaspard Kirira
 *
 * Copyright 2025, Gaspard Kirira. All rights reserved.
 * https://github.com/vixcpp/vix
 * Use of this source code is governed by a MIT license that can be found in the License file.
 *
 * Vix.cpp
 */
#ifndef VIX_AI_NN_LAYERS_CONV2D_HPP
#define VIX_AI_NN_LAYERS_CONV2D_HPP

#include <cstddef>
namespace vix::ai::nn::layers
{
  class Conv2D
  {
  public:
    explicit Conv2D(std::size_t k = 3) : k_(k) {}
    std::size_t kernel() const { return k_; }

  private:
    std::size_t k_{};
  };
} // namespace vix::ai::nn::layers

#endif
