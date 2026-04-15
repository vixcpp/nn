/**
 *
 *  @file Transformer.hpp
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
#ifndef VIX_AI_NN_LAYERS_TRANSFORMER_HPP
#define VIX_AI_NN_LAYERS_TRANSFORMER_HPP

#include <cstddef>
namespace vix::ai::nn::layers
{
  class Transformer
  {
  public:
    explicit Transformer(std::size_t h = 8) : heads_(h) {}
    std::size_t heads() const { return heads_; }

  private:
    std::size_t heads_{};
  };
} // namespace vix::ai::nn::layers

#endif
