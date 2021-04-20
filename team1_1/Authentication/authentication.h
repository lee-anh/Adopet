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
    Authentication();
    Authentication(string dbfilepath);
    ~Authentication();

    int logIn(string username, string password);
    bool signUp(string username, string password, string accountType);

    void loadAdopterFromDB(string username, string password);
    Adopter createAdopter(string username, string pwd, string fname, string lname, string emailAdd, int zip);
    void insertAdopterToDB(string username, string fname, string lname, string emailAdd, string zip);
    Adopter getAuthenticatedAdopter();
    Adopter updateAdopter(string username, string fname, string lname, string emailAdd, string zip);


    void loadOwnerFromDB(string username);
    Owner createOwner(string ownerType, string name, string address, int zip, int phone, string email);
    void insertOwnerToDB(string username, string name, string phone, string email, string address, string zip, string ownerType);
    Owner getAuthenticatedOwner();
    Owner updateOnwer(string username, string name, string phone, string email, string address, string zip, string ownerType);


       bool checkUsername(string username);
private:
    //db stuff
    QSqlDatabase db;
    void openDB();
    string dbName;



    Adopter authAdopter;
    Owner authOwner;


};

#endif // AUTHENTICATION_H
