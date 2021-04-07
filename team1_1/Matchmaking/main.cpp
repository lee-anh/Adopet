#include <iostream>
#include "matchmaking.h"

using namespace std;

//checking if matchmaking for adopters works
void checkPetMatches(){
    Matchmaking* match = new Matchmaking();
    string adopterName;
    cout << "Find match for adopter: ";
    getline(cin, adopterName);
    match->findMatchForAdopter(adopterName);
    match->showPetResults();
}

//checking if finding matches for pets work
void checkAdopterMatches(){
    Matchmaking* match = new Matchmaking();
    string petName;
    cout << "Find match for pet: ";
    getline(cin, petName);
    match->fillPets();
    match->findMatchForPet(petName);
    match->showAdopterResults();
}

int main(){
    checkPetMatches();
    //checkAdopterMatches();

    //algorithm3(string shelterName);
}
