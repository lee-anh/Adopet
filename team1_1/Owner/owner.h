#ifndef OWNER_H
#define OWNER_H

#include <string>
#include <vector>
#include <QtSql>
#include <iostream>

#include "../Pets/pet.h"

//include animal/pets

using namespace std;

class Owner{

public:
    Owner();
    Owner(string t);
    Owner(string n, string oT, string a, int zip, int pN, string e);

    string getOwnerType();          //Accessor function for owner type
    void setName(string n);         //Mutator function for name
    string getName();               //Accessor function for name
    void setAddress(string a);      //Mutator function for address
    string getAddress();            //Accessor function for address
    void setZipCode(int z);         //Mutator function for zip code
    int getZipCode();               //Accessor function for zip code
    void setPhoneNumber(int p);     //Mutator function for phone number
    int getPhoneNumber();           //Accessor function for phone number
    void setEmail(string e);        //Mutator function for email
    string getEmail();              //Accessor function for email
    Pet makePet(QSqlQuery query);   //makes and retrieves a Pet by passing the query in a DB. Takes in a query
    Pet makePet(QStringList petData);   //makes and retrieves a Pet by passing the query in a DB. Takes in a string list
    void fillPets();                //reads the database and retrieves the pets of the owner
    vector<Pet> getPets();          //Accessor function for pets

    void uploadPet(Pet p);          //uploads a Pet into the database one at a time
    void uploadPets();    //Reads animals from a txt file and fills up the vector

    int getLastPetID();         //loops through the pets database and gets the last pet id


private:
    string ownerType;                    //Either "Shelter Owner" or "Foster Parent"
    string name;
    string address;
    int zipCode;
    int phoneNumber;
    string email;

    vector<Pet> pets;                  //stores the pets of the owner
    int lastPetID;
};

#endif // OWNER_H
