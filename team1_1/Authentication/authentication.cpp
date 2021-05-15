#include "authentication.h"
#include <iostream>
#include <QString>

using namespace std;


/*!
 * \brief Authentication default constructor, not recommended
 */
Authentication::Authentication()
{
    cout << "default constructor called (auth)" << endl;
}

/*!
 * \brief Authentication main constructor, recommended
 * \param dbfilepath
 */
Authentication::Authentication(string dbfilepath)
{
    //open the database
    dbName = dbfilepath;
    openDB();


    //temporary instance variable assignments
    //authOwner = Owner();
    //authAdopter = NULL;

}

/*!
 * \brief Authentication destructor, closes the database
 */
Authentication::~Authentication(){

    db.close();
}

/*!
 * \brief logIn, logs the user into the system
 * Step 1: sees if the account exists
 * Step 2: loads the object from the database
 * \param username
 * \param password
 * \return -1 if no user was found, 0 if the user is an adopter, 1 if user is an owner
 */
int Authentication::logIn(string username, string password){
    int toReturn = -1;

    //Step 1: sees if the account exists

    if(db.open()){
        cout << "Database opened (auth)" << endl;
        QSqlQuery qry = QSqlQuery(db);
        string s = "SELECT EXISTS(SELECT 1 FROM accounts WHERE username = \"" + username + "\" AND password = \"" + password + "\")";
        QString qs = QString::fromStdString(s);
        qry.exec(qs);
        while(qry.next()){
            if (qry.value(0).toInt() == 1){
                toReturn = 1;
            } else if(qry.value(0).toInt()== 0){
                toReturn = -1;
            }
        }
   }


   // Step 2: loads the object from the database
    //load the object if the right account was found
    if(toReturn == 1){
        //find the usertype
        string userType = "";
        if(db.open()){
            QSqlQuery qry = QSqlQuery(db);
            string s = "SELECT accountType FROM accounts WHERE username = \"" + username + "\"";
            QString qs = QString::fromStdString(s);
            qry.exec(qs);
            while(qry.next()){
                userType = qry.value(0).toString().toStdString();
            }
        }

        //load the right object
        if(userType == "adopter"){

            loadAdopterFromDB(username, password);
            toReturn = 0;

        } else if (userType == "owner"){
            loadOwnerFromDB(username);
            toReturn = 1;

        }

    }


    return toReturn;
}

/*!
 * \brief signUp create an account for a new user
 * \param username
 * \param password
 * \param accountType
 * \return
 */
bool Authentication::signUp(string username, string password, string accountType){
    //verify that this is a unique username
    if(checkUsername(username) == true){
        //std::cerr << "Account already exists" << endl;
        return false;
    }
    else{
        //insert the name into the databaseof accounts
        if(db.open()){
            QSqlQuery qry = QSqlQuery(db);
            string s = "INSERT INTO accounts(username, password, accountType) VALUES(\""
            + username + "\", \"" + password + "\", \""+ accountType + "\")";
            QString qs = QString::fromStdString(s);
            qry.exec(qs);
        }
    }

    return true;
}


/*!
 * \brief loadAdopterFromDB
 * Step 1: queries the database
 * Step 2: calls the createAdopter method
 * \param username
 * \param password
 */
void Authentication::loadAdopterFromDB(string username, string password){

    //Step 1: query the database
    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        string s = "SELECT firstName, lastName, emailAddress, zip FROM adopter WHERE username = \"" + username + "\"";
        QString qs = QString::fromStdString(s);
        qry.exec(qs);

        string fname = "";
        string lname = "";
        string email = "";
        int zip = 0;

        while(qry.next()){
            fname = qry.value(0).toString().toStdString();
            lname = qry.value(1).toString().toStdString();
            email = qry.value(2).toString().toStdString();
            zip = qry.value(3).toInt();
        }


        //Step 2:calls the createAdopter method

        createAdopter(username, password, fname, lname, email, zip);

    }

}


