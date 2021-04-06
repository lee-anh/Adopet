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
    Pet(string n, string s, string b, string a, string sz, string t, string gd, string gw, string sh, string bio);
    ~Pet();

    //getters and setters
    string getName();
    void setName(string n);

    string getAge();
    void setAge(string a);

    string getSpecies();
    void setSpecies(string sp);

    string getSize();
    void setSize(string sz);

    string getGoodWith();
    void setGoodWith(string gw);

    string getShelter();
    void setShelter(string sh);

    string getBio();
    void setBio(string bi);

    string getBreed();
    void setBreed(string b);

    string getGender();
    void setGender(string g);

    //Will need to add more methods to manipulate temperament
    string getTemperament();
    void setTemperament(string t);

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
