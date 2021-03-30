#ifndef DBSEARCH_H
#define DBSEARCH_H

#include <iostream>

using namespace std;

class DBSearch
{
public:
    DBSearch();
    ~DBSearch();


    //cout all the animals that match
    void species(string s);
    void breed(string s);
    void age(string s);
    void temperament(string s);
    void gender(string s);

    //how do we refine searches?
    //store what you write to a datastructure
    //or you could query the database again (preferred)

    //specific order


};

#endif // DBSEARCH_H
