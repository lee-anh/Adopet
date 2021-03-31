#include "matchmaking.h"

Matchmaking::Matchmaking(){
    openDB();
}

Matchmaking::~Matchmaking(){
    db.~QSqlDatabase();
}

void Matchmaking::openDB(){
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

bool Matchmaking::customSort(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second > b.second);
}

int Matchmaking::getScore(vector<string> list, string name){
    for(int i = 0; i < (int) list.size(); i++){
        if(list.at(i) == name) return 1;
    }
    return 0;
}

void Matchmaking::findMatch(Preferences *p){
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT rowid, * from pets";
        query.exec(s);
        while(query.next()){
            int currScore = 0;

            int id = query.value(0).toInt();
            string name = query.value(1).toString().toStdString();
            string species = query.value(2).toString().toStdString();
            string breed = query.value(3).toString().toStdString();
            string age = query.value(4).toString().toStdString();
            string temperament = query.value(5).toString().toStdString();
            string gender = query.value(6).toString().toStdString();

            //make constructor with these parameters
            //age should be string
            //make temperament a string for now?
            Pet* pet = new Pet(name, age, species, breed, gender, temperament);

            currScore += getScore(p->getSpecies(), species);
            currScore += getScore(p->getBreed(), breed);
            currScore += getScore(p->getAge(), age);
            currScore += getScore(p->getTemperament(), temperament);
            if(p->getGender() == gender || p->getGender() == "all") currScore++;

            dbResults.push_back(make_pair(pet, currScore));
        }
    }

    sort(dbResults.begin(), dbResults.end(), customSort);
}

//display information about the pet
void Matchmaking::showResults(){
    for(int i = 0; i <= (int) dbResults.size(); i++){
         cout << "Pet Name: " << dbResults[i].first.getName() << ", Score: " << dbResults[i].second << endl;
    }
}

void Matchmaking::showResults(int amount){
    int resultSize = (int) dbResults.size();
    int shownAmount = 0;
    int input;
    while ((input = cin.get())) {
        if (input == (int)'\n' && shownAmount <= resultSize) {
            for(int i = 0; i < amount && shownAmount <= resultSize; i++){
                cout << "Pet Name: " << dbResults[shownAmount].first.getName()
                     << ", Score: " << dbResults[shownAmount].second << endl;
                shownAmount++;
            }
        }
        else {
            cout << "Showed all results!\n";
            break;
        }
    }
}
