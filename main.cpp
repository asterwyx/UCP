#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("UOS Editor");
    a.setOrganizationName("UOS");
    MainWindow w;
    w.show();
    return a.exec();
}
