#pragma once
#include <memory>
#include <vector>
#include "Region.h"

class LatinSquare
{
protected:
    std::vector<std::vector<Cell_p>> cells;
    std::vector<Region> regions;
public:
    LatinSquare(const size_t _n = 9);
    LatinSquare(std::vector<std::vector<Cell_p>> _cells);
    bool isValid(void) const;

    void print();

          std::vector<Cell_p>& operator[](std::size_t idx)       { return cells[idx]; }
    const std::vector<Cell_p>& operator[](std::size_t idx) const { return cells[idx]; }

protected:
    void init(const size_t _n);
    void initRegions();
};

