#include <iostream>

#include "dbsearch.h"

using namespace std;

int main()
{
    DBSearch *dbTest = new DBSearch();

    cout << "Search bar: ";
    string input;
    cin >> input;
    cout << endl;
    dbTest->search(input);
    dbTest->printMatchingVec();

    return 0;
}

