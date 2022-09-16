#ifndef GL_WIDGET_H
#define GL_WIDGET_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QOpenGLBuffer>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget {
    Q_OBJECT

public:
    GLWidget(QMainWindow* parent = 0);
    ~GLWidget();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    QColor clearColor = QColor(229, 248, 255);
    QOpenGLShaderProgram *program = nullptr;
    QOpenGLBuffer vbo;
};

#endif
