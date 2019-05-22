#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <scene.h>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Scene *scene = new Scene(this);
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
