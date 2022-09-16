#ifndef BOTTOM_VIEW_H
#define BOTTOM_VIEW_H

#include <QMainWindow>
#include <QTextEdit>

QT_FORWARD_DECLARE_CLASS(MainWindow);

class BottomView : public QTextEdit {
    Q_OBJECT

public:
    BottomView(QMainWindow* parent = 0);

    int buttonDim;
    MainWindow* parent;
};

#endif // BOTTOM_VIEW_H
