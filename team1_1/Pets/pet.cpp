#include "pet.h"


Pet::Pet()
{
    id = -1;
    name = "";
    species = "";
    breed = "";
    age = -1;
    size ="";
    temperament = "";
    gender = "";
    goodWith = "";
    shelter = "";
    bio = "";

}

Pet::Pet(string petName, string petSpecies, string petBreed, string petAge,
         string petSize, string petTemperament, string petGender,
         string petGoodWith, string petShelter, string petBio){
    name = petName;
    species = petSpecies;
    breed = petBreed;
    age = petAge;
    size = petSize;
    temperament = petTemperament;
    gender = petGender;
    goodWith = petGoodWith;
    shelter = petShelter;
    bio = petBio;
}

Pet::Pet(int petId, string petName, string petSpecies, string petBreed,
         string petAge, string petSize, string petTemperament, string petGender,
         string petGoodWith, string petShelter, string petBio){
    id = petId;
    name = petName;
    species = petSpecies;
    breed = petBreed;
    age = petAge;
    size = petSize;
    temperament = petTemperament;
    gender = petGender;
    goodWith = petGoodWith;
    shelter = petShelter;
    bio = petBio;
}

Pet::~Pet(){
    //temperament.clear();
}

//getters and setters
int Pet::getID(){
    return id;
}

void Pet::setID(int petID){
    id = petID;
}

string Pet::getName(){
    return name;
}

void Pet::setName(string n){
    name = n;
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

string Pet::getAge(){
    return age;
}

void Pet::setAge(string a){
    age = a;
}

string Pet::getSize(){
    return size;
}

void Pet::setSize(string sz){
    size = sz;
}

string Pet::getTemperament(){
    return temperament;
}

void Pet::setTemperament(string t){
    temperament = t;
}


string Pet::getGender(){
    return gender;
}

void Pet::setGender(string g){
    gender = g;
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


int Pet::getPetID(){
    return id;
}

void Pet::setPetID(int id){
    this->id = id;
}
