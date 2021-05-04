#ifndef PETGALLERY_H
#define PETGALLERY_H


#include <QtSql>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <algorithm>

#include "../Pets/pet.h"

using namespace std;

/*!
 * \brief The PetGallery class creates a pet display
 * Used in classes like MyFavorites, ManualSearch, MyPets, and FindMatch
 * for easy display of pets given different QWidget objects
 */
class PetGallery
{
public:

    /*!
     * \brief PetGallery default constructor
     */
    PetGallery();




    /*!
     * \brief PetGallery constructor for my favorites and manual search
     * (Gallery view)
     * \param numPetsToDisplay
     * \param prev
     * \param next
     * \param pageLine
     * \param petNameLabels
     * \param petPhotos
     * \param petLearnMore
     * \param petSaves
     * \param petVec
     */
    PetGallery(int numPetsToDisplay, QPushButton* prev,
               QPushButton* next, QLabel* pageLine,
               vector<QLabel*> petNameLabels,
               vector<QLabel*> petPhotos, vector<QPushButton*> petLearnMore,
               vector<QPushButton*> petSaves, vector<Pet> petVec, bool b);


    /*!
     * \brief PetGallery constructor for My favorites, manual search, MyPets
     * (List views)
     * \param b
     * \param numPetsToDisplay
     * \param prev
     * \param next
     * \param pageLine
     * \param petNameLabels
     * \param petInfo
     * \param petLearnMore
     * \param petSaves
     * \param petVec
     */
    PetGallery(bool b, int numPetsToDisplay, QPushButton* prev,
               QPushButton* next, QLabel* pageLine,
               vector<QLabel*> petNameLabels,
               vector<QLabel*> petInfo,
               vector<QPushButton*> petLearnMore,
               vector<QPushButton*> petSaves, vector<Pet> petVec);


    /*!
     * \brief PetGallery constructor for matchmaking (gallery view)
     * \param numPetsToDisplay
     * \param prev
     * \param next
     * \param pageLine
     * \param petNameLabels
     * \param petPhotos
     * \param petScores
     * \param petLearnMore
     * \param petSaves
     * \param petVec
     */
    PetGallery(int numPetsToDisplay, QPushButton* prev,
               QPushButton* next, QLabel* pageLine,
               vector<QLabel*> petNameLabels, vector<QLabel*> petPhotos,
               vector<QLabel*> petScores, vector<QPushButton*> petLearnMore,
               vector<QPushButton*> petSaves, vector<pair<Pet, int>> petVec);


    /*!
     * \brief PetGallery constructor for matchmaking (list view)
     * \param b
     * \param numPetsToDisplay
     * \param prev
     * \param next
     * \param pageLine
     * \param petNameLabels
     * \param petInfo
     * \param petScores
     * \param petLearnMore
     * \param petSaves
     * \param petVec
     */
    PetGallery(bool b, int numPetsToDisplay, QPushButton* prev,
               QPushButton* next, QLabel* pageLine,
               vector<QLabel*> petNameLabels, vector<QLabel*> petInfo,
               vector<QLabel*> petScores, vector<QPushButton*> petLearnMore,
               vector<QPushButton*> petSaves, vector<pair<Pet, int>> petVec);
    /*!
     * \brief PetGallery destructor
     */
    ~PetGallery();


    /*!
     * \brief updatePetVec, updates the pets to display
     * \param p
     */
    void updatePetVec(vector<Pet> p);


    /*!
     * \brief displayPets
     * \param start
     */
    void displayPets(int start);

    /*!
     * \brief next, advances pet gallery
     */
    void next();

    /*!
     * \brief previous, goes back on pet gallery
     */
    void previous();


    /*!
     * \brief setPageNum, set a page number
     * \param p
     */
    void setPageNum(int p);

    /*!
     * \brief getPet, gets a pet object that's being displayed
     * \param pos
     * \return
     */
    Pet getPet(int pos);

    /*!
     * \brief updatePet, update a pet's info in this class's pet vector
     * \param p
     */
    void updatePet(Pet p);

    /*!
     * \brief getPetVec, get the pet vector of all the pets in the class
     * \return
     */
    vector<Pet> getPetVec();


    /*!
     * \brief clearLabels, clear all labels used in the pet display
     */
    void clearLabels();



private:

    int numToDisplay;
    QPushButton* previousButton;
    QPushButton* nextButton;

    QLabel* pageNum;
    vector<QLabel*> nameLabels;
    vector<QLabel*> picLabels;
    vector<QLabel*> scoreLabels;
    vector<QLabel*> infoLabels;

    vector<QPushButton*> previews;
    vector<QPushButton*> learnMores;
    vector <QPushButton*> saveButtons;

    vector<Pet> pets;
    vector<pair<Pet, int>> matPets;

    vector<Pet> petsToDisplay;


    int nextStartIndex;
    int displayPetsPageNumber;

    bool mode; //false if owner, true if adopter

    /*!
     * \brief matchPetsToRegPets, converts a more complex vector to a simple one
     *
     */
    void matchPetsToRegPets();





};



#endif // PETGALLERY_H
