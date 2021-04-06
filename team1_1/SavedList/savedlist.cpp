#include "savedlist.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SavedList::SavedList()
{
    username = "exampleUser";
    openDB();
}

SavedList::SavedList(string username){
    this->username = username;
    openDB();
}

SavedList::~SavedList(){
    savedPets.clear();
}

void SavedList::savePet(Pet* p){
    Pet newPet = Pet(p->getName(), p->getSpecies(), p->getBreed(),p->getAge(),p->getGender(), p->getSize(),
                     p->getTemperament(), p->getGoodWith(), p->getShelter(), p->getBio());
    savedPets.push_back(newPet);
    newPet.setPetID(p->getPetID());
    QString qry = "INSERT INTO savedPets(username, petID) VALUES( ";
    qry+= QString::fromStdString(username) + ", ";
    qry+= QString::number(newPet.getPetID()) + ");";
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        query.exec(qry);
    }
}

void SavedList::savePet(int petID){
    QString qry = "INSERT INTO savedPets(username, petID) VALUES( ";
    qry+= QString::fromStdString(username) + ", ";
    qry+= QString::number(petID) + ");";
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        query.exec(qry);
    }
}

void SavedList::loadList(){
    savedPets.clear();
    if(db.open()){
        QString qry = "SELECT petID FROM savedPets WHERE username=";
        qry += QString::fromStdString(username);
        qry+=";";
        QSqlQuery query = QSqlQuery();
        QSqlQuery queryPets = QSqlQuery();
        query.exec(qry);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            qry = "SELECT * FROM pets WHERE id=";
            qry += QString::fromStdString(s) + ";";
            queryPets.exec(qry);
            while (queryPets.next()){
                //Have to change the constructor
                Pet* newPet = new Pet();
                savedPets.push_back(*newPet);
            }
        }
    }
}

void SavedList::setUsername(string username){
    this->username = username;
}

void SavedList::openDB(){
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
