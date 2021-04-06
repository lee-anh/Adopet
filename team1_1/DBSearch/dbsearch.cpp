#include "dbsearch.h"

DBSearch::DBSearch()
{
    filepath = "../../projectDB.sqlite";

    //Databse stuff
    openDB();

    //load keyword vectors
    fillStaticVecs();
    fillVecsFromDB();





}

DBSearch::DBSearch(string dbFilepath){
    filepath = dbFilepath;
    //Databse stuff
    openDB();

    //load keyword vectors
    fillStaticVecs();
    fillVecsFromDB();

}
DBSearch::~DBSearch()
{

    db.~QSqlDatabase();
}

void DBSearch::search(string s){
    matchingPets.clear();

    //lowercase the input
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int count = 0;
    string attributeToSearch = "";

    //how to prevent iterating over everything? it's a little repetitive rn
    for(int i = 0; i < (int) mainSpecies.size(); i++){
        if(s == mainSpecies.at(i)){
            attributeToSearch = "species";
            break;
        }
    }

    //breed
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainBreeds.size(); i++){
            if(s == mainBreeds.at(i)){
                attributeToSearch = "breed";
                break;
            }
        }
    }

    //age
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainAges.size(); i++){
            if(s == mainAges.at(i)){
                attributeToSearch = "age";
                break;
            }
        }
    }

    //size
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainSizes.size(); i++){
            if(s == mainSizes.at(i)){
                attributeToSearch = "size";
                break;
            }
        }
    }

    //temperament
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainTemperaments.size(); i++){
            if(s == mainTemperaments.at(i)){
                attributeToSearch = "temperament";
                break;
            }
        }
    }

    //gender
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainGenders.size(); i++){
            if(s == mainGenders.at(i)){
                attributeToSearch = "gender";
                break;
            }
        }
    }

    //goodWith
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainGoodWith.size(); i++){
            if(s == mainGoodWith.at(i)){
                attributeToSearch = "goodWith";
                break;
            }
        }
    }


     //Shelters
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainShelters.size(); i++){
            if(s == mainShelters.at(i)){
                attributeToSearch = "shelter";
                break;
            }
        }
    }


    if(attributeToSearch == ""){
       // count = generalQueryDB(s);//general query
    } else {
        count = queryDB(s, attributeToSearch);
    }

    if(count == 0){
        cout << "No animals match your search" << endl;
    }





}


int DBSearch::queryDB(string s, string attribute){
    int count = 0;
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString qAttribute = QString::fromStdString(attribute);
       // QString qs = "SELECT id, " + qAttribute + " FROM pets WHERE " +
       //         qAttribute + " LIKE '%" + QString::fromStdString(s) + "%'";
        QString qs = "SELECT " + qAttribute +
                ", id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio FROM pets";
        query.exec(qs);
        while(query.next()){
            string petAttribute = query.value(0).toString().toStdString();
            int id = query.value(1).toInt();
            string name = query.value(2).toString().toStdString();
            string species = query.value(3).toString().toStdString();
            string breed = query.value(4).toString().toStdString();
            string age = query.value(5).toString().toStdString();
            string size = query.value(6).toString().toStdString();
            string temperament = query.value(7).toString().toStdString();
            string gender = query.value(8).toString().toStdString();
            string goodWith = query.value(9).toString().toStdString();
            string shelter = query.value(10).toString().toStdString();
            string bio = query.value(11).toString().toStdString();


           // cout << "ID: " << id << endl; //%male% female problem
            //count++;
            if(s == petAttribute){
                count++;
                Pet p = Pet(id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
                matchingPets.push_back(p);
            }
        }
        cout << "Showing " << count << " results" << endl;
    } else {
        return -1; // -1 will indicate that the database couldn't open
    }

    return count;
}

vector<Pet> DBSearch::getPetVec(){
    return matchingPets;
}

int DBSearch::getPetVecSize(){
    return (int) matchingPets.size();
}



void DBSearch::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    string fullName = filepath;
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

void DBSearch::fillVecsFromDB(){
    if(db.open()){
    QSqlQuery query = QSqlQuery();

    //species
    QString qs = "SELECT speciesType FROM species";
    query.exec(qs);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainSpecies.push_back(s);
    }

    //breed
    QString qs2 = "SELECT breedType FROM breed";
    query.exec(qs2);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainBreeds.push_back(s);
    }

    //temperament
    QString qs3 = "SELECT temperamentType FROM temperament";
    query.exec(qs3);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainTemperaments.push_back(s);
    }


    //goodWith
    QString qs4 = "SELECT goodWithType FROM goodWith";
    query.exec(qs4);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainGoodWith.push_back(s);
    }


    //shelter
    QString qs5 = "SELECT shelterType FROM shelter";
    query.exec(qs5);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainShelters.push_back(s);
    }

    }
}

void DBSearch::fillStaticVecs(){
    mainAges = {"young", "adult","senior"};
    mainGenders = {"male", "female"};
    mainSizes = {"small", "medium", "large"};
    matchingPets = vector<Pet>();
}

void DBSearch::printMatchingVec(){
    for(int i = 0; i < (int) matchingPets.size(); i++){
        cout << matchingPets.at(i).getName() << endl;
    }
}
