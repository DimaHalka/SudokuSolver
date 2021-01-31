#include "Solve.h"

#include <algorithm>
#include <vector>


namespace
  {
  std::vector<int> _CurrentRow(const Sudoku::Grid& grid, int row_idx)
    {
    std::vector<int> row;
    row.reserve(9);
    for (auto i = 0U; i < 9; i++)
      if (grid[row_idx][i] != 0)
        row.emplace_back(grid[row_idx][i]);
    std::sort(row.begin(), row.end());
    return row;
    }

  std::vector<int> _CurrentColumn(const Sudoku::Grid& grid, int column_idx)
    {
    std::vector<int> column;
    column.reserve(9);
    for (auto i = 0U; i < 9; i++)
      if (grid[i][column_idx] != 0)
        column.emplace_back(grid[i][column_idx]);
    std::sort(column.begin(), column.end());
    return column;
    }

  std::vector<int> _CurrentFraction(const Sudoku::Grid& grid, int row_idx, int column_idx)
    {
    std::vector<int> fraction;
    fraction.reserve(9);
    for (unsigned i = (row_idx / 3) * 3; i < (row_idx / 3) * 3 + 3; i++)
      for (unsigned j = (column_idx / 3) * 3; j < (column_idx / 3) * 3 + 3; j++)
        if (grid[i][j] != 0)
          fraction.emplace_back(grid[i][j]);
    std::sort(fraction.begin(), fraction.end());
    return fraction;
    }
  }


std::unique_ptr<Sudoku::Grid> Sudoku::Solve(const Sudoku::Grid& input_grid)
  {
  auto p_grid = std::make_unique<Sudoku::Grid>(input_grid);
  auto& grid = *p_grid;

  std::vector<int> full_set({1,2,3,4,5,6,7,8,9});

  auto iteration = 0U;

  while (!grid)
    {
    for (auto i = 0U; i < 9; i++)
      {
      for (auto j = 0U; j < 9; j++)
        {
        if (grid[i][j] != 0)
          continue;

        std::vector<int> current_row = _CurrentRow(grid, i);
        std::vector<int> current_column = _CurrentColumn(grid, j);
        std::vector<int> current_fraction = _CurrentFraction(grid, i, j);

        std::vector<int> candidates_row;
        std::set_difference(full_set.begin(), full_set.end(), current_row.begin(), current_row.end(), std::back_inserter(candidates_row));
        if (candidates_row.size() == 1) 
          {
          grid[i][j] = candidates_row[0];
          continue;
          }

        std::vector<int> candidates_column;
        std::set_difference(full_set.begin(), full_set.end(), current_column.begin(), current_column.end(), std::back_inserter(candidates_column));
        if (candidates_column.size() == 1)
          {
          grid[i][j] = candidates_column[0];
          continue;
          }

        std::vector<int> candidates_fraction;
        std::set_difference(full_set.begin(), full_set.end(), current_fraction.begin(), current_fraction.end(), std::back_inserter(candidates_fraction));
        if (candidates_fraction.size() == 1)
          {
          grid[i][j] = candidates_fraction[0];
          continue;
          }

        std::vector<int> i1; // row U column 
        std::set_intersection(candidates_row.begin(), candidates_row.end(), candidates_column.begin(), candidates_column.end(), std::back_inserter(i1));
        std::vector<int> candidates; // row U column U fraction 
        std::set_intersection(i1.begin(), i1.end(), candidates_fraction.begin(), candidates_fraction.end(), std::back_inserter(candidates));

        if (candidates.size() == 1)
          grid[i][j] = candidates[0];
        }
      }

    std::cout << "Iteration " << ++iteration << std::endl;
    std::cout << grid << std::endl;
    }

  return p_grid;
  }
