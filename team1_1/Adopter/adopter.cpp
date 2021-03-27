#include "adopter.h"

//constructor
adopter::adopter()
{
    username = "null";
    password = "null";
    firstName = "null";
    lastName = "null";
    emailAddress = "null";
    zipcode = -1;
}

//destructor
adopter::~adopter(){

}


string adopter::getUsername(){
    return username;
}

void adopter::setUsername(string uName){
    username = uName;
}

string adopter::getFirstName(){
    return firstName;
}

void adopter::setFirstName(string fName){
    firstName = fName;
}

string adopter::getLastName(){
    return lastName;
}

void adopter::setLastName(string lName){
    lastName = lName;
}

string adopter::getEmailAddress(){
    return emailAddress;
}

void adopter::setEmailAddress(string email){
    emailAddress = email;
}

int adopter::getZipCode(){
    return zipcode;
}

void adopter::setZipCode(int zip){
    zipcode = zip;
}
