
#include "petgallery.h"


/*!
 * \brief PetGallery default constructor
 */
PetGallery::PetGallery()
{
    //default constructor, don't use
}




/*!
 * \brief PetGallery constructor for my favorites, manual search, my pets
 * (Gallery view)
 * \param numPetsToDisplay
 * \param prev, button
 * \param next, button
 * \param pageLine, label
 * \param petNameLabels, name labels
 * \param petPhotos, photo labels
 * \param petLearnMore, buttons
 * \param petSaves, buttons
 * \param petVec, pets to display
 */
PetGallery:: PetGallery(int numPetsToDisplay, QPushButton* prev,
                        QPushButton* next,  QLabel* pageLine,
                        vector<QLabel*> petNameLabels,
                        vector<QLabel*> petPhotos,
                        vector<QPushButton*> petLearnMore,
                        vector<QPushButton*> petSaves, vector<Pet> petVec, bool b){

    mode = b;
    numToDisplay = numPetsToDisplay;
    previousButton = prev;
    nextButton = next;
    pageNum = pageLine;
    nameLabels = petNameLabels;
    picLabels = petPhotos;
    learnMores = petLearnMore;
    saveButtons = petSaves;
    pets = petVec;
    nextStartIndex = 0;
    displayPetsPageNumber = 1;

    petsToDisplay = vector<Pet>();
    clearLabels();

}

/*!
 * \brief PetGallery constructor for My favorites, manual search, MyPets
 * (List views)
 * \param b, bool to differentiate the constructor
 * \param numPetsToDisplay
 * \param prev, button
 * \param next, button
 * \param pageLine, label
 * \param petNameLabels, name labels
 * \param petInfo, info labels
 * \param petLearnMore, buttons
 * \param petSaves, buttons,
 * \param petVec, pets to display
 */
PetGallery:: PetGallery(bool b, int numPetsToDisplay, QPushButton* prev,
                        QPushButton* next,  QLabel* pageLine,
                        vector<QLabel*> petNameLabels,
                        vector<QLabel*> petInfo,
                        vector<QPushButton*> petLearnMore,
                        vector<QPushButton*> petSaves, vector<Pet> petVec){

    mode = b;
    numToDisplay = numPetsToDisplay;
    previousButton = prev;
    nextButton = next;
    pageNum = pageLine;
    nameLabels = petNameLabels;
    infoLabels = petInfo;
    learnMores = petLearnMore;
    saveButtons = petSaves;
    pets = petVec;
    nextStartIndex = 0;
    displayPetsPageNumber = 1;

    petsToDisplay = vector<Pet>();
    clearLabels();

}


/*!
 * \brief PetGallery constructor for matchmaking (gallery view)
 * \param numPetsToDisplay
 * \param prev, button
 * \param next, button
 * \param pageLine, label
 * \param petNameLabels, name labels
 * \param petPhotos, photo labels
 * \param petScores, score labels
 * \param petLearnMore, buttons
 * \param petSaves, button
 * \param petVec, pets to display
 */
PetGallery::PetGallery(int numPetsToDisplay, QPushButton* prev,
                       QPushButton* next, QLabel* pageLine,
                       vector<QLabel*> petNameLabels,
                       vector<QLabel*> petPhotos,
                       vector<QLabel*> petScores,
                       vector<QPushButton*> petLearnMore,
                       vector<QPushButton*> petSaves, vector<pair<Pet, int>> petVec){
    mode = true;
    numToDisplay = numPetsToDisplay;
    previousButton = prev;
    nextButton = next;
    pageNum = pageLine;
    nameLabels = petNameLabels;
    picLabels = petPhotos;
    scoreLabels = petScores;
    learnMores = petLearnMore;
    saveButtons = petSaves;
    matPets = petVec;

    matchPetsToRegPets(); //convert vector

    nextStartIndex = 0;
    displayPetsPageNumber = 1;

    petsToDisplay = vector<Pet>();
    clearLabels();
}

