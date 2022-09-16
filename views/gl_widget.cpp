#include "gl_widget.h"

// This is the center view
GLWidget::GLWidget(QMainWindow *parent) : QOpenGLWidget(parent) {

    // Set background color
    setStyleSheet("background: rgb(32, 32, 32)");
}

GLWidget::~GLWidget() {
    vbo.destroy();
    delete program;
}

void GLWidget::initializeGL() {

    // Initialize VBO
    static const float vertexData[] = {
        -0.25f, 0.0f, 1.0f, 0.0f, 0.0f,   // First vertex
         0.0f, 0.25f, 0.0f, 1.0f, 0.0f,   // Second vertex
         0.25f, 0.0f, 0.0f, 0.0f, 1.0f};  // Third vertex

    vbo.create();
    vbo.bind();
    vbo.allocate(vertexData, 15 * sizeof(GLfloat));

    // Configure viewing properties
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // Create and configure program
    program = new QOpenGLShaderProgram();
    program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/triangle.vert");
    program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/triangle.frag");
    program->bindAttributeLocation("in_coords", 0);
    program->bindAttributeLocation("in_color", 1);
    program->link();
    program->bind();
}

void GLWidget::paintGL() {

    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    glClearColor(clearColor.redF(), clearColor.greenF(), clearColor.blueF(), clearColor.alphaF());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Enable attributes
    program->enableAttributeArray(0);
    program->enableAttributeArray(1);
    program->setAttributeBuffer(0, GL_FLOAT, 0, 2, 5 * sizeof(GLfloat));
    program->setAttributeBuffer(1, GL_FLOAT, 2 * sizeof(GLfloat), 3, 5 * sizeof(GLfloat));

    // Draw arrays
    f->glDrawArraysInstanced(GL_LINE_LOOP, 0, 3, 4);
}

void GLWidget::resizeGL(int width, int height) {
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
}
