rd /s /q CMakeFiles
rd /s /q Debug
rd /s /q SudokuSolver.dir
rd /s /q x64
rd /s /q .\.vs

attrib +r Clean.cmd
attrib +r CMake.cmd
attrib +r Sudoku.in
del /q *.*
attrib -r Clean.cmd
attrib -r CMake.cmd
attrib -r Sudoku.in