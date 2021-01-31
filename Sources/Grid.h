#pragma once

#include <array>
#include <iostream>

namespace Sudoku
  {
  typedef std::array<std::array<int, 9>, 9> Grid;
  }

std::ostream& operator<<(std::ostream& os, const Sudoku::Grid& grid);
std::istream& operator>>(std::istream& os, Sudoku::Grid& grid);
bool operator!(const Sudoku::Grid& grid);
