#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include "ui/models/FileSystemModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setOrganizationName("YourOrganization");
    app.setApplicationName("FileManager");

    QQmlApplicationEngine engine;

    // Set the import paths explicitly
    engine.addImportPath("qrc:/");

    // Optional: Print all import paths for debugging
    qDebug() << "QML import paths:" << engine.importPathList();

    qmlRegisterType<FileSystemModel>("FileManager", 1, 0, "FileSystemModel");
    FileSystemModel *fileSystemModel = new FileSystemModel();
    engine.rootContext()->setContextProperty("fileSystemModel", fileSystemModel);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}