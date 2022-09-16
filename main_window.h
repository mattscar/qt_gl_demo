#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDockWidget>
#include <QMainWindow>

// Display GUI views
#include "views/gl_widget.h"
#include "views/left_view.h"
#include "views/bottom_view.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Main widgets
    GLWidget* glWidget;
    LeftView* leftView;
    BottomView* bottomView;

    // Member variables
    QDockWidget *leftWidget, *bottomWidget;
};
#endif // MAINWINDOW_H
