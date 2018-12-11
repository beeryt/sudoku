#pragma once
#include <bitset>
#include <memory>

using element = unsigned int;

struct Cell
{
    bool isClue;
    element value;
    std::bitset<9> candidates;
};

using Cell_p = std::shared_ptr<Cell>;
