#include "preferences.h"

preferences::preferences()
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

preferences::~preferences(){

}

//Species
vector<string> preferences::getSpecies(){
    return species;
}

void preferences::addSpecies(string s){
    species.push_back(s);
}

bool preferences::removeSpecies(string s){
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
vector<string> preferences::getBreed(){
    return breed;
}

void preferences::addBreed(string b){
    breed.push_back(b);
}

bool preferences::removeBreed(string b){
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
vector<string> preferences::getAge(){
    return age;
}

void preferences::addAge(string a){
    age.push_back(a);
}

bool preferences::removeAge(string a){
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
vector<string> preferences::getSize(){
    return animalSize;
}

void preferences::addSize(string sz){
    animalSize.push_back(sz);

}

bool preferences::removeSize(string sz){
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
vector<string> preferences::getTemperament(){
    return temperament;
}

void preferences::addTemperament(string temper){
    temperament.push_back(temper);

}

bool preferences::removeTemperament(string temper){
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
string preferences::getGender(){
    return gender;
}

void preferences::setGender(string g){
    gender = g;
}








