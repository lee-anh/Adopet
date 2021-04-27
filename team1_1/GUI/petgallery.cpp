
#include "petgallery.h"

PetGallery::PetGallery()
{
    //default constructor, don't use
}


//constructor used in MyPets (Owner)
PetGallery:: PetGallery(int numPetsToDisplay, QPushButton* prev,
                        QPushButton* next,  QLabel* pageLine,
                        vector<QLabel*> petNameLabels,
                        vector<QLabel*> petPhotos,
                        vector<QPushButton*> petLearnMore,
                        vector<Pet> petVec){

    numToDisplay = numPetsToDisplay;
    previousButton = prev;
    nextButton = next;
    pageNum = pageLine;
    nameLabels = petNameLabels;
    picLabels = petPhotos;
    learnMores = petLearnMore;
    pets = petVec;
    nextStartIndex = 0;
    displayPetsPageNumber = 1;

    petsToDisplay = vector<Pet>();
    clearLabels();

}


//constructor used in gallery view of my favorites and manual search
PetGallery:: PetGallery(int numPetsToDisplay, QPushButton* prev,
                        QPushButton* next,  QLabel* pageLine,
                        vector<QLabel*> petNameLabels,
                        vector<QLabel*> petPhotos,
                        vector<QPushButton*> petLearnMore,
                        vector<QPushButton*> petSaves, vector<Pet> petVec){

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

//list view of my favorites and Manual Search
PetGallery:: PetGallery(bool b, int numPetsToDisplay, QPushButton* prev,
                        QPushButton* next,  QLabel* pageLine,
                        vector<QLabel*> petNameLabels,
                        vector<QLabel*> petInfo,
                        vector<QPushButton*> petLearnMore,
                        vector<QPushButton*> petSaves, vector<Pet> petVec){

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


//constructor for matchmaking (gallery view)
PetGallery::PetGallery(int numPetsToDisplay, QPushButton* prev,
                       QPushButton* next, QLabel* pageLine,
                       vector<QLabel*> petNameLabels,
                       vector<QLabel*> petPhotos,
                       vector<QLabel*> petScores,
                       vector<QPushButton*> petLearnMore,
                       vector<QPushButton*> petSaves, vector<pair<Pet, int>> petVec){
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

//constructor for matchmaking (list view)
PetGallery::PetGallery(bool b, int numPetsToDisplay, QPushButton* prev,
                       QPushButton* next, QLabel* pageLine,
                       vector<QLabel*> petNameLabels,
                       vector<QLabel*> petInfo,
                       vector<QLabel*> petScores,
                       vector<QPushButton*> petLearnMore,
                       vector<QPushButton*> petSaves, vector<pair<Pet, int>> petVec){
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




PetGallery::~PetGallery(){
}

void PetGallery::updatePetVec(vector<Pet> p){
    pets = p;
}

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
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            QString qpetName = QString::fromStdString(s);
            nameLabels[i]->setText(qpetName);


            if(infoLabels.size() >0){
                string info = pets[start].getSpecies() + " - " + pets[start].getGender() + " - good with " + pets[start].getGoodWith();
                infoLabels[i]->setText(QString::fromStdString(info));
            }

            if(picLabels.size() > 0){
                //picture
                if(pets[start].getImageFiles().size() == 0){
                    //default picture

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
                    string photo = "";
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

void PetGallery::next(){
    if(nextStartIndex + 1 < (int) pets.size()){
        displayPetsPageNumber++;
        nextStartIndex++;
        displayPets(nextStartIndex);

    }

}


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


void PetGallery::setPageNum(int p){
    displayPetsPageNumber = p;
}

Pet PetGallery::getPet(int pos){
    return petsToDisplay[pos];
}

vector<Pet> PetGallery::getPetVec(){
    return pets;
}

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

void PetGallery::matchPetsToRegPets(){
    pets = vector<Pet>();
   for(int i = 0; i < (int) matPets.size(); i++){
       pets.push_back(matPets[i].first);
   }
}


