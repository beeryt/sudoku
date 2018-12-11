#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QDebug>

#include "Sudoku.h"
#include "SudokuViewModel.h"

using namespace std;

int main(int argc, char *argv[])
{

    shared_ptr<Sudoku> sudoku = new Sudoku();
    if (!sudoku)
    {
        qCritical("File failed to load");
        return 1;
    }
    SudokuViewModel sudokuViewModel(sudoku);

    qInfo() << "Sudoku is trivially copyable:" << std::is_trivially_copyable<Sudoku>::value;
    qInfo() << "Sudoku is valid:" << sudoku->isValid();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("SudokuViewModel", &sudokuViewModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
