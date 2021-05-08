#ifndef ADOPTER_H
#define ADOPTER_H

#include <iostream>
#include <string>
#include <QtSql>

#include "preferences.h"


using namespace std;

/*!
 * \brief The Adopter class represents a potential adopter's account and basic info
 */
class Adopter
{
public:
    /*!
     * \brief default Adopter constructor
     */
    Adopter();


    Adopter(string db, string uname, string pwd, string fname, string lname,
                     string email, int zip);


    /*!
     * \brief Adopter alternate constructor
     * \param uname username
     * \param pwd password
     * \param fname firstname
     * \param lname lastname
     * \param email email address
     * \param zip zipcode
     * \param p Preferences object
     */
    Adopter(string uname, string pwd, string fname, string lname,
            string email, int zip, Preferences p);



    /*!
     * \brief Adopter destructor
     */
    ~Adopter();

    //getters and setters

    /*!
     * \brief getUsername
     * \return username
     */
    string getUsername();

    /*!
     * \brief setUsername
     * \param uName username
     */
    void setUsername(string uName);

    /*!
     * \brief getPassword
     * \return password
     */
    string getPassword();

    /*!
     * \brief setPassword
     * \param pwd password
     */
    void setPassword(string pwd);

    /*!
     * \brief getFirstName
     * \return first name
     */
    string getFirstName();

    /*!
     * \brief setFirstName
     * \param fName firstname
     */
    void setFirstName(string fName);

    /*!
     * \brief getLastName
     * \return lastname
     */
    string getLastName();

    /*!
     * \brief setLastName
     * \param lName lastname
     */
    void setLastName(string lName);

    /*!
     * \brief getEmailAddress
     * \return email address
     */
    string getEmailAddress();

    /*!
     * \brief setEmailAddress
     * \param email email address
     */
    void setEmailAddress(string email);

    /*!
     * \brief getZipCode
     * \return zip code
     */
    int getZipCode();

    /*!
     * \brief setZipCode
     * \param zip code
     */
    void setZipCode(int zip);

    /*!
     * \brief fillPreference fills the passed preference
     *  onto the adopter's preference list
     * \param attr
     * \param attrType
     */
    void fillPreference(string attr, string attrType);

    /*!
     * \brief fillPreferences fills the adopter's preference list
     *  by accessing the DB
     */
    void fillPreferences();

    /*!
     * \brief removePreferenceHelper helper method
     * removes the passed preference from the adopter's preference list
     * \param attr
     * \param attrType
     */
    void removePreferenceHelper(string attr, string attrType);

    /*!
     * \brief getPreferences accessor method for adopter's preference list
     * \return
     */
    Preferences getPreferences();

    /*!
     * \brief addPreference adds a preference
     * onto the adopter's preference list and the DB
     * \param attr
     * \param attrType
     */
    void addPreference(string attr, string attrType);

    /*!
     * \brief removePreference removes a preference
     * from the adopter's preference list and the DB
     * \param attr
     * \param attrType
     */
    void removePreference(string attr, string attrType);

    /*!
     * \brief setPreference set the preference as
     * the passed preference
     * \param pf: the new preference
     */
    void setPreference(Preferences pf);


private:
    //instance variables
    string username;
    string password;
    string firstName;
    string lastName;
    string emailAddress;
    int zipcode;

    Preferences preferenceList;

    //database stuff
    /*!
     * \brief openDB, opens a connection to the database
     */
    void openDB();
    string dbName;
    QSqlDatabase prefDB;
};

#endif // ADOPTER_H
