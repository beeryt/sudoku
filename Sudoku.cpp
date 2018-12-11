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

std::unique_ptr<Sudoku> Sudoku::loadFile(QString filename)
{
    QFile file(filename);

    if (!file.exists())
    {
        qCritical() << "File" << QDir::currentPath() + file.fileName() << "does not exist!";
        return nullptr;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return nullptr;
    }

    // TODO retrieve meta data such as N and shape of board
    size_t N = 9;

    vector<vector<Cell_p>> cells(N, vector<Cell_p>(N, nullptr));
    size_t i = 0;
    size_t j = 0;

    QTextStream in(&file);
    while (!in.atEnd())
    {
        for (i = 0; i < N; ++i)
        {
            char c;
            in >> c;
            cells[i][j] = std::unique_ptr<Cell>(new Cell);
            cells[i][j]->value = element(QString(c).toInt());
        }
        ++j;
    }

    return unique_ptr<Sudoku>(new Sudoku(cells));
}
