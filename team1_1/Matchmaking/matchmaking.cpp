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
 * Loops through all the pets in the database and stores each pet in a vector.
*/
void Matchmaking::fillPets(){
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT * FROM pets";
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
 * Adds an adopter with the passed name and score to the adopter results vector
 * @param name Adopter's username
 * @param score Adopter's score relative to a Pet's tags
*/
vector<pair<Adopter*, int>> Matchmaking::fillAdopterResults(string name, int score, vector<pair<Adopter*, int>> res){
    Adopter* adopter = new Adopter();
    adopter->setUsername(name);
    //cout << "Adopter username: " << adopter->getUsername() << endl;
    //cout << "Adding adopter to vector...CurrentScore: " << currScore << " userName: " << userName << endl;
    res.push_back(make_pair(adopter, score));
    return res;
}


/*
 * Finds the best adopter match for the given Pet
 * @param p Pet
 * @return Adopter matches and their respective scores
*/
vector<pair<Adopter*, int>> Matchmaking::findBestMatchForPet(Pet *p){
    vector<pair<Adopter*, int>> tempAdopterResults;
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT * FROM preferences";
        query.exec(s);
        string userName = "";
        //need to handle score change and userName change
        int currScore = 0;
        while(query.next()){
            string newUserName = query.value(0).toString().toStdString();

            if(userName != newUserName){
                if(userName != ""){
                    tempAdopterResults = fillAdopterResults(userName, currScore, tempAdopterResults);
                    currScore = 0;
                }
                userName = newUserName;
            }

            //storing information in each line
            string attribute = query.value(1).toString().toStdString();
            string attributeType = query.value(2).toString().toStdString();
            currScore += getAdopterScore(p, attributeType, attribute);
        }
        tempAdopterResults = fillAdopterResults(userName, currScore, tempAdopterResults);
    }

    sort(tempAdopterResults.begin(), tempAdopterResults.end(), customAdopterResultSort);
    return tempAdopterResults;
}

/*
 * Loops through all the pets in the vector and finds adopters whose preference match the pet.
*/
void Matchmaking::findMatchesForPets(string shelterName){
    vector<Pet*> currShelterPets;
    for(int i = 0; i < (int)allPets.size(); i++){
        if(allPets.at(i)->getShelter() == shelterName) currShelterPets.push_back(allPets.at(i));
    }

    for(int i = 0; i < (int)currShelterPets.size(); i++){
        vector<pair<Adopter*, int>> tempMatches = findBestMatchForPet(currShelterPets.at(i));
        cout << "Match for " << currShelterPets.at(i)->getName()
             << " - Adopter: " << tempMatches.at(0).first->getUsername()
             << "   Socer: " << tempMatches.at(0).second << endl;
    }
}

/*
 * Loops through all the pets and finds the pet with the passed name, and then finds adopter matches for it
*/
void Matchmaking::findMatchesForPet(string name){
    for(int i = 0; i < (int)allPets.size(); i++){
        if(allPets.at(i)->getName() == name) findMatchesForPet(allPets.at(i));
    }
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
 * The matchmaking algorithm.
 * Goes through the database line by line and stores each animal.
 * Sorts the animals based on matching score at the end.
 * @param p User preference object
*/
void Matchmaking::findMatchesForPet(Pet *p){
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT * FROM preferences";
        query.exec(s);
        string userName = "";
        //need to handle score change and userName change
        int currScore = 0;
        while(query.next()){
            string newUserName = query.value(0).toString().toStdString();

            if(userName != newUserName){
                if(userName != ""){
                    fillAdopterResults(userName, currScore, adopterResults);
                    currScore = 0;
                }
                userName = newUserName;
            }

            //storing information in each line
            string attribute = query.value(1).toString().toStdString();
            string attributeType = query.value(2).toString().toStdString();
            currScore += getAdopterScore(p, attributeType, attribute);
        }
        fillAdopterResults(userName, currScore, adopterResults);
    }

    sort(adopterResults.begin(), adopterResults.end(), customAdopterResultSort);
}

/*
 * Sets the specific preference of the user based on the bassed attribute and type of attribute
 * @param p Preference to be editted
 * @param attributeType the type of the attribute
 * @param attribute the attribute itself
*/
void Matchmaking::fillPreference(Preferences* p, string attribute, string attributeType){
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
    cout << "FillPreferences entered" << endl;
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString name = QString::fromStdString(adopterName);
        QString s = "SELECT * FROM preferences WHERE adopterUsername = '" + name + "'";
        query.exec(s);
        while(query.next()){
            string attribute = query.value(1).toString().toStdString();
            string attributeType = query.value(2).toString().toStdString();
            fillPreference(p, attribute, attributeType);
        }
    }
    return p;
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
 * The matchmaking algorithm.
 * Goes through the database line by line and stores each animal.
 * Sorts the animals based on matching score at the end.
 * @param p User preference object
*/
void Matchmaking::findMatchesForAdopter(string adopterName){
    Preferences* adopterPreference = fillPreferences(adopterName);
    if(db.open()){
        QSqlQuery query = QSqlQuery();
        QString s = "SELECT * FROM pets";
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
 * Prints out the adopter result - sorted vector of animals based on score
*/
void Matchmaking::showAdopterResults(){
    for(int i = 0; i <= (int) adopterResults.size(); i++){
         cout << "Adopter Name: " << adopterResults[i].first->getUsername() << ", Score: " << adopterResults[i].second << endl;
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
