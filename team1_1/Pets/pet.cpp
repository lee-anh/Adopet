#include "pet.h"


Pet::Pet()
{
    name = "";
    age = -1;
    species = "";
    breed = "";
    gender = "";
    temperament = "";

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
