#ifndef ADOPTER_H
#define ADOPTER_H

#include <iostream>
#include <string>

#include "preferences.h"

using namespace std;

class Adopter
{
public:
    Adopter();
    ~Adopter();

    //getters and setters

    string getUsername();
    void setUsername(string uName);

    string getPassword();
    void setPassword(string pwd);

    string getFirstName();
    void setFirstName(string fName);

    string getLastName();
    void setLastName(string lName);

    string getEmailAddress();
    void setEmailAddress(string email);

    int getZipCode();
    void setZipCode(int zip);

    Preferences *preferenceList;

private:
    //instance variables
    string username;
    string password;
    string firstName;
    string lastName;
    string emailAddress;
    int zipcode;






};

#endif // ADOPTER_H
