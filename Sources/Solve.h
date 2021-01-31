#pragma once

#include "Grid.h"
#include <memory>

namespace Sudoku
  {
  std::unique_ptr<Sudoku::Grid> Solve(const Sudoku::Grid& input_grid);
  }