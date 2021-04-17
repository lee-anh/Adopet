#include <iostream>
#include "./owner.h"

using namespace std;

int main(){

    Owner o = Owner("Shelter Owner");
    o.setName("best friends");

    Pet p = Pet("qwerty", "dog", "newBreed", "adult", "large", "happy", "male", "kids", "best friends", "loren ipsum");
    o.uploadPets();

    return 0;
}
