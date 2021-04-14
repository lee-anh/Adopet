
#include "petgallery.h"

PetGallery::PetGallery()
{

}

PetGallery:: PetGallery(int numPetsToDisplay, QLabel* pageLine, vector<QLabel*> petNameLabels,
                        vector<QLabel*> petPhotos, vector<QPushButton*> petLearnMore,vector<Pet> petVec){
    numToDisplay = numPetsToDisplay;
    pageNum = pageLine;
    nameLabels = petNameLabels;
    picLabels = petPhotos;
    learnMores = petLearnMore;
    pets = petVec;
    nextStartIndex = 0;
    displayPetsPageNumber = 1;

    petsToDisplay = vector<Pet>();

}



PetGallery::~PetGallery(){

}

void PetGallery::updatePetVec(vector<Pet> p){
    pets = p;
}

void PetGallery::displayPets(int start){
    QPixmap pixmap("../../../../../pictures/default.png");
    int counter = 0;
    petsToDisplay.clear();

    for(int i = 0; i < numToDisplay; i++){
        nameLabels[i]->clear();
        picLabels[i]->clear();
        learnMores[i]->setVisible(false);
        if(start < (int) pets.size()){
            //add to petsToDisplay vec
             petsToDisplay.push_back(pets[start]);

            //name
            string s = pets[start].getName();
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            QString qpetName = QString::fromStdString(s);
            nameLabels[i]->setText(qpetName);

            //TEMP
            picLabels[i]->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio));

            //learnMores
            learnMores[i]->setVisible(true);

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

