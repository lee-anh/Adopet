#include "adopter.h"


/*!
 * \brief default Adopter constructor
 */
Adopter::Adopter()
{
    username = "null";
    password = "null";
    firstName = "null";
    lastName = "null";
    emailAddress = "null";
    zipcode = -1;
    preferenceList = Preferences();
}

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
Adopter::Adopter(string uname, string pwd, string fname, string lname,
                 string email, int zip, Preferences p){
    username = uname;
    password = pwd;
    firstName = fname;
    lastName = lname;
    emailAddress = email;
    zipcode = zip;
    preferenceList = p;

}

/*!
 * \brief Adopter destructor
 */
Adopter::~Adopter(){
}


/*!
 * \brief getUsername
 * \return username
 */
string Adopter::getUsername(){
    return username;
}

/*!
 * \brief setUsername
 * \param uName username
 */
void Adopter::setUsername(string uName){
    username = uName;
}

/*!
 * \brief getPassword
 * \return password
 */
string Adopter::getPassword(){
    return password;
}

/*!
 * \brief setPassword
 * \param pwd password
 */
void Adopter::setPassword(string pwd){
    password = pwd;
}

/*!
 * \brief getFirstName
 * \return first name
 */
string Adopter::getFirstName(){
    return firstName;
}

/*!
 * \brief setFirstName
 * \param fName firstname
 */
void Adopter::setFirstName(string fName){
    firstName = fName;
}

/*!
 * \brief getLastName
 * \return lastname
 */
string Adopter::getLastName(){
    return lastName;
}

/*!
 * \brief setLastName
 * \param lName lastname
 */
void Adopter::setLastName(string lName){
    lastName = lName;
}

/*!
 * \brief getEmailAddress
 * \return email address
 */
string Adopter::getEmailAddress(){
    return emailAddress;
}

/*!
 * \brief setEmailAddress
 * \param email email address
 */
void Adopter::setEmailAddress(string email){
    emailAddress = email;
}

/*!
 * \brief getZipCode
 * \return zip code
 */
int Adopter::getZipCode(){
    return zipcode;
}

/*!
 * \brief setZipCode
 * \param zip code
 */
void Adopter::setZipCode(int zip){
    zipcode = zip;
}
