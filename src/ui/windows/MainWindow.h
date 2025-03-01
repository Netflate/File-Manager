#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QFileSystemModel>
#include <QTreeView>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // CREATING NEW UI ELEMENTS
    void createMenus();
    void createToolbars();
    void createStatusBar();
    void setupFileView();

    // UI ELEMENTS
    QMenuBar *mainMenuBar;
    QToolBar *fileToolBar;
    QStatusBar *mainStatusBar;

    // FILE MODEL AND VIEW
    QFileSystemModel *fileSystemModel;
    QTreeView *fileView;
};

#endif // MAINWINDOW_H