/*!
 * \brief PetGallery constructor for matchmaking (list view)
 * \param b, bool to differentiate constructor
 * \param numPetsToDisplay
 * \param prev, button
 * \param next, button
 * \param pageLine, label
 * \param petNameLabels, name label
 * \param petInfo, info label
 * \param petScores, score label
 * \param petLearnMore, buttons
 * \param petSaves, buttons
 * \param petVec, pets to display
 */
PetGallery::PetGallery(bool b, int numPetsToDisplay, QPushButton* prev,
                       QPushButton* next, QLabel* pageLine,
                       vector<QLabel*> petNameLabels,
                       vector<QLabel*> petInfo,
                       vector<QLabel*> petScores,
                       vector<QPushButton*> petLearnMore,
                       vector<QPushButton*> petSaves, vector<pair<Pet, int>> petVec){
    mode = true;
    numToDisplay = numPetsToDisplay;
    previousButton = prev;
    nextButton = next;
    pageNum = pageLine;
    nameLabels = petNameLabels;
    infoLabels = petInfo;
    scoreLabels = petScores;
    learnMores = petLearnMore;
    saveButtons = petSaves;
    matPets = petVec;

    matchPetsToRegPets(); //convert vector

    nextStartIndex = 0;
    displayPetsPageNumber = 1;

    petsToDisplay = vector<Pet>();
    clearLabels();
}



/*!
 * \brief PetGallery destructor
 */
PetGallery::~PetGallery(){
}


/*!
 * \brief updatePetVec, updates the pets to display
 * \param p vector of pets to display
 */
void PetGallery::updatePetVec(vector<Pet> p){
    pets = p;
}


/*!
 * \brief displayPets, displays the pets
 * updates all the associated labels and buttons
 * \param start, starting index
 */
void PetGallery::displayPets(int start){

    int counter = 0;

    //clear petsToDisplayVector
    petsToDisplay.clear();

    //hide old buttons
    previousButton->setVisible(true);
    nextButton->setVisible(true);

    for(int i = 0; i < numToDisplay; i++){
        //clear the old labels and hide the old buttons
        nameLabels[i]->clear();
        if(picLabels.size() > 0){
         picLabels[i]->clear();
        }
        if(infoLabels.size() > 0){
            infoLabels[i]->clear();
        }

        learnMores[i]->setVisible(false);
        if(saveButtons.size() > 0){
            saveButtons[i]->setVisible(false);
        }
        if(matPets.size() > 0){
            scoreLabels[i]->clear();
        }

        //display pets
        if(start < (int) pets.size()){
            //add to petsToDisplay vec
             petsToDisplay.push_back(pets[start]);

            //name
            string s = pets[start].getName();
           // transform(s.begin(), s.end(), s.begin(), ::toupper);
            QString qpetName = QString::fromStdString(s).toUpper();
            nameLabels[i]->setText(qpetName);

            if(mode == false){
                string es = s + "  ID: " + to_string(pets[start].getID());
                QString esq = QString::fromStdString(es).toUpper();
                nameLabels[i]->setText(esq);
            }


            if(infoLabels.size() >0){
                string info = pets[start].getSpecies() + " - " + pets[start].getBreed() + " - " + pets[start].getTemperament() + " - good with " + pets[start].getGoodWith();
                infoLabels[i]->setText(QString::fromStdString(info));
            }

            if(picLabels.size() > 0){
                //picture
                if(pets[start].getImageFiles().size() == 0){
                    //default picture
                    //CHANGE HERE                   
                    QString os = QSysInfo::productVersion();
                    if(os == "10.16"){
                        QPixmap pixmap("../../../../../pictures/default.png");
                        picLabels[i]->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio));
                    } else {
                        QPixmap pixmap("../../pictures/default.png");
                        picLabels[i]->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio));
                    }
                } else {
                    QString os = QSysInfo::productVersion();
                    string photo;

                    if(os == "10.16"){
                        photo = "../../../../../pictures/" + pets[start].getImageFiles()[0];
                    } else {
                        photo = "../../pictures/" + pets[start].getImageFiles()[0];
                    }

                    QPixmap pix(QString::fromStdString(photo));
                    picLabels[i]->setPixmap(pix.scaled(150, 150, Qt::KeepAspectRatio));
                }
            }


            //learnMores
            learnMores[i]->setVisible(true);

            //saveButton (if they exist)
            if(saveButtons.size() > 0){
                saveButtons[i]->setVisible(true);

            }

            //scores (for matchmaking only)
            if(matPets.size() > 0){

                int score = matPets[start].second;
                QString m = QString::number(score) + "% match";
                scoreLabels[i]->setText(m);
            }

            start++;
            counter++;



        }
    }

    nextStartIndex = start - 1;

    int numOfPages = ceil(pets.size()/(numToDisplay*1.0));


    if(counter == 0){
        pageNum->setText("No animals match your search");
    } else {

        pageNum->setText("Showing page " +
             QString::number(displayPetsPageNumber) + " out of "
             + QString::number(numOfPages));
    }


}

