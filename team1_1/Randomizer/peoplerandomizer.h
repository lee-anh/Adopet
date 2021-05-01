#ifndef PEOPLERANDOMIZER_H
#define PEOPLERANDOMIZER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <QtSql>
#include <algorithm>
#include <time.h>
using namespace std;

/*!
 * \brief The PeopleRandomizer class outputs a csv of dummy adopters
 */
class PeopleRandomizer
{
public:

    /*!
     * \brief PeopleRandomizer default constructor
     */
    PeopleRandomizer();

    /*!
     * \brief PeopleRandomizer main constructor
     * \param num
     */
    PeopleRandomizer(int num);

    /*!
     * \brief PeopleRandomizer destructor
     */
    ~PeopleRandomizer();

    /*!
     * \brief writeToCSV, write generated info to a csv
     */
    void writeToCSV();




private:
    int numOfPeople;
    //CSV File stuff
    ofstream csv1;
    ofstream csv2;
    ofstream csv3;


    //Database stuff
    QSqlDatabase db;
    /*!
     * \brief openDB opens a connection to the database
     */
    void openDB();

    /*!
     * \brief loadDBVecs load tag info frm database
     */
    void loadDBVecs();

    /*!
     * \brief initalizeNameVecs choose names for the users
     */
    void initalizeNameVecs();





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

    int seed;




};

#endif // PEOPLERANDOMIZER_H
