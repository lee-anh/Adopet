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
bool Matchmaking::customPetResultSort(const pair<Pet*,int> &a, const pair<Pet*,int> &b){
    return (a.second > b.second);
}

/*
 * Sorts the vector of animal results based on the score of each animal
*/
bool Matchmaking::customAdopterResultSort(const pair<Adopter*,int> &a, const pair<Adopter*,int> &b){
    return (a.second > b.second);
}

/*
 * Loops through the passed vector of a tag and checks if it contains the passed preference
 * @param list A specific tag list
 * @param name User's preference
 * @return 1 if found, 0 otherwise
*/
int Matchmaking::getPetScore(vector<string> list, string name){
    for(int i = 0; i < (int) list.size(); i++){
        if(list.at(i) == name) return 1;
    }
    return 0;
}

/*
 * Checks if the passed Pet contains the given preference of an adopter
 * @param p Pet to be checked
 * @param attributeType the type of the attribute
 * @param attribute the attribute itself
 * @return 1 if there's a match, 0 otherwise
*/
int Matchmaking::getAdopterScore(Pet* p, string attributeType, string attribute){
    if(attributeType == "species" && p->getSpecies() == attribute) return 1;
    else if(attributeType == "breed" && p->getBreed() == attribute) return 1;
    else if(attributeType == "age" && p->getAge() == attribute) return 1;
    else if(attributeType == "size" && p->getSize() == attribute) return 1;
    else if(attributeType == "temperament" && p->getTemperament() == attribute) return 1;
    else if(attributeType == "gender" && p->getGender() == attribute) return 1;
    else if(attributeType == "goodWith" && p->getGoodWith() == attribute) return 1;
    else if(attributeType == "shelter" && p->getShelter() == attribute) return 1;

    return 0;
}

/*
 * Loops through all the pets in the database and stores each pet in a vector.
*/
void Matchmaking::fillPets(){
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT * from pets";
        query.exec(s);
        while(query.next()){
            //storing information in each line
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

            Pet* pet = new Pet(name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
            allPets.push_back(pet);
        }
    }
}

/*
 * Loops through all the pets in the vector and finds adopters whose preference match the pet.
*/
void Matchmaking::findMatchForPets(){
    for(int i = 0; i < (int)allPets.size(); i++){
        findMatchForPet(allPets.at(i));
    }
}

/*
 * Loops through all the pets and finds the pet with the passed name, and then finds adopter matches for it
*/
void Matchmaking::findMatchForPet(string name){
    for(int i = 0; i < (int)allPets.size(); i++){
        if(allPets.at(i)->getName() == name) findMatchForPet(allPets.at(i));
    }
}

/*
 * Adds an adopter with the passed name and score to the adopter results vector
 * @param name Adopter's username
 * @param score Adopter's score relative to a Pet's tags
*/
void Matchmaking::fillAdopterResults(string name, int score){
    Adopter* adopter = new Adopter();
    adopter->setUsername(name);
    //cout << "Adopter username: " << adopter->getUsername() << endl;
    //cout << "Adding adopter to vector...CurrentScore: " << currScore << " userName: " << userName << endl;
    adopterResults.push_back(make_pair(adopter, score));
}

/*
 * The matchmaking algorithm.
 * Goes through the database line by line and stores each animal.
 * Sorts the animals based on matching score at the end.
 * @param p User preference object
*/
void Matchmaking::findMatchForPet(Pet *p){
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT * from preferences";
        query.exec(s);
        string userName = "";
        //need to handle score change and userName change
        int currScore = 0;
        while(query.next()){
            string newUserName = query.value(0).toString().toStdString();

            //cout << "Previous userName: " << userName << endl;
            //cout << "Current userName# " << count << ": " << newUserName << endl;

            if(userName != newUserName){
                if(userName != ""){
                    fillAdopterResults(userName, currScore);
                    currScore = 0;
                }
                userName = newUserName;
            }

            //storing information in each line
            string attribute = query.value(1).toString().toStdString();
            string attributeType = query.value(2).toString().toStdString();
            currScore += getAdopterScore(p, attributeType, attribute);
        }
        fillAdopterResults(userName, currScore);
    }

    sort(adopterResults.begin(), adopterResults.end(), customAdopterResultSort);
}

