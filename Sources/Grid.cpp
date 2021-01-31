#include "Grid.h"

#include <sstream>

std::ostream& operator<<(std::ostream& os, const Sudoku::Grid& grid)
  {
  for (auto i = 0U; i < 9; i++)
    {
    for (auto j = 0U; j < 9; j++)
      {
      os << (grid[i][j] == 0 ? "." : std::to_string(grid[i][j])) << " ";
      }
    os << std::endl;
    }

  return os;
  }

std::istream& operator>>(std::istream& is, Sudoku::Grid& grid)
  {
  for (auto i = 0U; i < 9; i++)
    {
    std::string str;
    std::getline(is, str);
    std::stringstream ss(str);
    for (auto j = 0U; j < 9; j++)
      {
      ss >> str;
      grid[i][j] = str == "." ? 0 : std::stoi(str);
      }
    }

  return is;
  }

bool operator!(const Sudoku::Grid& grid)
  {
  for (auto i = 0U; i < 9; i++)
    {
    for (auto j = 0U; j < 9; j++)
      {
      if (grid[i][j] == 0)
        return true;
      }
    }
  return false;
  }
