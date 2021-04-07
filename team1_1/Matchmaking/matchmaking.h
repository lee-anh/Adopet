#ifndef MATCHMAKING_H
#define MATCHMAKING_H

#include "../Adopter/adopter.h"
#include "../Pets/pet.h"
#include <vector>
#include <QtSql>

using namespace std;

class Matchmaking{
public:
    Matchmaking();
    ~Matchmaking();

    void openDB();                                      //opens the database before performing actions
    Preferences* fillPreferences(string adopterName);           //searches the DB and gets the preference of the passed user
    void updatePreference(Preferences* p, string attribute, string attributeType);     //sets a specific preference based on attribute type and attribute
    void findMatchForAdopter(string adopterName);           //finds the matching pets based on an adopter user
    void fillPets();                                    //stores all the pets in the DB in the vector
    void findMatchForPets();                            //finds matching potential adopters for all pets in the DB
    void findMatchForPet(Pet *p);                       //finds the matching potential adopters based on pet attributes
    void findMatchForPet(string name);                 // finds the pet with the given name and finds adopter matches for it
    void showPetResults();                              //prints out the list of matching pets based on score
    void showPetResults(int amount);
    void fillAdopterResults(string name, int score);    //adds in an adopter with the given information to the adopter results vector
    void showAdopterResults();                          //prints out the list of matching adopters based on score
    void showAdopterResults(int amount);                          //prints out the list of matching adopters based on score
    int getPetScore(vector <string> list, string name);    //checks the passed list if it contains what the user wanted
    int getAdopterScore(Pet* p, string attributeType, string attribute);    //checks if the pet contains the adopter's preference
    static bool customPetResultSort(const pair<Pet*,int> &a, const pair<Pet*,int> &b);     //sorts the pet result list based on score
    static bool customAdopterResultSort(const pair<Adopter*,int> &a, const pair<Adopter*,int> &b); //sorts the adopter results list based on score

private:
    vector<pair<Pet*, int>> petResults;
    vector<pair<Adopter*, int>> adopterResults;
    vector<Pet*> allPets;
    QSqlDatabase db;
};

#endif // MATCHMAKING_H
