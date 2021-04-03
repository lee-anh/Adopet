#ifndef PEOPLERANDOMIZER_H
#define PEOPLERANDOMIZER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <QtSql>
#include <algorithm>

using namespace std;

class PeopleRandomizer
{
public:
    PeopleRandomizer();
    PeopleRandomizer(int num);
    ~PeopleRandomizer();

    void writeToCSV();

    void speciesTest();



private:
    int numOfPeople;
    //CSV File stuff
    ofstream csv1;
    ofstream csv2;
    ofstream csv3;


    //Database stuff
    QSqlDatabase db;
    void openDB();

    void initalizeNameVecs();
    void loadDBVecs();



    //doesn't have to be the most efficient b/c just run sometimes

    //vectors that don't change
    vector<string> firstNames;
    vector<string> lastNames;
    vector<string> age;
    vector<string> gender;
    vector<string> size;


    //read from DB
    vector<string> species;
    vector<pair<string, string>> breed;
    vector<string> temperament;
    vector<string> goodWith;
    vector<string> shelter;





};

#endif // PEOPLERANDOMIZER_H
