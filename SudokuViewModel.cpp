#include "SudokuViewModel.h"

using sudoku_ptr = std::shared_ptr<Sudoku>;
using namespace std;

SudokuViewModel::SudokuViewModel(sudoku_ptr _sudoku, QObject *parent)
    : QAbstractListModel(parent), m_Sudoku(_sudoku)
{

}


int SudokuViewModel::rowCount(const QModelIndex &) const
{
    return m_Sudoku->N() * m_Sudoku->N();
}

int SudokuViewModel::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant SudokuViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    int x = index.row() % m_Sudoku->N();
    int y = index.row() / m_Sudoku->N();

    switch (role)
    {
    case Qt::EditRole:
    case Qt::DisplayRole:
        return QString("%1").arg((*m_Sudoku)[x][y]->value);
    case Qt::DecorationRole:
        return QString("steelblue");
    default:
        return QVariant();
    }
}

bool SudokuViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        bool result;
        (*m_Sudoku)[index.row()][index.column()]->value = value.toInt(&result);
        emit dataChanged(index, index);
        return result;
    }
    return false;
}

Qt::ItemFlags SudokuViewModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }

    return QAbstractItemModel::flags(index) | Qt::ItemIsSelectable;
}
