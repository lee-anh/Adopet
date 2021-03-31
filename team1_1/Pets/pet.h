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
    Pet(string n, int a, string s, string b, string g, string t);
    ~Pet();

    //getters and setters
    string getName();
    void setName(string n);

    int getAge();
    void setAge(int a);

    string getSpecies();
    void setSpecies(string sp);

    string getBreed();
    void setBreed(string b);

    string getGender();
    void setGender(string g);

    //Will need to add more methods to manipulate temperament
    string getTemperament();
    void setTemperament(string t);

private:
    string name;
    int age;
    string species;
    string breed;
    string gender;
    string temperament;

};

#endif // PET_H