/*
 * Sets the specific preference of the user based on the bassed attribute and type of attribute
 * @param p Preference to be editted
 * @param attributeType the type of the attribute
 * @param attribute the attribute itself
*/
void Matchmaking::updatePreference(Preferences* p, string attribute, string attributeType){
    if(attributeType == "species") p->addSpecies(attribute);
    else if(attributeType == "breed") p->addBreed(attribute);
    else if(attributeType == "age") p->addAge(attribute);
    else if(attributeType == "size") p->addSize(attribute);
    else if(attributeType == "temperament") p->addTemperament(attribute);
    else if(attributeType == "gender") p->setGender(attribute);
    else if(attributeType == "goodWith") p->addGoodWith(attribute);
    else if(attributeType == "shelter") p->addShelter(attribute);
}

/*
 * Loops through the preferences database and gets the preference of the passed adopter user
 * @param adopterName Username of the adopter
 * @return Preference object with the adopter's preferences
*/
Preferences* Matchmaking::fillPreferences(string adopterName){
    Preferences* p = new Preferences();
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT * from preferences";
        query.exec(s);
        while(query.next()){
            string name = query.value(0).toString().toStdString();
            if(name == adopterName){
                string attribute = query.value(1).toString().toStdString();
                string attributeType = query.value(2).toString().toStdString();
                updatePreference(p, attribute, attributeType);
            }
        }
    }
    return p;
}

/*
 * The matchmaking algorithm.
 * Goes through the database line by line and stores each animal.
 * Sorts the animals based on matching score at the end.
 * @param p User preference object
*/
void Matchmaking::findMatchForAdopter(string adopterName){
    Preferences* adopterPreference = fillPreferences(adopterName);
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT * from pets";
        query.exec(s);
        while(query.next()){
            int currScore = 0;

            //storing information in each line
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

            Pet* pet = new Pet(name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);

            //gathering the scores based on whether it matches user preferences
            currScore += getPetScore(adopterPreference->getSpecies(), species);
            currScore += getPetScore(adopterPreference->getBreed(), breed);
            currScore += getPetScore(adopterPreference->getAge(), age);
            currScore += getPetScore(adopterPreference->getTemperament(), temperament);
            currScore += getPetScore(adopterPreference->getSize(), size);
            currScore += getPetScore(adopterPreference->getGoodWith(), goodWith);
            currScore += getPetScore(adopterPreference->getShelter(), shelter);
            if(adopterPreference->getGender() == gender || adopterPreference->getGender() == "all") currScore++;

            petResults.push_back(make_pair(pet, currScore));
        }
    }

    sort(petResults.begin(), petResults.end(), customPetResultSort);
}

/*
 * Prints out the pet result - sorted vector of animals based on score
*/
void Matchmaking::showPetResults(){
    for(int i = 0; i <= (int) petResults.size(); i++){
         cout << "Pet Name: " << petResults[i].first->getName() << ", Score: " << petResults[i].second << endl;
    }
}

/*
 * Prints out the adopter result - sorted vector of animals based on score
*/
void Matchmaking::showAdopterResults(){
    for(int i = 0; i <= (int) adopterResults.size(); i++){
         cout << "Adopter Name: " << adopterResults[i].first->getUsername() << ", Score: " << adopterResults[i].second << endl;
    }
}

/*
 * Prints out the result - sorted vector of animals based on score.
 * Takes in a specified amount of results to show each time.
 * @param amount Number of items to show each time
*/
void Matchmaking::showPetResults(int amount){
    int resultSize = (int) petResults.size();
    int shownAmount = 0;
    int input;
    while ((input = cin.get())) {
        if (input == (int)'\n' && shownAmount <= resultSize) {
            for(int i = 0; i < amount && shownAmount <= resultSize; i++){
                cout << "Pet Name: " << petResults[shownAmount].first->getName() << ", Score: " << petResults[shownAmount].second << endl;
                shownAmount++;
            }
        }
        else {
            cout << "Showed all results!\n";
            break;
        }
    }
}

/*
 * Prints out the result - sorted vector of adopters based on their score.
 * Takes in a specified amount of results to show each time.
 * @param amount Number of items to show each time
*/
void Matchmaking::showAdopterResults(int amount){
    int resultSize = (int) adopterResults.size();
    int shownAmount = 0;
    int input;
    while ((input = cin.get())) {
        if (input == (int)'\n' && shownAmount <= resultSize) {
            for(int i = 0; i < amount && shownAmount <= resultSize; i++){
                cout << "Pet Name: " << adopterResults[shownAmount].first->getUsername() << ", Score: " << adopterResults[shownAmount].second << endl;
                shownAmount++;
            }
        }
        else {
            cout << "Showed all results!\n";
            break;
        }
    }
}
