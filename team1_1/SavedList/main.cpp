#include <iostream>
#include "savedlist.h"

using namespace std;

int main()
{

    SavedList *test = new SavedList();
    Pet p = Pet();
    p.setID(1);
    test->unsavePet(p);

    return 0;
}
