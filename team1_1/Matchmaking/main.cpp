#include <iostream>
#include "matchmaking.h"

using namespace std;

int main(){
    preferences* p = new preferences();
    p->addAge("Young");
    p->addAge("Adult");
    p->addBreed("Golden Retriever");
    p->addSpecies("Dog");
    p->addTemperament("Happy");

    Matchmaking* match = new Matchmaking();
    match->findMatch(p);
    match->showResults();
}
