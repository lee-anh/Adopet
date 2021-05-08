#include "adopter.h"


/*!
 * \brief default Adopter constructor, not recommended
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
 * \brief Adopter alternate constructor, recommended
 * \param db database filepath as a string
 * \param uname username
 * \param pwd password
 * \param fname firstname
 * \param lname lastname
 * \param email email address
 * \param zip zipcode
 * \param p Preferences object
 */
Adopter::Adopter(string db, string uname, string pwd, string fname, string lname,
                 string email, int zip){
    dbName = db;
    username = uname;
    password = pwd;
    firstName = fname;
    lastName = lname;
    emailAddress = email;
    zipcode = zip;
    preferenceList = Preferences();
    openDB();
    fillPreferences();
    cout << "Adopter database constructor called" << endl;
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
   // prefDB.removeDatabase(prefDB.connectionName());
    prefDB.close();
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

/*!
 * \brief fillPreference
 * Adds the specific preference onto the adopter's preference list
 * \param attr Preference
 * \param attrType Type of preference
 */
void Adopter::fillPreference(string attr, string attrType){
    if(attrType == "species") preferenceList.addSpecies(attr);
    else if(attrType == "breed") preferenceList.addBreed(attr);
    else if(attrType == "age") preferenceList.addAge(attr);
    else if(attrType == "size") preferenceList.addSize(attr);
    else if(attrType == "temperament") preferenceList.addTemperament(attr);
    else if(attrType == "gender") preferenceList.addGender(attr);
    else if(attrType == "goodWith") preferenceList.addGoodWith(attr);
    else if(attrType == "shelter") preferenceList.addShelter(attr);
}

/*!
 * \brief fillPreferences
 * Goes through the preferences database and fills the preference list of the current adopter
 *
 */
void Adopter::fillPreferences(){
    if(prefDB.open()){
        QSqlQuery query = QSqlQuery(prefDB);
        QString s = "SELECT adopterUsername, attribute, attributeType FROM preferences";
        query.exec(s);

        while(query.next()){
            string name = query.value(0).toString().toStdString();
            string attribute = query.value(1).toString().toStdString();
            string attributeType = query.value(2).toString().toStdString();

            if(name == username) fillPreference(attribute, attributeType);
        }
    }
}

/*!
 * \brief removePreferenceHelper
 * Helper method to remove the specific preference from the adopter's preference list
 *
 * \param attr Preference
 * \param attrType Type of preference
 */
void Adopter::removePreferenceHelper(string attr, string attrType){
    if(attrType == "species") preferenceList.removeSpecies(attr);
    else if(attrType == "breed") preferenceList.removeBreed(attr);
    else if(attrType == "age") preferenceList.removeAge(attr);
    else if(attrType == "size") preferenceList.removeSize(attr);
    else if(attrType == "temperament") preferenceList.removeTemperament(attr);
    else if(attrType == "gender") preferenceList.removeGender(attr);
    else if(attrType == "goodWith") preferenceList.removeGoodWith(attr);
    else if(attrType == "shelter") preferenceList.removeShelter(attr);
}

/*!
 * \brief getPreferences accessor method for adopter's preference list
 * \return Preference object
 */
Preferences Adopter::getPreferences(){
    return preferenceList;
}

/*!
 * \brief addPreference
 * Adds a preference onto the adopter's
 *  preference list and the preference database
 *  \param attr Preference to be added
 * \param attrType Type of preference
 */
void Adopter::addPreference(string attr, string attrType){
    QString s = "INSERT INTO preferences(adopterUsername, attribute, attributeType) VALUES(\"";
    s += QString::fromStdString(username) + "\", \"";
    s += QString::fromStdString(attr) + "\", \"";
    s += QString::fromStdString(attrType) + "\")";

    if(prefDB.open()){
        QSqlQuery query = QSqlQuery(prefDB);
        query.exec(s);
    }

    fillPreference(attr, attrType);
}

/*!
 * \brief removePreference Removes a preference from the
 * adopter's preference list and the preference database
 *
 * \param attr Preference to be removed
 * \param attrType Type of preference
 */
void Adopter::removePreference(string attr, string attrType){
    QString s = "DELETE FROM preferences WHERE (adopterUsername = ";
    s += "\"" + QString::fromStdString(username) + "\" AND attribute = ";
    s += "\"" + QString::fromStdString(attr) + "\" AND attributeType = ";
    s += "\"" + QString::fromStdString(attrType) + "\")";

    if(prefDB.open()){
        QSqlQuery query = QSqlQuery(prefDB);
        query.exec(s);
    }

    removePreferenceHelper(attr, attrType);
}

/*!
 * \brief setPreference, setter method for preference list
 * \param pf Preference object to set the current list
 */
void Adopter::setPreference(Preferences pf){
    preferenceList = pf;
}


/*!
 * \brief openDB, opens a connection to the database
 */
void Adopter::openDB(){
    prefDB = QSqlDatabase::addDatabase("QSQLITE", "adopterCxn");
    string fullName = dbName;
    prefDB.setDatabaseName(QString::fromStdString(fullName));
    if(!prefDB.open()){
        std::cerr << "Database does not open -- "
                  << prefDB.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully (from Adopter class)\n";
    }
}
