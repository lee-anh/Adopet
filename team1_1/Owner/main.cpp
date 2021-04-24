#include <iostream>
#include "./owner.h"

using namespace std;

int main(){

    Owner o = Owner();
    o.setName("best friends");

    Pet p = Pet("qwerty", "dog", "newBreed", "adult", "large", "happy", "male", "kids", "best friends", "loren ipsum");
    o.fillPets();
    vector<Pet> v =  o.getPets();

    return 0;
}
