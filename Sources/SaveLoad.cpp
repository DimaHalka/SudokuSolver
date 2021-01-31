#include "SaveLoad.h"

#include <fstream>
#include <sstream>

std::unique_ptr<Sudoku::Grid> Sudoku::Load(const std::string& file_path)
  {
  auto p_grid = std::make_unique<Sudoku::Grid>();
  std::ifstream ifs(file_path);
  if (!ifs.is_open())
    throw std::exception(("Cant open " + file_path).c_str());
  ifs >> *p_grid;
  return p_grid;
  }

void Sudoku::Save(const Sudoku::Grid& grid, const std::string& file_path)
  {
  std::ofstream ofstr(file_path.c_str());
  if (!ofstr.is_open())
    throw std::exception(("Cant open " + file_path).c_str());
  ofstr << grid;
  ofstr.close();
  }

