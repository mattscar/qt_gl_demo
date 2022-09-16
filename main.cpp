#include "main_window.h"

#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    app.setOrganizationName("Matthew Scarpino");
    app.setApplicationName("Qt - OpenGL Demonstration by Matthew Scarpino");
    // QApplication::setWindowIcon(QIcon(":/images/bph_gui.ico"));

    // Create window
    MainWindow mainWindow;
    mainWindow.showMaximized();
    return app.exec();
}
