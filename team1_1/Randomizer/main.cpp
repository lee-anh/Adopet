#include <iostream>

#include "peoplerandomizer.h"
using namespace std;

int main()
{
    PeopleRandomizer *test = new PeopleRandomizer(10);
    test->writeToCSV();
    test->speciesTest();

    return 0;
}
