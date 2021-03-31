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

    void findMatch(Preferences *p);
    void openDB();
    void showResults();
    void showResults(int amount);
    int getScore(vector <string> list, string name);
    static bool customSort(const pair<int,int> &a, const pair<int,int> &b);

private:
    vector<pair<Pet, int>> dbResults;
    QSqlDatabase db;
};

#endif // MATCHMAKING_H
