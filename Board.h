#pragma once

#include <array>

#define MAX_COL 9
#define MAX_ROW 9

class Board
{
public:
    Board();
    unsigned int n(void) const { return m_N; };

    void clear(void);
    int get(unsigned int x, unsigned int y) const;
    int set(unsigned int x, unsigned int y, int e);

    bool isValid(void) const;
    bool isFull(void) const;

private:
    bool checkHorizontal(unsigned int x, unsigned int y, int e) const;
    bool checkVertical(unsigned int x, unsigned int y, int e) const;
    bool checkBlock(unsigned int x, unsigned int y, int e) const;
    bool isValidHorizontal(void) const;
    bool isValidVertical(void) const;
    bool isValidBlock(void) const;

    unsigned int m_N = 9;
    std::array<std::array<int, 9>, 9> m_Board;
};
