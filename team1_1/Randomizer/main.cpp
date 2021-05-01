#include <iostream>

#include "peoplerandomizer.h"
#include "petrandomizer.h"
using namespace std;

int main()
{
    /*
    PeopleRandomizer *test = new PeopleRandomizer(10);
    test->writeToCSV();
    delete test;
    */

    PetRandomizer* test1 = new PetRandomizer(100);
    //test1->getFileNameBySpecies("rabbit");

    test1->writeToCSV();
    return 0;
}
