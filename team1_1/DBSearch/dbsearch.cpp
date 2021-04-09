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

    dbSearchdb.~QSqlDatabase();
}

bool DBSearch::addToAttributes(string attribute, string category){
    int index = getIndex(category);

    if(index < 0){
        return false;
    }
    //else
    constraints[index].push_back(attribute);
    return true;
}


bool DBSearch::removeFromAttributes(string attribute, string category){
    int index = getIndex(category);
    bool toReturn = false;
    if (index < 0){
        return toReturn;
    }
    //else
    for(int i = 0; i < (int) constraints[index].size(); i++){
        if(attribute == constraints[index][i]){
            constraints[index].erase(constraints[index].begin() + i);
            toReturn = true;
            break;
        }
    }

    return toReturn;

}

bool DBSearch::search(string s){
    //clear vectors in the constraints vector, not constraint vector itsle
    for(int i = 0; i < (int) constraints.size(); i++){
        constraints[i].clear();
    }

    //lowercase the input
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    string attributeToSearch = "";

    //species
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


    //shelter
    if(attributeToSearch == ""){
        for(int i = 0; i < (int) mainShelters.size(); i++){
            if(s == mainShelters.at(i)){
                attributeToSearch = "shelter";
                break;
            }
        }
    }


    addToAttributes(s, attributeToSearch);
    return true; //TODO


}






int DBSearch::runNewQuery(){
    //clear the current vector of matchingPets
    matchingPets.clear();

    //generate query from current constraints vector
    string qry = createQuery();

    //run query, which alters the matchingPets vector
    return queryDB(qry);


}

string DBSearch::createQuery(){
    string query = "SELECT id, name, species, breed, age, "
        "size, temperament, gender, goodWith, shelter, bio FROM pets ";
    int first = 0;
    for(int i = 0; i < (int) constraints.size(); i++){
        vector<string> temp = constraints[i];
        if(first == 0 && temp.size() > 0){
            query = query + "WHERE (";
            first++;
        } else if (first > 0 && temp.size() > 0){
            query = query + "AND (";
        } //else do nothing

        for(int j = 0; j < (int) temp.size(); j++){
            query = query  + attributes[i] + " = \"" + temp[j] + "\"";
            if(j < ((int) temp.size() - 1)){
                query = query + " OR ";
            } else {
                query = query + ") ";
            }
        }
    }

    return query;
}


int DBSearch::queryDB(string qry){
    int count = 0;
    if(dbSearchdb.open()){
        QSqlQuery query = QSqlQuery(dbSearchdb);
        QString qs = QString::fromStdString(qry);
        query.exec(qs);
        while(query.next()){
            int id = query.value(0).toInt();
            string name = query.value(1).toString().toStdString();
            string species = query.value(2).toString().toStdString();
            string breed = query.value(3).toString().toStdString();
            string age = query.value(4).toString().toStdString();
            string size = query.value(5).toString().toStdString();
            string temperament = query.value(6).toString().toStdString();
            string gender = query.value(7).toString().toStdString();
            string goodWith = query.value(8).toString().toStdString();
            string shelter = query.value(9).toString().toStdString();
            string bio = query.value(10).toString().toStdString();



            Pet p = Pet(id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
            matchingPets.push_back(p);
            count++;
        }

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
    dbSearchdb = QSqlDatabase::addDatabase("QSQLITE", "dbsearch");
    string fullName = filepath;
    dbSearchdb.setDatabaseName(QString::fromStdString(fullName));
    if(!dbSearchdb.open()){
        std::cerr << "Database does not open -- "
                  << dbSearchdb.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully\n";
    }
}


void DBSearch::fillVecsFromDB(){
    if(dbSearchdb.open()){
    QSqlQuery query = QSqlQuery(dbSearchdb);

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
    attributes = {"species", "breed", "age",
                  "size", "temperament", "gender", "goodWith", "shelter"};
    constraints.resize(8, vector<string>(0)); //8 attributes to compare
}

void DBSearch::printMatchingVec(){
    for(int i = 0; i < (int) matchingPets.size(); i++){
        cout << matchingPets.at(i).getName() << endl;
    }
}



int DBSearch::getIndex(string category){
    if (category == "species"){
        return 0;
    } else if (category == "breed"){
        return 1;
    } else if (category == "age"){
        return 2;
    } else if (category == "size"){
        return 3;
    } else if (category == "temperament"){
        return 4;
    } else if (category == "gender"){
        return 5;
    } else if (category == "goodWith"){
        return 6;
    } else if (category == "shelter"){
        return 7;
    } else {
        return -1;
    }
}

