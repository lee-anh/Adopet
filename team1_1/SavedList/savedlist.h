#ifndef SAVEDLIST_H
#define SAVEDLIST_H

#include "../Pets/pet.h"
#include <vector>
#include <QtSql>

using namespace std;

/*!
 * \brief The SavedList class manages an adopter's saved pets
 */
class SavedList
{
public:
    /*!
     * \brief SavedList defaul constructor
     */
    SavedList();

    /*!
     * \brief SavedList alternate constructor
     * \param username
     */
    SavedList(string username);

    /*!
     * \brief SavedList database constructor
     * \param databaseFilepath
     * \param username
     */
    SavedList(string databaseFilepath, string username);


    /*!
     * \brief SavedList destructor
     */
    ~SavedList();

    /*!
     * \brief savePet adds a pet to the saved list
     * \param p
     */
    void savePet(Pet p);



    /*!
     * \brief unsavePet removes a pet from the saved list
     * \param p
     */
    void unsavePet(Pet p);




    /*!
     * \brief setUsername
     * \param username
     */
    void setUsername(string username);

    /*!
     * \brief getPetVec returns the current saved pets
     * \return
     */
    vector<Pet> getPetVec();

    /*!
     * \brief printVec prints out the current saved pets
     */
    void printVec();

    /*!
     * \brief isSavedPet checks if a certain pet is saved or not
     * \param p
     * \return
     */
    bool isSavedPet(Pet p);



private:
    vector<Pet> savedPets;
    string username;

    //DB Stuff
    string dbName;
    QSqlDatabase dbSL;

    /*!
     * \brief savePet is a helper
     * \param petID
     */
    void savePet(int petID);

    /*!
     * \brief unsavePet is a helper method
     * \param petID
     */
    void unsavePet(int petID);

    /*!
     * \brief loadList loads the saved pets form the database
     */
    void loadList();

    /*!
     * \brief openDB opens a connection to the database
     */
    void openDB();

    /*!
     * \brief closeDB clses connection to the database
     */
    void closeDB();


};

#endif // SAVEDLIST_H
