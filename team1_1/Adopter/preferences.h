#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*!
 * \brief The Preferences class contains a potential adopter's preferences
 */
class Preferences
{
public:
    /*!
     * \brief Preferences constructor
     */
    Preferences();
    /*!
     * \brief Preferences destructor
     */
    ~Preferences();

    //Species

    /*!
     * \brief getSpecies
     * \return the species vector
     */
    vector<string> getSpecies();

    /*!
     * \brief addSpecies
     * \param s species to add
     */
    void addSpecies(string s);

    /*!
     * \brief removeSpecies
     * \param s species to remove
     * \return a bool
     */
    bool removeSpecies(string s);


    //Breed
    /*!
     * \brief getBreed
     * \return  the breed vector
     */
    vector<string> getBreed();

    /*!
     * \brief addBreed
     * \param b breed to add
     */
    void addBreed(string b);

    /*!
     * \brief removeBreed
     * \param b breed to remove
     * \return a bool
     */
    bool removeBreed(string b);

    //Age
    /*!
     * \brief getAge
     * \return the age vector
     */
    vector<string> getAge();

    /*!
     * \brief addAge
     * \param a age to add
     */
    void addAge(string a);

    /*!
     * \brief removeAge
     * \param a age to remove
     * \return a bool
     */
    bool removeAge(string a);

    //Size
    /*!
     * \brief getSize
     * \return the size vector
     */
    vector<string> getSize();

    /*!
     * \brief addSize
     * \param sz size to add
     */
    void addSize(string sz);

    /*!
     * \brief removeSize
     * \param sz size to remove
     * \return a bool
     */
    bool removeSize(string sz);

    //Temperament
    /*!
     * \brief getTemperament
     * \return the temperament vector
     */
    vector<string> getTemperament();

    /*!
     * \brief addTemperament
     * \param temper temperament to add
     */
    void addTemperament(string temper);

    /*!
     * \brief removeTemperament
     * \param temper
     * \return a bool
     */
    bool removeTemperament(string temper);


    //Gender
    /*!
     * \brief getGender
     * \return the gender in a string
     */
    vector<string> getGender();

    void addGender(string gw);
    bool removeGender(string gw);

    vector<string> getGoodWith();
    void addGoodWith(string gw);
    bool removeGoodWith(string gw);

    vector<string> getShelter();
    void addShelter(string s);
    bool removeShelter(string s);

private:

    //vectors to store preference info
    vector<string> species;
    vector<string> breed;
    vector<string> age;
    vector<string> animalSize;
    vector<string> temperament;
    vector<string> gender;
    vector<string> goodWith;
    vector<string> shelter;
};

#endif //PREFERENCES_H
