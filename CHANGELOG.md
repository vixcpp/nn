# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [Unreleased]

### Added
- Basic feedforward neural network support.
- Layers: Dense, Activation (ReLU, Sigmoid, Tanh).
- Loss functions: MSE, CrossEntropy.
- Optimizers: SGD, Adam.
- Integration with Vix AI Tensor for fast tensor-based computations.
- Unit tests for forward/backward propagation.

### Changed
- N/A

### Fixed
- N/A

---

## [0.1.0] - 2026-03-13

### Added
- Initial release of Vix AI NN library.
- Core classes:
  - `Layer` base class for building neural network layers.
  - `DenseLayer` for fully connected layers.
  - `ActivationLayer` for applying non-linear functions.
  - `NeuralNetwork` class for training and inference.
- Support for forward and backward propagation.
- CMake build system with options for tests, warnings, and installation.
- Example programs demonstrating training on small datasets.
- Fully compatible with Vix AI Tensor for computations.

### Changed
- N/A

### Fixed
- N/A
