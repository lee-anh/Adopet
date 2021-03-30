#include "adopter.h"

//constructor
Adopter::Adopter()
{
    username = "null";
    password = "null";
    firstName = "null";
    lastName = "null";
    emailAddress = "null";
    zipcode = -1;
    preferenceList = new Preferences();
}

//destructor
Adopter::~Adopter(){
    delete preferenceList;
}


string Adopter::getUsername(){
    return username;
}

void Adopter::setUsername(string uName){
    username = uName;
}

string Adopter::getPassword(){
    return password;
}

void Adopter::setPassword(string pwd){
    password = pwd;
}

string Adopter::getFirstName(){
    return firstName;
}

void Adopter::setFirstName(string fName){
    firstName = fName;
}

string Adopter::getLastName(){
    return lastName;
}

void Adopter::setLastName(string lName){
    lastName = lName;
}

string Adopter::getEmailAddress(){
    return emailAddress;
}

void Adopter::setEmailAddress(string email){
    emailAddress = email;
}

int Adopter::getZipCode(){
    return zipcode;
}

void Adopter::setZipCode(int zip){
    zipcode = zip;
}
