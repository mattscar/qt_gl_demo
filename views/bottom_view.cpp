#include "bottom_view.h"

#include "../main_window.h"

BottomView::BottomView(QMainWindow *p) : QTextEdit(p) {

    // Configure appearance
    parent = reinterpret_cast<MainWindow*>(p);
    setStyleSheet("background: rgb(220, 220, 220)");

    // Set font and text
    QFont font = currentFont();
    font.setPointSize(16);
    setFont(font);
    setText("   Qt-OpenGL Demonstration by Matthew Scarpino");
}

