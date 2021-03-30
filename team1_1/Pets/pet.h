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
    ~Pet();

    //getters and setters
    string getName();
    void setName(string n);

    int getAge();
    void setAge(int a);

    string getType();
    void setType(string t);

    string getBreed();
    void setBreed(string b);

    string getGender();
    void setGender(string g);

    //Will need to add more methods to manipulate temperament
    vector<string> getTemperament();
    void addTemperament(string n);

private:
    string name;
    int age;
    string type;
    string breed;
    string gender;
    vector<string> temperament;

};

#endif // PET_H
