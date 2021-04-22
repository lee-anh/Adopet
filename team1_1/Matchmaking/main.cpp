#include <iostream>
#include "matchmaking.h"

using namespace std;

//checking if matchmaking for adopters works
void checkPetMatches(){
    Matchmaking match = Matchmaking();
    match.openDB();
    string adopterName;
    cout << "Find match for adopter: ";
    getline(cin, adopterName);
    match.findMatchesForAdopter(adopterName);
    match.showPetResults();
}

//checking if finding matches for pets work
void checkAdopterMatches(){
    Matchmaking match = Matchmaking();
    match.openDB();
    string petName;
    cout << "Find match for pet: ";
    getline(cin, petName);
    match.fillPets();
    match.findMatchesForPet(petName);
    match.showAdopterResults();
}

//checking if finding matches for all pets in a specific shelter work
void checkAllShelterPetsMatches(){
    Matchmaking match = Matchmaking();
    match.openDB();
    string shelterName;
    cout << "Find matches for pets in the shelter: ";
    getline(cin, shelterName);
    match.fillPets();
    match.findMatchesForPets(shelterName);
}

int main(){
    checkPetMatches();
    //checkAdopterMatches();
    //checkAllShelterPetsMatches();
}
