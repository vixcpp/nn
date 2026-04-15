/**
 *
 *  @file SGD.hpp
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
#ifndef VIX_AI_NN_OPTIMIZERS_SGD_HPP
#define VIX_AI_NN_OPTIMIZERS_SGD_HPP

namespace vix::ai::nn::opt
{
  class SGD
  {
  public:
    double lr() const { return 0.01; }
  };
} // namespace vix::ai::nn::opt

#endif
