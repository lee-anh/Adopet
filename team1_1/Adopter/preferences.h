#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class preferences
{
public:
    preferences();
    ~preferences();

    //could be multiple types
    //could be all except
    vector<string> getSpecies();
    void addSpecies(string s);
    bool removeSpecies(string s);

    //could be multiple types
    //could be all except
    vector<string> getBreed();
    void addBreed(string b);
    bool removeBreed(string b);

    //could be multiple types/all excepts
    vector<string> getAge();
    void addAge(string a);
    bool removeAge(string a);

    //could be multiple types/all excepts
    vector<string> getSize();
    void addSize(string sz);
    bool removeSize(string sz);

    //temperament
    vector<string> getTemperament();
    void addTemperament(string temper);
    bool removeTemperament(string temper);


    //limited to one or all
    string getGender();
    void setGender(string g);




private:

    //instance variables
    vector<string> species;
    vector<string> breed;
    vector<string> age;
    vector<string> animalSize;
    vector<string> temperament;
    string gender;



    //optional?
    string goodWith;


};

#endif // PREFERENCES_H
