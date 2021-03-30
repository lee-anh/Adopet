#ifndef OWNER_H
#define OWNER_H

#include <string>
#include <vector>
#include <iostream>

//include animal/pets

using namespace std;

class Owner{

public:
    Owner(string t);
    string getType();               //Accessor function for type
    void setName(string n);         //Mutator function for name
    string getName();               //Accessor function for name
    void setAddress(string a);      //Mutator function for address
    string getAddress();            //Accessor function for address
    void setZipCode(int z);             //Mutator function for zip code
    int getZipCode();                   //Accessor function for zip code
    void setPhoneNumber(int p);     //Mutator function for phone number
    int getPhoneNumber();           //Accessor function for phone number
    void setEmail(string e);        //Mutator function for email
    string getEmail();              //Accessor function for email

    //void setAnimals(txt file);    //Reads animals from a txt file and fills up the vector
    //___ getAnimals();

private:
    string type;                    //Either "Shelter Owner" or "Foster Parent"
    string name;
    string address;
    int zipCode;
    int phoneNumber;
    string email;

    //vector <Animal/Pet> animals;

};

#endif // OWNER_H
