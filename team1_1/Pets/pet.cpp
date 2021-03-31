#include "pet.h"


Pet::Pet()
{
    name = "";
    age = -1;
    species = "";
    breed = "";
    gender = "";
    string temperament;
}

Pet::Pet(string n, int a, string s, string b, string g, string t){
    name = n;
    age = a;
    species = s;
    breed = b;
    gender = g;
    t = temperament;
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

int Pet::getAge(){
    return age;
}

void Pet::setAge(int a){
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
