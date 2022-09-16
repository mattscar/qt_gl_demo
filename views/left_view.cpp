#include "left_view.h"

#include <QDebug>

#include "../main_window.h"

LeftView::LeftView(QMainWindow *qw) {

    parent = reinterpret_cast<MainWindow*>(qw);

    // Set background color
    setStyleSheet("background: rgb(250, 250, 250)");
}
