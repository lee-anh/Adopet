#ifndef MATCHMAKING_H
#define MATCHMAKING_H

#include "../Adopter/adopter.h"
//include animals
#include <vector>
#include <QtSql>

using namespace std;

class Matchmaking{
public:
    Matchmaking();
    ~Matchmaking();

    void findMatch(Preferences *p);
    void openDB();
    void showResults();
    void showResults(int amount);
    int getScore(vector <string> list, string name);
    static bool customSort(const pair<int,int> &a, const pair<int,int> &b);

private:
    vector<pair<int, int>> dbResults;
    QSqlDatabase db;

    //search the vector of pairs and get 10 best animals
    //search the database again for the 10 best animals
    //vector<animals> of 10 best animals (highest scores)
};

#endif // MATCHMAKING_H
