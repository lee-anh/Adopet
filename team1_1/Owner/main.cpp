#include <iostream>
#include "./owner.h"

using namespace std;

void printPets(vector<Pet> p){
    for(int i = 0; i < (int) p.size(); i++){
        cout << p.at(i).getID() << ": " << p.at(i).getName() << endl;
    }
    cout << endl;
}

int main(){
    Owner o = Owner();
    o.setName("best friends");

    o.fillPets();

    Pet p = Pet("name", "species", "breed", "age", "size", "temperament",
                "gender", "goodWith", "shelter", "bio");
    o.uploadPet(p);

    printPets(o.getPets());

    return 0;
}
