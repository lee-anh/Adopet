#include <iostream>

#include "peoplerandomizer.h"
#include "petrandomizer.h"
using namespace std;

int main()
{

    //PeopleRandomizer *test = new PeopleRandomizer(100);
    //test->writeToCSV();
    //delete test;


    PetRandomizer* test1 = new PetRandomizer(100);
    test1->writeToCSV();
    return 0;
}
