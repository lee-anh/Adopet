#include "matchmaking.h"

Matchmaking::Matchmaking(){
    openDB();
}

Matchmaking::~Matchmaking(){
    db.~QSqlDatabase();
}

/*
 * Opens the database before reading/modifying it
*/
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

/*
 * Sorts the vector of animal results based on the score of each animal
*/
bool Matchmaking::customSort(const pair<Pet*,int> &a, const pair<Pet*,int> &b){
    return (a.second > b.second);
}

/*
 * Loops through the passed vector of a tag and checks if it contains the passed preference
 * @param list A specific tag list
 * @param name User's preference
 * @return 1 if found, 0 otherwise
*/
int Matchmaking::getScore(vector<string> list, string name){
    for(int i = 0; i < (int) list.size(); i++){
        if(list.at(i) == name) return 1;
    }
    return 0;
}

/*
 * The matchmaking algorithm.
 * Goes through the database line by line and stores each animal.
 * Sorts the animals based on matching score at the end.
 * @param p User preference object
*/
void Matchmaking::findMatch(Preferences *p){
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT rowid, * from pets";
        query.exec(s);
        while(query.next()){
            int currScore = 0;

            //storing information in each line
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

            //gathering the scores based on whether it matches user preferences
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

/*
 * Prints out the result - sorted vector of animals based on score
*/
void Matchmaking::showResults(){
    for(int i = 0; i <= (int) dbResults.size(); i++){
         cout << "Pet Name: " << dbResults[i].first->getName() << ", Score: " << dbResults[i].second << endl;
    }
}

/*
 * Prints out the result - sorted vector of animals based on score.
 * Takes in a specified amount of results to show each time.
 * @param amount Number of items to show each time
*/
void Matchmaking::showResults(int amount){
    int resultSize = (int) dbResults.size();
    int shownAmount = 0;
    int input;
    while ((input = cin.get())) {
        if (input == (int)'\n' && shownAmount <= resultSize) {
            for(int i = 0; i < amount && shownAmount <= resultSize; i++){
                cout << "Pet Name: " << dbResults[shownAmount].first->getName() << ", Score: " << dbResults[shownAmount].second << endl;
                shownAmount++;
            }
        }
        else {
            cout << "Showed all results!\n";
            break;
        }
    }
}
