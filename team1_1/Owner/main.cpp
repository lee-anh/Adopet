#include <iostream>
#include "./owner.h"

using namespace std;

int main(){
    Owner o = Owner("Shelter Owner");
    o.setName("best friends");

    o.uploadPets();
    return 0;
}
