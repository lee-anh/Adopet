#include "pet.h"


Pet::Pet()
{
    name = "";
    age = -1;
    type = "";
    breed = "";
    gender = "";
    vector<string> temperament;
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

string Pet::getType(){
    return type;
}

void Pet::setType(string t){
    type = t;
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
vector<string> Pet::getTemperament(){
    return temperament;
}

void Pet::addTemperament(string temp){
    temperament.push_back(temp);
}
