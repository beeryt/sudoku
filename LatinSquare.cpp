#include "LatinSquare.h"
#include <QDebug>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::shared_ptr;

void LatinSquare::print()
{
    auto c = cells;
    for (auto row = c.begin(); row != c.end(); ++row)
    {
        auto out = qInfo();
        for (auto col = row->begin(); col != row->end(); ++col)
        {
            out << (*col)->value;
        }
    }
}

void LatinSquare::init(const size_t _n)
{
    cells = vector<vector<Cell_p>>(_n, vector<Cell_p>(_n, nullptr));
}

void LatinSquare::initRegions()
{
    const size_t _n = cells.size();
    for (size_t row = 0; row < _n; ++row)
    {
        vector<Cell_p> rowRegion;
        for (size_t col = 0; col < _n; ++col)
        {
            rowRegion.push_back(std::make_shared<Cell>(*cells[row][col]));
        }
        regions.push_back(Region(rowRegion));
    }

    for (size_t col = 0; col < _n; ++col)
    {
        vector<Cell_p> colRegion;
        for (size_t row = 0; row < _n; ++row)
        {
            colRegion.push_back(std::make_shared<Cell>(*cells[row][col]));
        }
        regions.push_back(Region(colRegion));
    }
}

LatinSquare::LatinSquare(const size_t _n)
{
    init(_n);
    initRegions();
}

LatinSquare::LatinSquare(vector<vector<Cell_p>> _cells)
{
    const size_t _n = _cells.size();
    for (size_t i = 0; i < _n; ++i)
    {
        if (_cells[i].size() != _n)
        {
            throw "bananas";
        }
    }

    init(_n);

    for (size_t i = 0; i < _n; ++i)
    {
        for (size_t j = 0; j < _n; ++j)
        {
            cells[i][j] = std::make_shared<Cell>(*_cells[i][j]);
        }
    }

    initRegions();
}

bool LatinSquare::isValid() const
{
    for (auto idx = regions.begin(); idx != regions.end(); ++idx)
    {
        if (!idx->isValid())
        {
            return false;
        }
    }
    return true;
}
