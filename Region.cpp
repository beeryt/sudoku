#include "Region.h"
#include <bitset>

using std::vector;

Region::Region()
{

}

Region::Region(const std::vector<Cell_p> &_cells)
{
    cells = vector<Cell_p>(_cells.size());
    for (size_t i = 0; i < _cells.size(); ++i)
    {
        cells[i] = std::make_shared<Cell>(*_cells[i]);
    }
}

bool Region::isValid() const
{
    vector<bool> bitset(cells.size());

    for (auto idx = cells.begin(); idx != cells.end(); ++idx)
    {
        if (!idx->operator bool())
        {
            return false;
        }
        element value = (*idx)->value;
        if (bitset[value])
        {
            return false;
        }
        bitset[value] = true;
    }
    return true;
}
