#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <string>
#include <QtSql>
#include <QString>
#include "../Adopter/adopter.h"
#include "../Adopter/preferences.h"
#include "../Owner/owner.h"
#include "../Pets/pet.h"

using namespace std;

class Authentication
{
public:
    /*!
     * \brief Authentication default constructor
     */
    Authentication();

    /*!
     * \brief Authentication main constructor
     * \param dbfilepath
     */
    Authentication(string dbfilepath);


    /*!
     * \brief Authentication destructor
     */
    ~Authentication();

    /*!
     * \brief logIn, method to login to the system
     * \param username
     * \param password
     * \return
     */
    int logIn(string username, string password);

    /*!
     * \brief signUp, method to sign up
     * \param username
     * \param password
     * \param accountType
     * \return
     */
    bool signUp(string username, string password, string accountType);

    /*!
     * \brief loadAdopterFromDB, loads an adopter from the database
     * \param username
     * \param password
     */
    void loadAdopterFromDB(string username, string password);

    /*!
     * \brief createAdopter creates an adopter object
     * \param username
     * \param pwd
     * \param fname
     * \param lname
     * \param emailAdd
     * \param zip
     * \return
     */
    Adopter* createAdopter(string username, string pwd, string fname, string lname, string emailAdd, int zip);

    /*!
     * \brief insertAdopterToDB, inserted an adopter to the database
     * \param username
     * \param fname
     * \param lname
     * \param emailAdd
     * \param zip
     */
    void insertAdopterToDB(string username, string fname, string lname, string emailAdd, string zip);

    /*!
     * \brief getAuthenticatedAdopter, returns the current adopter object
     * \return
     */
    Adopter* getAuthenticatedAdopter();

    /*!
     * \brief updateAdopter updates the adopter's info
     * \param username
     * \param fname
     * \param lname
     * \param emailAdd
     * \param zip
     * \return
     */
    Adopter updateAdopter(string username, string fname, string lname, string emailAdd, string zip);

    /*!
     * \brief loadOwnerFromDB, loads an owner from the database
     * \param username
     */
    void loadOwnerFromDB(string username);

    /*!
     * \brief createOwner, creates and Owner object
     * \param name
     * \param address
     * \param zip
     * \param phone
     * \param email
     * \return
     */
    Owner* createOwner( string name, string address, int zip, long phone, string email);

    /*!
     * \brief insertOwnerToDB, inserts owner to DB
     * \param username
     * \param name
     * \param phone
     * \param email
     * \param address
     * \param zip
     */
    bool insertOwnerToDB(string username, string name, string phone, string email, string address, string zip);

    /*!
     * \brief getAuthenticatedOwner, get the current owner object
     * \return
     */
    Owner* getAuthenticatedOwner();

    /*!
     * \brief updateOnwer
     * \param username
     * \param name
     * \param phone
     * \param email
     * \param address
     * \param zip
     * \param ownerType
     * \return
     */
    Owner updateOwner(string username, string name, string phone, string email, string address, string zip);


private:
    //db stuff
    QSqlDatabase db;

    /*!
     * \brief openDB, opens a connection to the database
     */
    void openDB();
    string dbName;

    /*!
     * \brief checkUsername, checks that a username is unique
     * \param username
     * \return
     */
    bool checkUsername(string username);

    /*!
     * \brief checkShelterName, checks that a shelter name is unique
     * \param shelterName
     * \return
     */
    bool checkShelterName(string shelterName);

    Adopter *authAdopter;
    Owner *authOwner;



};

#endif // AUTHENTICATION_H
