#include "MainWindow.h"
#include <QMenu>
#include <QAction>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // configuring the main window
    setWindowTitle("File manager");
    resize(800, 600);

    //creating ui components
    createMenus();
    createToolbars();
    createStatusBar();
    setupFileView();
}

MainWindow::~MainWindow() {
    // clearing some info, in the future
}

void MainWindow::createMenus() {
    // creating menu
    QMenu *fileMenu = menuBar()->addMenu("&File");

    // opening directory action
    QAction *openDirAction = new QAction("&Open Directory", this);
    fileMenu->addAction(openDirAction);

    // connecting signal choosing an action with handler
    connect(openDirAction, &QAction::triggered, this, [this]() {
        QString dirPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"));
        if (!dirPath.isEmpty()) {
            fileSystemModel->setRootPath(dirPath);
            fileView->setRootIndex(fileSystemModel->index(dirPath));
            statusBar()->showMessage("Opened: " + dirPath);
        }
    });

    // adding separator
    fileMenu->addSeparator();

    // exit action
    QAction *exitAction = new QAction("E&xit", this);
    fileMenu->addAction(exitAction);
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    // Creating help menu
    QMenu *helpMenu = menuBar()->addMenu("&Help");

    // action "about the app"
    QAction *aboutAction = new QAction("&About", this);
    helpMenu->addAction(aboutAction);
    connect(aboutAction, &QAction::triggered, this, [this]() {
        QMessageBox::about(this, "About File Manager", "Simple File Manager\nVersion 0.1\nCreated with Qt and C++");
    });
}

void MainWindow::createToolbars() {
    // creating tool bar
    fileToolBar = new QToolBar("file");

    // adding new directory button
    QAction *openDirAction = new QAction("Open Directory", this);
    fileToolBar->addAction(openDirAction);

    // connecting signal
    connect(openDirAction, &QAction::triggered, this, [this]() {
        QString dirPath = QFileDialog::getExistingDirectory(this, "Open Directory");
        if (!dirPath.isEmpty()) {
            fileSystemModel->setRootPath(dirPath);
            fileView->setRootIndex(fileSystemModel->index(dirPath));
            statusBar()->showMessage("Opened: " + dirPath);
        }
    });
}

void MainWindow::createStatusBar() {
    // creating status bar
    mainStatusBar = new QStatusBar(this);
    setStatusBar(mainStatusBar);
    mainStatusBar->showMessage("Ready");
}

void MainWindow::setupFileView() {
    // creating file system model
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    fileSystemModel->setRootPath(QDir::homePath());

    // creating file view
    fileView = new QTreeView(this);
    fileView->setModel(fileSystemModel);
    fileView->setRootIndex(fileSystemModel->index(QDir::homePath()));

    // setting up columns of file view
    fileView->setColumnWidth(0, 250);
    fileView->setSortingEnabled(true);

    // setting as the main widget
    setCentralWidget(fileView);
}