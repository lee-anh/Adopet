#include "savedlist.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SavedList::SavedList()
{
    username = "default User";
    dbName =  "../../projectDB.sqlite";
   // openDB();
   // loadList();
    cout << "default constructor called" <<endl;
}

SavedList::SavedList(string username){
    this->username = username;
    dbName = "../../projectDB.sqlite";
    cout << "other constructor called" << endl;
    openDB();
    loadList();
}

SavedList::SavedList(string databaseFilePath, string username){
    this->username = username;
    dbName = databaseFilePath;
    openDB();
    loadList();
}

SavedList::SavedList(QSqlDatabase d){
    dbSL = d;
    loadList();
}

SavedList::~SavedList(){
    savedPets.clear();
    closeDB();

}

void SavedList::savePet(Pet p){
    //push to vector
    Pet temp = p;
    savedPets.push_back(temp);

    //call helper method
    savePet(temp.getID());
}


void SavedList::savePet(int petID){

    QString qry = "INSERT INTO savedPets(username, petID) VALUES(\"";
    qry+= QString::fromStdString(username) + "\", ";
    qry+= QString::number(petID) + ")";
    if(dbSL.open()){
        QSqlQuery query = QSqlQuery(dbSL);
        query.exec(qry);
    }
    cout << qry.toStdString() << endl;

}

void SavedList::unsavePet(Pet p){
    //remove from vector
    for(int i = 0; i < (int) savedPets.size(); i++){
        if(p.getID() == savedPets[i].getID()){
            savedPets.erase(savedPets.begin() + i);
            break;
        }
    }
    //call helper method
    unsavePet(p.getID());

}

void SavedList::unsavePet(int petID){

    QString qry = "DELETE FROM savedPets WHERE username = \"" +
            QString::fromStdString(username) + "\" AND petID = " +
            QString::number(petID);

    if(dbSL.open()){
        QSqlQuery query = QSqlQuery(dbSL);
        query.exec(qry);

    }
    //cout << qry.toStdString() << endl;


}

void SavedList::loadList(){

    savedPets.clear();
    if(dbSL.open()){
        QString qry = "SELECT petID FROM savedPets WHERE username = \"" +
                QString::fromStdString(username) + "\"";

        //cout << qry.toStdString() << endl;
        QSqlQuery query = QSqlQuery(dbSL);
        QSqlQuery queryPets = QSqlQuery(dbSL);

        query.exec(qry);

        while(query.next()){

            string qry2StdString = "SELECT id, name, species, breed, age, "
                     "size, temperament, gender, goodWith, shelter,"
                     "bio FROM pets WHERE id = "
                     + query.value(0).toString().toStdString();
            //cout << qry2StdString << endl;
            QString qry2 = QString::fromStdString(qry2StdString);
            queryPets.exec(qry2);
            while (queryPets.next()){
                int id = queryPets.value(0).toInt();
                string name = queryPets.value(1).toString().toStdString();
                string species = queryPets.value(2).toString().toStdString();
                string breed = queryPets.value(3).toString().toStdString();
                string age = queryPets.value(4).toString().toStdString();
                string size = queryPets.value(5).toString().toStdString();
                string temperament = queryPets.value(6).toString().toStdString();
                string gender = queryPets.value(7).toString().toStdString();
                string goodWith = queryPets.value(8).toString().toStdString();
                string shelter = queryPets.value(9).toString().toStdString();
                string bio = queryPets.value(10).toString().toStdString();
                Pet p = Pet(id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);

                savedPets.push_back(p);
            }
        }
    }
}

void SavedList::setUsername(string username){
    this->username = username;
}



void SavedList::openDB(){
    dbSL = QSqlDatabase::addDatabase("QSQLITE", "savedListsCxn");
    string fullName = dbName;
    dbSL.setDatabaseName(QString::fromStdString(fullName));
    if(!dbSL.open()){
        std::cerr << "Database does not open -- "
                  << dbSL.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully (from SavedList class)\n";
    }
}

void SavedList::closeDB(){
    dbSL.close();
}

vector<Pet> SavedList::getPetVec(){
    return savedPets;
}

void SavedList::printVec(){
    for(int i = 0; i < (int) savedPets.size(); i++){
        cout << savedPets[i].getName() << endl;
    }
}

bool SavedList::isSavedPet(Pet p){
    for(int i = 0; i < (int) savedPets.size(); i++){
        if(savedPets[i].getID() == p.getID()){
            return true;
            }
    }
    return false;
}
