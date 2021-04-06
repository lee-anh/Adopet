#include "pet.h"


Pet::Pet()
{
    name = "";
    size = "";
    age = "";
    species = "";
    breed = "";
    gender = "";
    temperament = "";
    this->bio = "";
    goodWith = "";
    shelter = "";
}

Pet::Pet(string n, string s, string b, string a, string sz, string t, string gd, string gw, string sh, string bio){
    name = n;
    size = sz;
    age = a;
    species = s;
    breed = b;
    gender = gd;
    temperament = t;
    this->bio = bio;
    goodWith = gw;
    shelter = sh;
}

Pet::~Pet(){
    temperament.clear();
}

//getters and setters
string Pet::getName(){
    return name;
}

void Pet::setName(string n){
    name = n;
}

string Pet::getAge(){
    return age;
}

void Pet::setAge(string a){
    age = a;
}

string Pet::getSpecies(){
    return species;
}

void Pet::setSpecies(string sp){
    species = sp;
}

string Pet::getBreed(){
    return breed;
}

void Pet::setBreed(string b){
    breed = b;
}

string Pet::getGender(){
    return gender;
}

void Pet::setGender(string g){
    gender = g;
}

//Will need to add more methods to manipulate temperament
string Pet::getTemperament(){
    return temperament;
}

void Pet::setTemperament(string t){
    temperament = t;
}

string Pet::getGoodWith(){
    return goodWith;
}
void Pet::setGoodWith(string gw){
    goodWith = gw;
}

string Pet::getShelter(){
    return shelter;
}

void Pet::setShelter(string sh){
    shelter = sh;
}

string Pet::getBio(){
    return bio;
}

void Pet::setBio(string bi){
    bio = bi;
}

string Pet::getSize(){
    return size;
}

void Pet::setSize(string sz){
    size = sz;
}

int Pet::getPetID(){
    return id;
}

void Pet::setPetID(int id){
    this->id = id;
}
