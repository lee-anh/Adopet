#include <iostream>
#include "savedlist.h"

using namespace std;

int main()
{
    //Demo
    SavedList *test = new SavedList();
    test->printVec(); //load from database

    Pet pUnsave = Pet();
    pUnsave.setID(2);

    Pet p = Pet();
    p.setID(3);

    Pet p1 = Pet();
    p1.setID(5);

    Pet p2 = Pet();
    p2.setID(7);

    test->unsavePet(pUnsave); //removing pet with ID 2
    test->savePet(p);
    test->savePet(p1);
    test->savePet(p2);

    return 0;
}
