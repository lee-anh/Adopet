#include "owner.h"

Owner::Owner(string t){
    if(t == "Shelter Owner" || t == "Foster Parent") type = t;
    else type = "";
}

/*
 * Gets the type of the owner
 * @return The type of the owner
*/
string Owner::getType(){
    return type;
}

/*
 * Sets the name of the owner
 * @param n The name of the owner
*/
void Owner::setName(string n){
    name = n;
}

/*
 * Gets the name of the owner
 * @return The name of the owner
*/
string Owner::getName(){
    return name;
}

/*
 * Sets the address of the owner
 * @param a The address of the owner
*/
void Owner::setAddress(string a){
    address = a;
}

/*
 * Gets the address of the owner
 * @return The address of the owner
*/
string Owner::getAddress(){
    return address;
}

/*
 * Sets the zip code of the owner
 * @param z The zip code of the owner
*/
void Owner::setZipCode(int z){
    zipCode = z;
}

/*
 * Gets the zip code of the owner
 * @return The zip code of the owner
*/
int Owner::getZipCode(){
    return zipCode;
}

/*
 * Sets the phone number of the owner
 * @param p The phone number of the owner
*/
void Owner::setPhoneNumber(int p){
    phoneNumber = p;
}

/*
 * Gets the phone number of the owner, for contact information
 * @return The phone number of the owner
*/
int Owner::getPhoneNumber(){
    return phoneNumber;
}

/*
 * Sets the email of the owner
 * @param e The email of the owner
*/
void Owner::setEmail(string e){
    email = e;
}

/*
 * Gets the email of the owner, for contact information
 * @return The email of the owner
*/
string Owner::getEmail(){
    return email;
}
