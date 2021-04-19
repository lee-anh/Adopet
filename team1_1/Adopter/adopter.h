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

    void addPreference(string attr, string attrType);           //adds a specific preference onto the adopter's preference list
    void fillPreferences();             //fills the adopter's preference list by accessing the DB
    void getPreferences();              //accessor method for adopter's preference list


private:
    //instance variables
    string username;
    string password;
    string firstName;
    string lastName;
    string emailAddress;
    int zipcode;

    Preferences preferenceList;
};

#endif // ADOPTER_H
