#include "Board.h"
#include <QDebug>

Board::Board()
{
    for (size_t i = 0; i < m_Board.size(); ++i)
    {
        m_Board[i].fill(0);
    }
}

/*!
 * Checks if all board positions are valid
 */
bool Board::isValid(void) const
{
    return (isValidHorizontal() && isValidVertical() && isValidBlock());
}

/*!
 * Checks the horizontal row of position for given element
 */
bool Board::checkHorizontal(unsigned int x, unsigned int y, int e) const
{
    if (x > n() || y > n())
    {
        qFatal("Indices are out of bounds");
    }

    bool valid = (m_Board[x][y] == 0);                  // initially valid if position is empty

    for (unsigned int i = 0; valid && i < n(); ++i)     // will break on !valid
    {
        valid = (m_Board[i][y] != e);                   // valid as long as e is not in the row
    }

    return valid;
}

/*!
 * Checks the vertical column of position for given element
 */
bool Board::checkVertical(unsigned int x, unsigned int y, int e) const
{
    if (x > n() || y > n())
    {
        qFatal("Indices are out of bounds");
    }

    bool valid = (m_Board[x][y] == 0);                  // initially valid if position is empty

    for (unsigned int j = 0; valid && j < n(); ++j)     // will break on !valid
    {
        valid = (m_Board[x][j] != e);                   // valid as long as e is not in the col
    }

    return valid;
}

/*!
 * Checks the local block of position for the given element
 */
bool Board::checkBlock(unsigned int x, unsigned int y, int e) const
{
    if (x > n() || y > n())
    {
        qFatal("Indices are out of bounds");
    }

    bool valid = (m_Board[x][y] == 0);                  // initially valid if position is empty

    unsigned int startX = x - (x % 3);                  // starting coordinates of the block
    unsigned int startY = y - (y % 3);

    for (unsigned int i = startY; valid && (i % 3 != 0 || i == startY); ++i)
    {
        for (unsigned int j = startX; valid && (j % 3 != 0 || j == startX); ++j)
        {
            valid = (m_Board[j][i] != e);               // valid as long as e is not in the block
        }
    }

    return valid;
}

/*!
 * Checks if all horizontal rows of the board are valid
 */
bool Board::isValidHorizontal(void) const
{
    std::array<bool,10> elementOccured;
    bool valid = true;

    for (unsigned int i = 0; valid && i < n(); ++i)
    {
        elementOccured.fill(false);                     // Initialize the boolean array
        for (unsigned int j = 0; valid && j < n(); ++j)
        {
            unsigned int cur = m_Board[j][i];
            valid = !elementOccured[cur];               // valid if element has yet to occur
            elementOccured[cur] = (cur != 0);           // element has occured if position is not blank
        }
    }

    return valid;
}

/*!
 * Checks if all vertical columns of the board are valid
 */
bool Board::isValidVertical(void) const
{
    std::array<bool,10> elementOccured;
    bool valid = true;

    for (unsigned int i = 0; valid && i < n(); ++i)
    {
        elementOccured.fill(false);
        for (unsigned int j = 0; valid && j < n(); ++j)
        {
            unsigned int cur = m_Board[i][j];
            valid = !elementOccured[cur];
            elementOccured[cur] = (cur != 0);
        }
    }

    return valid;
}

/*!
 * Checks if all blocks of the board are valid
 */
bool Board::isValidBlock(void) const
{
    std::array<bool,10> elementOccured;
    bool valid = true;

    for (unsigned int startX = 0; valid && startX < n(); startX += 3)
    {
        for (unsigned int startY = 0; valid && startY < n(); startY += 3)
        {
            elementOccured.fill(false);
            for (unsigned int i = startX; valid && (i % 3 != 0 || i == startX); ++i)
            {
                for (unsigned int j = startY; valid && (j % 3 != 0 || j == startY); ++j)
                {
                    unsigned int cur = m_Board[j][i];
                    valid = !elementOccured[cur];
                    elementOccured[cur] = (cur != 0);
                }
            }
        }
    }

    return valid;
}
