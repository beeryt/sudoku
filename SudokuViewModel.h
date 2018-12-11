#pragma once
#include <memory>
#include <QAbstractListModel>
#include "Sudoku.h"

class SudokuViewModel : public QAbstractListModel
{
    std::shared_ptr<Sudoku> m_Sudoku;
public:
    SudokuViewModel(std::shared_ptr<Sudoku> _sudoku, QObject *parent = nullptr);

    // QAbstractListModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

};
