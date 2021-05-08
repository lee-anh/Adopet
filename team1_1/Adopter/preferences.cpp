#include "preferences.h"

/*!
 * \brief Preferences constructor
 */
Preferences::Preferences()
{
    species = vector<string>();
    breed = vector<string>();
    age = vector<string>();
    animalSize = vector<string>();
    temperament = vector<string>();
    gender = vector<string>();
}

/*!
 * \brief Preferences destructor
 */
Preferences::~Preferences(){

}

//Species
/*!
 * \brief getSpecies
 * \return the species vector
 */
vector<string> Preferences::getSpecies(){
    return species;
}

/*!
 * \brief addSpecies
 * \param s species to add
 */
void Preferences::addSpecies(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    species.push_back(s);
}

/*!
 * \brief removeSpecies
 * \param s species to remove
 * \return true if species was removed sucessfully, false if not
 */
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
/*!
 * \brief getBreed
 * \return  the breed vector
 */
vector<string> Preferences::getBreed(){
    return breed;
}

/*!
 * \brief addBreed
 * \param b breed to add
 */
void Preferences::addBreed(string b){
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    breed.push_back(b);
}

/*!
 * \brief removeBreed
 * \param b breed to remove
 * \return true if breed was removed sucessfully, false if not
 */
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
/*!
 * \brief getAge
 * \return the age vector
 */
vector<string> Preferences::getAge(){
    return age;
}

/*!
 * \brief addAge
 * \param a age to add
 */
void Preferences::addAge(string a){
    age.push_back(a);
}

/*!
 * \brief removeAge
 * \param a age to remove
 * \return true if age was removed sucessfully, false if not
 */
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
/*!
 * \brief getSize
 * \return  the size vector
 */
vector<string> Preferences::getSize(){
    return animalSize;
}

/*!
 * \brief addSize
 * \param s size to add
 */
void Preferences::addSize(string sz){
    animalSize.push_back(sz);

}

/*!
 * \brief removeSize
 * \param s size to remove
 * \return true if size was removed sucessfully, false if not
 */
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
/*!
 * \brief getTemperament
 * \return the temperament vector
 */
vector<string> Preferences::getTemperament(){
    return temperament;
}

/*!
 * \brief addTemperament
 * \param temper temperament to add
 */
void Preferences::addTemperament(string temper){
    transform(temper.begin(), temper.end(), temper.begin(), ::tolower);
    temperament.push_back(temper);

}

/*!
 * \brief removeTemperament
 * \param temper
 * \return a bool
 */
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
/*!
 * \brief getGender
 * \return the gender in a string
 */
vector<string> Preferences::getGender(){
    return gender;
}

/*!
 * \brief setGender
 * \param g gender to add
 */
void Preferences::addGender(string gw){
    transform(gw.begin(), gw.end(), gw.begin(), ::tolower);
    gender.push_back(gw);
}

/*!
 * \brief removeGender
 * \param s gender to remove
 * \return true if gender was removed sucessfully, false if not
 */
bool Preferences::removeGender(string gw){
    int genderSize = (int) gender.size();
    for(int i = 0; i < genderSize; i++){
        if(gender.at(i) == gw){
            gender.erase(gender.begin()+i);
            return true;
        }

    }
    return false;
}

//GoodWith
/*!
 * \brief getGoodWith
 * \return  the goodWith vector
 */
vector<string> Preferences::getGoodWith(){
    return goodWith;
}

/*!
 * \brief addGoodWith
 * \param s goodWith attribute to add
 */
void Preferences::addGoodWith(string gw){
    transform(gw.begin(), gw.end(), gw.begin(), ::tolower);
    goodWith.push_back(gw);
}

/*!
 * \brief removeGoodWith
 * \param s goodWith preference to remove
 * \return true if goodWith preference was removed sucessfully, false if not
 */
bool Preferences::removeGoodWith(string gw){
    int goodWithSize = (int) goodWith.size();
    for(int i = 0; i < goodWithSize; i++){
        if(goodWith.at(i) == gw){
            goodWith.erase(goodWith.begin()+i);
            return true;
        }

    }
    return false;
}

//Shelter
/*!
 * \brief getShelter
 * \return  the shetler vector
 */
vector<string> Preferences::getShelter(){
    return shelter;
}

/*!
 * \brief addShelter
 * \param s shelter to add
 */
void Preferences::addShelter(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    shelter.push_back(s);
}

/*!
 * \brief removeShelter
 * \param s shelter to remove
 * \return true if shelter was removed sucessfully, false if not
 */
bool Preferences::removeShelter(string s){
    int shelterSize = (int) shelter.size();
    for(int i = 0; i < shelterSize; i++){
        if(shelter.at(i) == s){
            shelter.erase(shelter.begin()+i);
            return true;
        }

    }
    return false;
}
