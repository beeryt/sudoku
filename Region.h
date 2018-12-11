#pragma once
#include <vector>
#include <array>
#include "Cell.h"


//class Constraint
//{

//};

class Region
{
    std::vector<Cell_p> cells;
//    Constraint c;
public:
    Region();
    Region(const std::vector<Cell_p> &_cells);
    bool isValid(void) const;

};
