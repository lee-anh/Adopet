#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <string>
#include <QtSql>
#include <QString>
#include "../Adopter/adopter.h"
#include "../Adopter/preferences.h"

using namespace std;

class Authentication
{
public:
    Authentication();
    ~Authentication();

    bool logIn(string username, string password);
    bool signUp(string username, string password, string accountType);

    Adopter* createAdopter(string username, string password, string emailAdd, int zip);
    Adopter* getAuthenticatedAdopter();
private:
    void openDB();
    bool checkUsername(string username);
    Adopter* authAdopter;
    QSqlDatabase db;
};

#endif // AUTHENTICATION_H
