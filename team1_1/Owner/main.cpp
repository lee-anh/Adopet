#include <iostream>
#include "./owner.h"

using namespace std;

/*
 * Prints out the pets with their information given a pet list
 * @param p List of pets
*/
void printPets(vector<Pet> p){
    for(int i = 0; i < (int) p.size(); i++){
        cout << p.at(i).getID() << ": " << p.at(i).getName() << endl;
    }
    cout << endl;
}

int main(){
    /*
    Owner o = Owner();
    o.setName("best friends");

    o.fillPets();

    Pet p = Pet(101, "nameCHANGEDAGAIN", "species", "breedCHANGED", "age", "size", "temperament",
                "gender", "goodWithCHANGED", "best friends", "bio");
    o.removePet(p);

    printPets(o.getPets());
    */

    return 0;
}
