/**
 *
 *  @file Dense.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.
 *  All rights reserved.
 *  https://github.com/vixcpp/vix
 *
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 */
#ifndef VIX_AI_NN_LAYERS_DENSE_HPP
#define VIX_AI_NN_LAYERS_DENSE_HPP

#include <cstddef>
namespace vix::ai::nn::layers
{
  class Dense
  {
  public:
    Dense(std::size_t in = 0, std::size_t out = 0) : in_(in), out_(out) {}
    std::size_t in_features() const { return in_; }
    std::size_t out_features() const { return out_; }

  private:
    std::size_t in_{};
    std::size_t out_{};
  };
} // namespace vix::ai::nn::layers

#endif
