#include "gui.h"

#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../../../../../projectDB.sqlite");
    if(!database.open()){
        std::cerr << "Database does not open -- "
                  << database.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << "../../../../../projectDB.sqlite" << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully (from gui class)\n";
    }
    */

    GUI w;
    w.show();
    return a.exec();
}
