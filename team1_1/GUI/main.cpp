#include "gui.h"

#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    GUI w;

    w.show();
    return a.exec();
}