/*!
 * \brief createAdopter creates an Adopter object
 * \param username
 * \param pwd
 * \param fname
 * \param lname
 * \param emailAdd
 * \param zip
 * \return an Adopter object
 */
Adopter* Authentication::createAdopter(string username, string pwd, string fname, string lname, string emailAdd, int zip){
    //create adopter object
    Preferences pref = Preferences();
    authAdopter= new Adopter(dbName, username, pwd, fname, lname, emailAdd, zip);


    return authAdopter;
}


/*!
 * \brief insertAdopterToDB, adds a new adopter user. Should be called w/ signUp
 * \param username
 * \param fname
 * \param lname
 * \param emailAdd
 * \param zip
 */
void Authentication::insertAdopterToDB(string username, string fname, string lname, string emailAdd, string zip){

    int zp = stoi(zip); //convert zip to an int

    //Add to adopters table in database
    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        QString qs = "INSERT INTO adopter(username, firstName, lastName, emailAddress, zip) VALUES( \""
        + QString::fromStdString(username) + "\", \"" + QString::fromStdString(fname)  + "\", \"" + QString::fromStdString(lname) + "\", \"" + QString::fromStdString(emailAdd) + "\"," + QString::number(zp) + ")";
       // QString qs = QString::fromStdString(s);
        qry.exec(qs);


    }

}

/*!
 * \brief getAuthenticatedAdopter
 * \return authenticated adopter
 */
Adopter* Authentication::getAuthenticatedAdopter(){
    return authAdopter;

}

/*!
 * \brief updateAdopter updates the adopter's entry in the database
 * Step 1: update the database
 * Step 2: update local adopter object
 *
 * \param username
 * \param fname
 * \param lname
 * \param emailAdd
 * \param zip
 * \return updated Adopter object
 */
Adopter Authentication::updateAdopter(string username, string fname, string lname, string emailAdd, string zip){

    //update database
    int zp = stoi(zip); //convert zip to an int
    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        QString qs = "UPDATE adopter SET firstName = \"" + QString::fromStdString(fname) +
                "\", lastName = \"" + QString::fromStdString(lname) +
                "\", emailAddress = \"" + QString::fromStdString(emailAdd) +
                "\", zip = " + QString::number(zp) + " WHERE username = \""
                 + QString::fromStdString(username) + "\";";
        qry.exec(qs);
        cout << qs.toStdString() << endl;
    }
    //update local object
    authAdopter->setFirstName(fname);
    cout << fname << endl;
    authAdopter->setLastName(lname);
    cout << lname << endl;
    authAdopter->setEmailAddress(emailAdd);
    cout << emailAdd << endl;
    authAdopter->setZipCode(zp);
    cout << zp << endl;
    return *authAdopter;
}


/*!
 * \brief loadOwnerFromDB
 * Step 1: queries the database
 * Step 2: calls the createOwner method
 * \param username
 * \param password
 */
void Authentication::loadOwnerFromDB(string username){

    //Step 1: queries the database
    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        string s = "SELECT name, phoneNumber, emailAddress, ownerAddress, zip FROM owner WHERE username = \"" + username + "\"";
        QString qs = QString::fromStdString(s);
        qry.exec(qs);

        string name = "";
        long num = 0;
        string email = "";
        string address = "";
        int zip = 0;

        while(qry.next()){
            name = qry.value(0).toString().toStdString();
            num = qry.value(1).toLongLong();
            email = qry.value(2).toString().toStdString();
            address = qry.value(3).toString().toStdString();
            zip = qry.value(4).toInt();
        }

        //calls create owner method
        createOwner(name, address, zip, num, email);
    }

}

/*!
 * \brief createOwner creates an Owner object
 * \param ownerType
 * \param name
 * \param address
 * \param zip
 * \param phone
 * \param email
 * \return
 */
Owner* Authentication::createOwner(string name, string address, int zip, long phone, string email){
    Owner *o = new Owner(dbName, name, address, zip, phone, email);
    authOwner = o;
    return o;
}

