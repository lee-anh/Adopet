#include "dbsearch.h"

DBSearch::DBSearch()
{

    //keywords
    //read in from database
    mainSpecies = {"dog", "cat", "rabbit", "rodent", "fish", "bird"};
    mainBreeds = {"sporting", "hound", "working", "terrier", "toy", "non-sporting", "herding",
                 "siamese", "persian", "maine coon", "ragdoll",
                 "hamster", "guinea pig", "gerbil", "mouse", "rat",
                 "freshwater", "saltwater",
                 "parakeet", "lovebird", "parrot"};
    mainAges = {"young", "adult", "senior"};
    mainSizes = {"small", "medium", "large"};
    mainGenders = {"male", "female"};
    mainTemperaments = {"happy", "friendly", "introverted", "active", "vigilant"};
    mainShelters = {"best friends", "humane society", "animal welfare league"};

    //Databse stuff
    openDB();



}

DBSearch::~DBSearch()
{

    db.~QSqlDatabase();
}

void DBSearch::search(string s){
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


    /*
     //Shelters
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainShelters.size(); i++){
            if(s == mainShelters.at(i)){
                attributeToSearch = "shelter";
                break;
            }
        }
    }
    */

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
       // QString qs = "SELECT rowid, " + qAttribute + " FROM pets WHERE " +
       //         qAttribute + " LIKE '%" + QString::fromStdString(s) + "%'";
        QString qs = "SELECT rowid, " + qAttribute + " FROM pets";
        query.exec(qs);
        while(query.next()){
            int id = query.value(0).toInt();
            string petAttribute = query.value(1).toString().toStdString();
           // cout << "ID: " << id << endl; //%male% female problem
            //count++;
            if(s == petAttribute){
                count++;
               cout << "ID: " << id << endl;
            }
        }
        cout << "Showing " << count << " results" << endl;
    } else {
        return -1; // -1 will indicate that the database couldn't open
    }

    return count;
}

/*
int DBSearch::generalQueryDB(string s){
    int count = 0;
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString qs = "SELECT rowid, species, breed, age, temperament, gender FROM pets";
        query.exec(qs);
        while(query.next()){
            //divide up the query
            int id = query.value(0).toInt();
            string species = query.value(1).toString().toStdString();
            string breed = query.value(2).toString().toStdString();
            string age = query.value(3).toString().toStdString();
            string temperament = query.value(4).toString().toStdString();
            string gender = query.value(5).toString().toStdString();

            //if s matches any of the fields
            if(s == species || s == breed || s == age
                    || s == temperament || s == gender){
                count++;
                cout << "ID: " << id << endl;
            }
        }
        cout << "Showing " << count << " results" << endl;
    } else {
        return -1; // -1 will indicate that the database couldn't open
    }

    return count;
}
*/


void DBSearch::openDB(){
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
