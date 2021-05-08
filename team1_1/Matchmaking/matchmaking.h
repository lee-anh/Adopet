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
    Matchmaking(string n);
    Matchmaking(string path, string n);
    ~Matchmaking();

    void openDB();                                                                       //opens the database before performing actions
    void closeDB();                                                                      //closes the database
    void fillPets();                                                                     //stores all the pets in the DB in the vector
    Pet makePet(QSqlQuery query);                                                                      //makes and retrieves a Pet by passing the query in a DB
    vector<pair<Pet, pair<Adopter, int>>> findMatchesForPets(string shelterName);                                         //finds matching potential adopters for all pets in the DB
    vector<pair<Adopter, int>> findBestMatchForPet(Pet p);                             //finds the best adopter match for the specified pet
    vector<pair<Adopter, int>> findMatchesForPet(Pet p);                                                      //finds the matching potential adopters based on pet attributes
    vector<pair<Adopter, int>> findMatchesForPet(int petID);                                                 // finds the pet with the given name and finds adopter matches for it
    Preferences fillPreferences(string adopterName);                                    //searches the DB and gets the preference of the passed user
    Preferences fillPreference(Preferences p, string attribute, string attributeType);         //sets a specific preference based on attribute type and attribute
    vector<pair<Pet, int>> findMatchesForAdopter(string adopterName);                                      //finds the matching pets based on an adopter user



    vector<pair<Pet, int>> findMatchesForAdopterDistance(string adopterName);
    vector<pair<Adopter, int>> fillAdopterResults(string name, int score, vector<pair<Adopter, int>> res);    //adds in an adopter with the given information to the adopter results vector
    void showPetResults();                                                               //prints out the list of matching pets based on score
    void showPetResults(int amount);                                                     //prints out the list of matching pets based on score in the amount shown
    void showAdopterResults();                                                           //prints out the list of matching adopters based on score
    void showAdopterResults(int amount);                                                 //prints out the list of matching adopters based on score
    int getPetScore(vector <string> list, string name);                                  //checks the passed list if it contains what the user wanted
    int getAdopterScore(Pet p, string attributeType, string attribute);                 //checks if the pet contains the adopter's preference
    static bool customPetResultSort(const pair<Pet,int> &a, const pair<Pet,int> &b);   //sorts the pet result list based on score
    static bool customAdopterResultSort(const pair<Adopter,int> &a, const pair<Adopter,int> &b);              //sorts the adopter results list based on score

    vector<Pet> getAllPets();      //getter method for allPets

private:
    vector<pair<Pet, int>> petResults;
    vector<pair<Adopter, int>> adopterResults;
    vector<pair<Pet, pair<Adopter, int>>> allResultsForPets;
    vector<Pet> allPets;
    QSqlDatabase db;


    vector<string> parseFile();
    string username;
    string dbName;
};

#endif // MATCHMAKING_H
