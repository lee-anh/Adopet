#include "authentication.h"
#include <iostream>
#include <QString>

using namespace std;

Authentication::Authentication()
{
    authAdopter = nullptr;
    openDB();
}

Authentication::~Authentication(){
    delete authAdopter;
    db.close();
}

bool Authentication::logIn(string username, string password){
    if(db.isOpen()){
        QSqlQuery qry = QSqlQuery(db);
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

bool Authentication::checkUsername(string username){
    if(db.isOpen()){
        QSqlQuery qry = QSqlQuery(db);
        QString qs = "SELECT EXISTS(SELECT 1 FROM accounts WHERE username=";
        qs+= "\"" + QString::fromStdString(username) + "\"";
        qs+=");";
        qry.exec(qs);
        while(qry.next()){
            if (qry.value(0).toInt()==1) return true;
        }
    }
    return false;
}


void Authentication::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE","authConnection");
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

int Authentication::signUp(string username, string password, string emailAdd, int zip, string accountType){
    if(checkUsername("username")){
        std::cerr << "Account already exists" << endl;
        return -1;
    }
    if(accountType.compare("Adopter")){
        createAdopter(username,password, emailAdd, zip);
        std::cerr << "New Adopter Created" << endl;
        return 1;
    }
    else{
        std::cerr << "Invalid sign up. Return code -1" << endl;
        return -1;
    }
}

Adopter* Authentication::createAdopter(string username, string password, string emailAdd, int zip){
    Preferences* pref = new Preferences();
    //Big problem: find a way to add first and last name
    Adopter* newAdptr = new Adopter(username, password, "", "",emailAdd, zip, *pref);
    //Add to accounts
    if(db.isOpen()){
        QSqlQuery qry = QSqlQuery(db);
        QString qs = "INSERT INTO accounts(username, password, accountType) VALUES(";
        qs+= "\"" + QString::fromStdString(username) + "\"";
        qs += ",";
        qs+= "\"" + QString::fromStdString(password)+"\"";
        qs += ",";
        qs+= "\"";
        qs+= "adopter";
        qs+= "\"";
        qs+=");";
        qry.exec(qs);
    }
    //Add to adopters
    if(db.isOpen()){
        QSqlQuery qry = QSqlQuery(db);
        QString qs = "INSERT INTO adopter(username, firstname, lastname, emailAddress, zip) VALUES(";
        qs+= "\"" + QString::fromStdString(username) + "\"";
        qs += ",";
        //fname
        qs+= "\"";
        qs+= "";
        qs+= "\"";
        qs += ",";
        //lname
        qs+= "\"";
        qs+= "";
        qs+= "\"";
        qs += ",";
        //
        qs+= "\"";
        qs+= QString::fromStdString(emailAdd);
        qs+= "\"";
        qs += ",";
        //
        qs+= "\"";
        qs+= QString::number(zip);
        qs+= "\"";
        //
        qs+=");";
        qry.exec(qs);
    }
    authAdopter = newAdptr;
    return newAdptr;
}

Adopter* Authentication::getAuthenticatedAdopter(){
    if(authAdopter){
        return authAdopter;
    }
    cerr << "No authenticated adopter" << endl;
    return nullptr;
}
