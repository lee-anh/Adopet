#ifndef DBSEARCH_H
#define DBSEARCH_H

#include <iostream>
#include <vector>
#include <QtSql>

using namespace std;

class DBSearch
{
public:
    DBSearch();
    ~DBSearch();

    //two option: search bar or check/uncheck the boxes

    //cout all the animals that match
    void search(string s);

    int queryDB(string s, string attribute);
    int generalQueryDB(string s);





private:
    //database stuff
    void openDB();
    QSqlDatabase db;

    //vectors of keywords
    vector<string> mainSpecies;
    vector<string> mainBreeds;
    vector<string> mainAges;
    vector<string> mainSizes;
    vector<string> mainTemperaments;
    vector<string> mainGenders;

    //not doing main goodWiths
    //not doing zipcodes yet
    vector<string> mainShelters;


    //optimization for later: find likes

    //how do we refine searches?
    //store what you write to a datastructure
    //or you could query the database again (preferred)

    //specific order



};

#endif // DBSEARCH_H
