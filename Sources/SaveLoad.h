#pragma once

#include "Grid.h"

#include <string>
#include <memory>

namespace Sudoku
  {
  std::unique_ptr<Grid> Load(const std::string& file_path);
  void Save(const Sudoku::Grid& grid, const std::string& file_path);
  }