/*!
 * \brief next, advances pet gallery
 */
void PetGallery::next(){
    if(nextStartIndex + 1 < (int) pets.size()){
        displayPetsPageNumber++;
        nextStartIndex++;
        displayPets(nextStartIndex);

    }

}

/*!
 * \brief previous, goes back on pet gallery
 */
void PetGallery::previous(){
    int startMod =  nextStartIndex % numToDisplay;
    if(nextStartIndex - numToDisplay < 0){
        displayPetsPageNumber = 1;
        displayPets(0);

    } else {
        nextStartIndex = nextStartIndex- numToDisplay - startMod;
        if(displayPetsPageNumber - 1 > 0)
            displayPetsPageNumber--;
        else
            displayPetsPageNumber = 1;
        displayPets(nextStartIndex);

    }
}


/*!
 * \brief setPageNum, set a page number
 * \param p, page number
 */
void PetGallery::setPageNum(int p){
    displayPetsPageNumber = p;
}


/*!
 * \brief getPet, gets a pet object that's being displayed
 * \param pos, position of pet to get
 * \return
 */
Pet PetGallery::getPet(int pos){
    return petsToDisplay[pos];
}

/*!
 * \brief updatePet, update a pet's info in this class's pet vector
 * \param p, new pet object
 */
void PetGallery::updatePet(Pet p){
    for(int i = 0; i < (int) petsToDisplay.size(); i++){
        if(petsToDisplay.at(i).getID() == p.getID()){
            petsToDisplay.at(i) = p;
        }
    }
    for(int j = 0; j < (int) pets.size(); j++){
        if(pets.at(j).getID() == p.getID()){
            pets.at(j) = p;
        }
    }
}


/*!
 * \brief getPetVec, get the pet vector of all the pets in the class
 * \return, vector of pets
 */
vector<Pet> PetGallery::getPetVec(){
    return pets;
}

/*!
 * \brief clearLabels, clear all labels used in the pet display
 */
void PetGallery::clearLabels(){
    for(int i = 0; i < numToDisplay; i++){
        nameLabels[i]->clear();

        //if there are pictures
        if(picLabels.size() >0){
            picLabels[i]->clear();
        }

        //if there are info labels
        if(infoLabels.size() > 0){
            infoLabels[i]->clear();
        }

        learnMores[i]->setVisible(false);

        //if there are save buttons
        if(saveButtons.size() > 0){
            saveButtons[i]->setVisible(false);
        }

        //if there are score labels
        if(scoreLabels.size() > 0){
            scoreLabels[i]->clear();
            pageNum->clear();
        }
    }
    previousButton->setVisible(false);
    nextButton->setVisible(false);
}


/*!
 * \brief matchPetsToRegPets, converts a more complex vector
 * to a simple vector of pets
 *
 */
void PetGallery::matchPetsToRegPets(){
    pets = vector<Pet>();
   for(int i = 0; i < (int) matPets.size(); i++){
       pets.push_back(matPets[i].first);
   }
}


