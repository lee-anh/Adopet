#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>
#include <vector>
#include <QtSql>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

using namespace std;

#include "../Owner/owner.h"
class Owner;

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

    //int getPetID();
    //void setPetID(int id);

    void fillMediaFiles(string dbName);             //loops through the DB and fills in the pet's media information

    vector<string> getImageFiles();             //accessor method for pet's image files
    void addImageFile(string file);             //adds a new file onto the pet's image file list
    void preventDupMedia();                     //prevents duplicate files from occurring

    vector<string> getVideoFiles();             //accessor method for pet's video files
    void addVideoFile(string file);             //adds a new file onto the pet's video file list

    Owner getOwner(string dbName);              //gets the pet's current owner

    //trying out zipcode stuff
    void afterRequest(QNetworkReply* reply);
    int getDistance(int zipcode1, int zipcode2);

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

    string database;
    vector<string> imageFiles;
    vector<string> videoFiles;





};

#endif // PET_H
