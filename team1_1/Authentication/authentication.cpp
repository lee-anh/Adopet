#include "authentication.h"
#include <iostream>
#include <QString>

using namespace std;

Authentication::Authentication()
{
    openDB();
}

Authentication::~Authentication(){

}

bool Authentication::logIn(string username, string password){
    if(db.isOpen()){
        QSqlQuery qry = QSqlQuery();
        QString qs = "SELECT EXISTS(SELECT 1 FROM accounts WHERE username=";
        qs+= "\"" + QString::fromStdString(username) + "\"";
        qs += "AND password=";
        qs+= "\"" + QString::fromStdString(password)+"\"";
        qs+=");";
        qry.exec(qs);
        while(qry.next()){
            if (qry.value(0).toInt()==1) return true;
        }
    }
    return false;
}


void Authentication::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    string fullName = "../../projectDB.sqlite";
    db.setDatabaseName(QString::fromStdString(fullName));
    if(!db.open()){
        std::cerr << "Database does not open -- "
                  << db.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully\n";
    }
}
