#include "preferences.h"

Preferences::Preferences()
{
    //default setting will be all the different pets
    //so if the array is empty, then it's all of them?
    //WILL NEED TO CHECK IF THE USER SELECTS ALL OF THEM!!! (use the size? doing dyamic?)
    species = vector<string>();
    breed = vector<string>();
    age = vector<string>();
    animalSize = vector<string>();
    temperament = vector<string>();

    gender = "all";


}

Preferences::~Preferences(){

}

//Species
vector<string> Preferences::getSpecies(){
    return species;
}

void Preferences::addSpecies(string s){
   // transform(s.begin(), s.end(), s.begin(), ::tolower);
    species.push_back(s);
}

bool Preferences::removeSpecies(string s){
    int speciesSize = (int) species.size();
    for(int i = 0; i < speciesSize; i++){
        if(species.at(i) == s){
            species.erase(species.begin()+i);
            return true;
        }

    }
    return false;
}



//Breed
vector<string> Preferences::getBreed(){
    return breed;
}

void Preferences::addBreed(string b){
    //transform(b.begin(), b.end(), b.begin(), ::tolower);
    breed.push_back(b);
}

bool Preferences::removeBreed(string b){
    int breedSize = (int) breed.size();
    for(int i = 0; i < breedSize; i++){
        if(breed.at(i) == b){
            breed.erase(breed.begin()+i);
            return true;
        }

    }
    return false;
}

//Age
vector<string> Preferences::getAge(){
    return age;
}

void Preferences::addAge(string a){
  //  transform(a.begin(), a.end(), a.begin(), ::tolower);
    age.push_back(a);
}

bool Preferences::removeAge(string a){
    int ageSize = (int) age.size();
    for(int i = 0; i < ageSize; i++){
        if(age.at(i) == a){
            age.erase(age.begin()+i);
            return true;
        }

    }
    return false;
}

//Size
vector<string> Preferences::getSize(){
    return animalSize;
}

void Preferences::addSize(string sz){
   // transform(sz.begin(), sz.end(), sz.begin(), ::tolower);
    animalSize.push_back(sz);

}

bool Preferences::removeSize(string sz){
    int animalSizeSize = (int) animalSize.size();
    for(int i = 0; i < animalSizeSize; i++){
        if(animalSize.at(i) == sz){
            animalSize.erase(animalSize.begin()+i);
            return true;
        }

    }
    return false;
}


//Temperament
vector<string> Preferences::getTemperament(){
    return temperament;
}

void Preferences::addTemperament(string temper){
  //  transform(temper.begin(), temper.end(), temper.begin(), ::tolower);
    temperament.push_back(temper);

}

bool Preferences::removeTemperament(string temper){
    int temperamentSize = (int) temperament.size();
    for(int i = 0; i < temperamentSize; i++){
        if(temperament.at(i) == temper){
            temperament.erase(temperament.begin()+i);
            return true;
        }

    }
    return false;
}


//Gender
string Preferences::getGender(){
    return gender;
}

void Preferences::setGender(string g){
    //transform(g.begin(), g.end(), g.begin(), ::tolower);
    gender = g;
}








