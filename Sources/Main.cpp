#include <iostream>

#include "Grid.h"
#include "SaveLoad.h"
#include "Solve.h"

int main(int argc, char** argv)
  {
  std::string input_file_path("Sudoku.in"), output_file_path("Sudoku.out");

  try 
    {
    auto p_input_grid = Sudoku::Load(input_file_path);
    auto p_solved_grid = Sudoku::Solve(*p_input_grid);
    Sudoku::Save(*p_solved_grid, output_file_path);
    }
  catch (const std::exception& ex)
    {
    std::cerr << ex.what() << std::endl;
    return 1;
    }

  return 0;
  }
