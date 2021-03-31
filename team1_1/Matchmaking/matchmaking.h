#ifndef MATCHMAKING_H
#define MATCHMAKING_H

#include "../Adopter/adopter.h"
#include "../Pets/pet.h"
#include <vector>
#include <QtSql>

using namespace std;

class Matchmaking{
public:
    Matchmaking();
    ~Matchmaking();

    void findMatch(Preferences *p);                     //finds the matching pets based on user preference
    void openDB();                                      //opens the database before performing actions
    void showResults();                                 //prints out the list of matching pets based on score
    void showResults(int amount);
    int getScore(vector <string> list, string name);    //checks the passed list if it contains what the user wanted
    static bool customSort(const pair<int,int> &a, const pair<int,int> &b);     //sorts the result list based on score

private:
    vector<pair<Pet*, int>> dbResults;
    QSqlDatabase db;
};

#endif // MATCHMAKING_H
