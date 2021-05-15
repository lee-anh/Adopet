#ifndef DBSEARCH_H
#define DBSEARCH_H

#include <iostream>
#include <vector>
#include <QtSql>
#include <algorithm>
#include <random>
#include <chrono>
#include "../Pets/pet.h"



using namespace std;

/*!
 * \brief The DBSearch class provides backend support for manual searching
 */
class DBSearch
{
public:
    /*!
     * \brief DBSearch default constructor
     */
    DBSearch();

    /*!
     * \brief DBSearch main constructor
     * \param dbFilepath
     */
    DBSearch(string dbFilepath);

    /*!
     * \brief DBSearch experimental constructor
     * \param d
     */
    DBSearch(QSqlDatabase d);

    /*!
     * \brief DBSearch destructor
     */
    ~DBSearch();



    //Step 1: edit constraints vector

    /*!
     * \brief search
     * \param s
     */
    void search(string s);

    /*!
     * \brief addToAttributes
     * \param attribute
     * \param category
     * \return
     */
    bool addToAttributes(string attribute, string category);

    /*!
     * \brief removeFromAttributes
     * \param attribute
     * \param category
     * \return
     */
    bool removeFromAttributes(string attribute, string category);

    //Step 2: run the query
    /*!
     * \brief runNewQuery
     * \return
     */
    int runNewQuery(bool dist);

    /*!
     * \brief createQuery, helper method to runNewQuery()
     * \return
     */
    string createQuery();

    /*!
     * \brief queryDB, helper method to runNewQuery()
     * \param qry
     * \return
     */
    int queryDB(string qry);

    /*!
     * \brief getPetVec
     * \return
     */
    vector<Pet> getPetVec();

    /*!
     * \brief getPetVecSize
     * \return
     */
    int getPetVecSize();

    /*!
     * \brief printMatchingVec
     */
    void printMatchingVec();

    /*!
     * \brief randomShuffle the matchingPets
     */
    void randomShuffle(bool dist);
    /*!
     * \brief getConstraints, accessor method for constrains
     * \return
     */
    string getConstraints();






private:
    //database stuff
    string filepath;
    bool distance;
    /*!
     * \brief openDB
     */
    void openDB();
    QSqlDatabase dbSearchdb;

    /*!
     * \brief fillVecsFromDB
     */
    void fillVecsFromDB();
    /*!
     * \brief fillStaticVecs
     */
    void fillStaticVecs();



    /*!
     * \brief getIndex, helper method to add/remove attributes
     * \param category
     * \return
     */
    int getIndex(string category);


    vector<string> parseFile();
    vector<string> zips;


    //vectors of keywords
    vector<string> mainSpecies; //from DB
    vector<string> mainBreeds; //from DB
    vector<string> mainAges; //static
    vector<string> mainSizes; //static
    vector<string> mainTemperaments; //from DB
    vector<string> mainGenders; //static
    vector<string> mainGoodWith; //from DB
    vector<string> mainShelters; //from DB
    vector<string> names;


    vector<string> attributes;
    vector<vector<string>> constraints;
    vector<Pet> matchingPets;




};

#endif // DBSEARCH_H
