#include "main_window.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {

    // Set title
    setStyleSheet("QMainWindow { background: rgb(100, 64, 64);};");
    setWindowTitle("Qt OpenGL Demo - Spinning Triangles - by Matthew Scarpino");

    // Create editor
    glWidget = new GLWidget(this);
    setCentralWidget(glWidget);
    glWidget->show();

    // Create the bottom view
    bottomWidget = new QDockWidget(tr("bottom View"), this);
    bottomWidget->setTitleBarWidget(new QWidget(bottomWidget));
    bottomView = new BottomView(this);
    bottomWidget->setWidget(bottomView);
    bottomWidget->setMinimumHeight(175);
    addDockWidget(Qt::BottomDockWidgetArea, bottomWidget);

    // Create left view
    leftWidget = new QDockWidget(tr("Left View"), this);
    leftWidget->setTitleBarWidget(new QWidget(leftWidget));
    leftWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
    leftView = new LeftView(this);
    leftWidget->setWidget(leftView);
    leftWidget->setMinimumWidth(300);
    addDockWidget(Qt::LeftDockWidgetArea, leftWidget);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
}

MainWindow::~MainWindow() {}

