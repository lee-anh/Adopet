#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <string>
#include <QtSql>
#include <QString>

using namespace std;

class Authentication
{
public:
    Authentication();
    ~Authentication();

    bool logIn(string username, string password);
    int signUp(string username, string password, string accountType);
    void createAdopter();
    void createShelter();
private:
    void openDB();
    QSqlDatabase db;
};

#endif // AUTHENTICATION_H
