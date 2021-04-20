#include "authentication.h"
#include <iostream>
#include <QString>

using namespace std;

Authentication::Authentication()
{
    cout << "default constructor called (auth)" << endl;
}
Authentication::Authentication(string dbfilepath)
{
    dbName = dbfilepath;
    openDB();
    authOwner = Owner();
    authAdopter = Adopter();

}

Authentication::~Authentication(){

    db.close();
}

/*!
 * \brief Authentication::logIn
 * \param username
 * \param password
 * \return -1 if no user was found, 0 if the user is an adopter, 1 if user is an owner
 */
int Authentication::logIn(string username, string password){
    int toReturn = -1;


    if(db.open()){
        cout << "Database opened (auth)" << endl;
        QSqlQuery qry = QSqlQuery(db);
        string s = "SELECT EXISTS(SELECT 1 FROM accounts WHERE username = \"" + username + "\" AND password = \"" + password + "\")";
        QString qs = QString::fromStdString(s);
        qry.exec(qs);
        while(qry.next()){
            if (qry.value(0).toInt() == 1){
                toReturn = 2;
            } else if(qry.value(0).toInt()== 0){
                toReturn = -1;
            } else {
                toReturn = 3;
            }
        }
   }


    //load the object if the right account was found
    if(toReturn == 2){
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
            toReturn = 0;
            loadAdopterFromDB(username, password);
            cout << "adopter" << endl;
        } else if (userType == "owner"){
            loadOwnerFromDB(username);
            toReturn = 1;
            cout << "owner" << endl;
        }

    }


    return toReturn;
}

bool Authentication::checkUsername(string username){

    if(db.open()){
        cout << "ping" << endl;
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



bool Authentication::signUp(string username, string password, string accountType){
    if(checkUsername(username) == true){
        std::cerr << "Account already exists" << endl;
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



void Authentication::loadAdopterFromDB(string username, string password){

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


        createAdopter(username, password, fname, lname, email, zip);

    }

}

Adopter Authentication::createAdopter(string username, string pwd, string fname, string lname, string emailAdd, int zip){
    //create adopter object
    Preferences pref = Preferences();//TODO: INCORPORATE SHAKH'S PREFERENCE CHANGES
    Adopter newAdptr =  Adopter(username, pwd, fname, lname, emailAdd, zip, pref);
    authAdopter = newAdptr;

    return newAdptr;
}

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
Adopter Authentication::getAuthenticatedAdopter(){
    return authAdopter;
    /*
    if(authAdopter){
        return authAdopter;
    }
    cerr << "No authenticated adopter" << endl;
    return nullptr;
    */
}

Adopter Authentication::updateAdopter(string username, string fname, string lname, string emailAdd, string zip){
    int zp = stoi(zip); //convert zip to an int
    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        QString qs = "UPDATE adopter SET username = \"" + QString::fromStdString(username) +
                "\", firstName = \"" + QString::fromStdString(fname) +
                "\", lastName = \"" + QString::fromStdString(lname) +
                "\", emailAddress = \"" + QString::fromStdString(emailAdd) +
                "\", zip = " + QString::number(zp) + ")";

        qry.exec(qs);
    }
    authAdopter.setFirstName(fname);
    authAdopter.setLastName(lname);
    authAdopter.setEmailAddress(emailAdd);
    authAdopter.setZipCode(zp);
    return authAdopter;
}



void Authentication::loadOwnerFromDB(string username){

    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        string s = "SELECT name, phoneNumber, emailAddress, ownerAddress, zip, ownerType FROM owner WHERE username = \"" + username + "\"";
        QString qs = QString::fromStdString(s);
        qry.exec(qs);

        string name = "";
        int num = 0;
        string email = "";
        string address = "";
        int zip = 0;
        string type = "";

        while(qry.next()){
            name = qry.value(0).toString().toStdString();
            num = qry.value(1).toInt();
            email = qry.value(2).toString().toStdString();
            address = qry.value(3).toString().toStdString();
            zip = qry.value(4).toInt();
            type = qry.value(5).toString().toStdString();
        }

        createOwner(type, name, address, zip, num, email);

    }

}

Owner Authentication::createOwner(string ownerType, string name, string address, int zip, int phone, string email){
    Owner o = Owner(name, ownerType, address, zip, phone, email);
    authOwner = o;
    return o;
}

void Authentication::insertOwnerToDB(string username, string name, string phone, string email, string address, string zip, string ownerType){
    int phoneNum = stoi(phone);
    int zipNum = stoi(zip);

    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        string s = "INSERT INTO owner(username, name, phoneNumber, emailAddress, ownerAddress, zip, ownerType) VALUES( \""
        + username + "\", \"" + name + "\", \"" + to_string(phoneNum) + "\", \""
        + email + "\", \"" + address + "\"," + to_string(zipNum) + ", \"" + ownerType +"\")";

        QString qs = QString::fromStdString(s);
        qry.exec(qs);

    }
}

Owner Authentication::getAuthenticatedOwner(){
    return authOwner;
}

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

