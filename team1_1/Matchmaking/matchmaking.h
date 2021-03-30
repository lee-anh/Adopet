#ifndef MATCHMAKING_H
#define MATCHMAKING_H

#include "../Adopter/adopter.h"
//include animals
#include <vector>
#include <QtSql>

using namespace std;

class Matchmaking
{
public:
    Matchmaking();
    ~Matchmaking();

    void findMatch(preferences *p);
    //cout the 10 most relavent
    void openDB();
    void showResults();
    static bool customSort(const pair<int,int> &a, const pair<int,int> &b);


private:
    vector<pair<int, int>> dbResults;
    QSqlDatabase db;



    //search pet database once
    //vector<pair<int, int>> database searching results.
    //first int id , second int match score
    //keep sorting in mind
    //keep match score ties in mind (counter)


    //search the vector of pairs and get 10 best animals

    //search the database again for the 10 best animals
    //vector<animals> of 10 best animals (highest scores)
};

#endif // MATCHMAKING_H
