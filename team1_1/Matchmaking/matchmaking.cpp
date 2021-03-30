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

void Matchmaking::findMatch(Preferences *p){
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT rowid, * from pets";
        query.exec(s);
        while(query.next()){
            int currScore = 0;

            int id = query.value(0).toInt();
            string species = query.value(2).toString().toStdString();
            string breed = query.value(3).toString().toStdString();
            string age = query.value(4).toString().toStdString();
            string temperament = query.value(5).toString().toStdString();
            string gender = query.value(6).toString().toStdString();

            for(int i = 0; i < (int) p->getSpecies().size(); i++){
                if(p->getSpecies().at(i) == species){
                    currScore++;
                    break;
                }
            }

            for(int j = 0; j < (int) p->getBreed().size(); j++){
                if(p->getBreed().at(j) == breed) {
                    currScore++;
                    break;
                }
            }

            for(int k = 0; k < (int) p->getAge().size(); k++){
                if(p->getAge().at(k) == age) {
                    currScore++;
                    break;
                }
            }

            for(int l = 0; l < (int) p->getTemperament().size(); l++){
                if(p->getTemperament().at(l) == temperament) {
                    currScore++;
                    break;
                }
            }

                if(p->getGender() == gender) currScore++;
                else if(p->getGender() == "all") currScore++;

            dbResults.push_back(make_pair(id, currScore));
        }
    }
}

bool Matchmaking::customSort(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second > b.second);
}

void Matchmaking::showResults(){
    sort(dbResults.begin(), dbResults.end(), customSort);
    for(int i = 0; i < (int) dbResults.size(); i++){
         cout << "Id: " << dbResults[i].first << ", Score: " << dbResults[i].second << endl;
    }
}
