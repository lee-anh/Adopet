#include <iostream>

#include "peoplerandomizer.h"
#include "petrandomizer.h"
using namespace std;

int main()
{
    /*
    PeopleRandomizer *test = new PeopleRandomizer(10);
    test->writeToCSV();
    test->speciesTest();
    delete test;
    */

    PetRandomizer* test1 = new PetRandomizer(10);
    test1->writeToCSV();

    return 0;
}
