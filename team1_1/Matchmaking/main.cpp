#include <iostream>
#include "matchmaking.h"

using namespace std;

//checking if matchmaking for adopters works
void checkPetMatches(){
    Preferences* p = new Preferences();
    p->addAge("young");
    p->addAge("adult");
    p->addBreed("golden retriever");
    p->addSpecies("dog");
    p->addTemperament("happy");
    p->addSize("middle");
    p->addShelter("human society");
    p->addGoodWith("kids");

    Matchmaking* match = new Matchmaking();
    match->findMatchForAdopter(p);
    match->showPetResults(4);
}

//checking if finding matches for pets work
void checkAdopterMatches(){
    Matchmaking* match = new Matchmaking();
    string petName = "jessica";
    match->fillPets();
    match->findMatchForPet(petName);
    cout << "Searching adopter matches for pet: " << petName << endl;
    match->showAdopterResults(3);
}

int main(){
    //checkPetMatches();

    checkAdopterMatches();
}
