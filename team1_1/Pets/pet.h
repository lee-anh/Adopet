#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pet
{
public:
    Pet();
    Pet(string petName, string petSpecies, string petBreed, string petAge,
        string petSize, string petTemperament, string petGender,
        string petGoodWith, string petShelter, string petBio);
    Pet(int petId, string petName, string petSpecies, string petBreed,
        string petAge, string petSize, string petTemperament, string petGender,
        string petGoodWith, string petShelter, string petBio);
    ~Pet();

    //getters and setters

    int getID();
    void setID(int petID);

    string getName();
    void setName(string n);

    string getSpecies();
    void setSpecies(string sp);

    string getBreed();
    void setBreed(string b);

    string getAge();
    void setAge(string a);

    string getSize();
    void setSize(string sz);

    string getTemperament();
    void setTemperament(string t);

    string getGender();
    void setGender(string g);

    string getGoodWith();
    void setGoodWith(string gw);

    string getShelter();
    void setShelter(string sh);

    string getBio();
    void setBio(string bi);


    int getPetID();
    void setPetID(int id);

private:
    int id;
    string name;
    string species;
    string breed;
    string age;
    string size;
    string temperament;
    string gender;
    string goodWith;
    string shelter;
    string bio;
};

#endif // PET_H
