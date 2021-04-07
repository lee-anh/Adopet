#include <iostream>

#include "dbsearch.h"

using namespace std;

int main()
{
    DBSearch *dbTest = new DBSearch();


    dbTest->addToAttributes("cat", "species");
    dbTest->addToAttributes("dog", "species");

    dbTest->addToAttributes("maine coon", "breed");
    dbTest->addToAttributes("young", "age");
    dbTest->removeFromAttributes("maine coon", "breed");


    cout << dbTest->createQuery() << endl;


    return 0;
}

