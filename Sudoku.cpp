#include "Sudoku.h"
#include <QFile>
#include <QDir>
#include <cmath>

using namespace std;

Sudoku::Sudoku() : LatinSquare ()
{
    updateRegions();
}

Sudoku::Sudoku(std::vector<std::vector<Cell_p>> _cells) : LatinSquare (_cells)
{
    updateRegions();
}

void Sudoku::updateRegions()
{
    const size_t N = cells.size();
    const size_t n = 3; // TODO actually pass around sqrt (sudoku is n²x n², where N = n²)
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            vector<Cell_p> newRegion;
            for (size_t col = i*n; col < i*n + n; ++col)
            {
                for (size_t row = j*n; row < j*n + n; ++row)
                {
                    newRegion.push_back(make_shared<Cell>(*cells[row][col]));
                }
            }
            regions.push_back(newRegion);
        }
    }
}
