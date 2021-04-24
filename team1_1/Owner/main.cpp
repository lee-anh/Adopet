#include <iostream>
#include "./owner.h"

using namespace std;

int main(){


    Owner o = Owner("../../projectDB.sqlite", "best friends", "test", 01234, 1234567, "test");
    //o.setName("best friends");

   // Pet p = Pet("qwerty", "dog", "newBreed", "adult", "large", "happy", "male", "kids", "best friends", "loren ipsum");
   // o.uploadPets();
    for(int i = 0; i < (int) o.getPets().size(); i++){
        cout << o.getPets().at(i).getName() << endl;
    }


    return 0;
}
