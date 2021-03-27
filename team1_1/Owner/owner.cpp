#include "owner.h"

Owner::Owner(string t){
    type = t;
}

void Owner::setName(string n){
    name = n;
}

string Owner::getName(){
    return name;
}

void Owner::setAddress(string a){
    address = a;
}

string Owner::getAddress(){
    return address;
}

void Owner::setZip(int z){
    zip = z;
}

int Owner::getZip(){
    return zip;
}

void Owner::setPhoneNumber(int p){
    phoneNumber = p;
}

int Owner::getPhoneNumber(){
    return phoneNumber;
}

void Owner::setEmail(string e){
    email = e;
}

string Owner::getEmail(){
    return email;
}
