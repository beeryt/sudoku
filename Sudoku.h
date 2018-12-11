#pragma once

#include <memory>
#include <vector>
#include <QDebug>
#include "LatinSquare.h"

class Sudoku : public LatinSquare
{
    int m_N = 9;
public:
    Sudoku();
    Sudoku(std::vector<std::vector<Cell_p>> _cells);

    int N() const { return m_N; }

private:
    void updateRegions();
};