/*!
 * \brief insertOwnerToDB, adds a new owner user. Sh\ould be called w/ signUp
 * \param username
 * \param name
 * \param phone
 * \param email
 * \param address
 * \param zip
 * \param ownerType
 */
bool Authentication::insertOwnerToDB(string username, string name, string phone, string email, string address, string zip){

    int zipNum = stoi(zip);
    if(checkShelterName(name) == true){
        return false;
    }
    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);

        string s = "INSERT INTO owner(username, name, phoneNumber, emailAddress, ownerAddress, zip) VALUES( \""
        + username + "\", \"" + name + "\", \"" + phone + "\", \""
        + email + "\", \"" + address + "\"," + to_string(zipNum) +")";
        cout << s << endl;
        QString qs = QString::fromStdString(s);
        qry.exec(qs);

    }
    return true;
}

/*!
 * \brief getAuthenticatedOwner
 * \return authenicated owner
 */
Owner* Authentication::getAuthenticatedOwner(){
    return authOwner;
}

/*!
 * \brief updateOwner updates the adopter's entry in the database
 *Step 1: update the database
 * Step 2: update local adopter object
 * \param username
 * \param name
 * \param phone
 * \param email
 * \param address
 * \param zip
 * \return
 */
Owner Authentication::updateOwner(string username, string name, string phone, string email, string address, string zip){
    int zp = stoi(zip); //convert zip to an int


    //Step 1: updaate database
    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);

        QString qs = "UPDATE owner SET name = \"" + QString::fromStdString(name) +
                "\", phoneNumber = \"" + QString::fromStdString(phone) +
                "\", emailAddress = \"" + QString::fromStdString(email) +
                "\", ownerAddress = \"" + QString::fromStdString(address) +
                "\", zip = " + QString::number(zp)
                +  " WHERE username = \"" + QString::fromStdString(username) + "\"";

        qry.exec(qs);
    }

    //Step 2: update local owner object
    //alternatively... loadOwnerFromDB(username);
        authOwner->setName(name);
        authOwner->setPhoneNumber(stol(phone));
        authOwner->setEmail(email);
        authOwner->setAddress(address);
        authOwner->setZipCode(zp);

    return *authOwner;
}

/*!
 * \brief openDB, opens a connection to the database
 */
void Authentication::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE","authConnection");
    string fullName = dbName;
    db.setDatabaseName(QString::fromStdString(fullName));
    if(!db.open()){
        std::cerr << "Database does not open -- "
                  << db.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully (from Authentication class)\n";
    }
}

/*!
 * \brief checkUsername a helper method to signUp, checks to see if a username is unique
 * \param username
 * \return true if the username already exists, false if it is unique
 */
bool Authentication::checkUsername(string username){

    if(db.open()){

        QSqlQuery qry = QSqlQuery(db);
        QString qs = "SELECT EXISTS(SELECT 1 FROM accounts WHERE username =";
        qs+= "\"" + QString::fromStdString(username) + "\"";
        qs+=");";
        qry.exec(qs);
        while(qry.next()){
            if (qry.value(0).toInt()==1){
                return true; //the username already exists
            } else if(qry.value(0).toInt() == 0){
                return false;
            }

        }
    }

    return false;
}

/*!
 * \brief checkShelterName, checks that a shelter name is unique
 * \param shelterName
 * \return true if not unique, false if unique
 */
bool Authentication::checkShelterName(string shelterName){
    if(db.open()){

        QSqlQuery qry = QSqlQuery(db);
        QString qs = "SELECT EXISTS(SELECT 1 FROM owner WHERE name =";
        qs+= "\"" + QString::fromStdString(shelterName) + "\"";
        qs+=");";
        qry.exec(qs);
        while(qry.next()){
            if (qry.value(0).toInt()==1){
                return true; //the username already exists
            } else if(qry.value(0).toInt() == 0){
                return false;
            }

        }
    }

    return false;
}

