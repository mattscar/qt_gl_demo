#ifndef LEFT_VIEW_H
#define LEFT_VIEW_H

#include <QMainWindow>
#include <QTreeView>
#include <QWidget>

QT_FORWARD_DECLARE_CLASS(MainWindow);

class LeftView : public QTreeView {
    Q_OBJECT

public:
    LeftView(QMainWindow* parent = 0);
    MainWindow* parent;
};

#endif // LEFT_VIEW_H
