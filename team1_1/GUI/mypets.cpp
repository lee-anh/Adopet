
#include "mypets.h"
#include "ui_mypets.h"

/*!
 * \brief MyPets constructor
 * \param parent
 */
MyPets::MyPets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPets)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    previousPage = 0;
    ui->linkToTemplate->setText("<a href = \"https://docs.google.com/spreadsheets/d/1C7GgwQls9a7Rxzte0Iz9U1Ei3gRmg5iuxAwXiLrIYPc/edit?usp=sharing\">Link to Adopet upload template</a>");
    ui->linkToTemplate->setTextFormat(Qt::RichText);
    ui->linkToTemplate->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->linkToTemplate->setOpenExternalLinks(true);

    connect(&petAdopted, SIGNAL(yesAdopted()), this, SLOT(backToMyPets()));


}

MyPets::~MyPets()
{
    delete ui;
}

/*!
 * \brief setOwner sets the owner object class
 * \param o owner
 */
void MyPets::setOwner(Owner *o){
    owner = o;
}

/*!
 * \brief goToUploadPet page, fills the pets from the database
 */
void MyPets::goToUploadPet(){
    //go to uploadPet page
    ui->stackedWidget->setCurrentIndex(1);
    previousPage = 1;
    //update pets from database
    owner->fillPets();

}

/*!
 * \brief goToMyPets page, fills pets from database, preset to gallery mode
 */
void MyPets::goToMyPets(){


    //update pets from database
    owner->fillPets();
    galleryMode();
    mode = "edit";

}

/*!
 * \brief galleryMode set up for gallery mode, sets up page and pet gallery
 */
void MyPets::galleryMode(){
    ui->viewMode->setCurrentIndex(1);
    //go to myPets page (gallery)
    ui->stackedWidget->setCurrentIndex(0);
    previousPage = 0;

    petgal = PetGallery(4, ui->previous, ui->next, ui->pageLine,
                        {ui->name1, ui->name2, ui->name3, ui->name4},
                        {ui->pic1, ui->pic2, ui->pic3, ui->pic4},
                        {ui->link1, ui->link2, ui->link3, ui->link4},
                        {ui->prev1, ui->prev2, ui->prev3, ui->prev4},
                        owner->getPets(), false);
    petgal.displayPets(0);
}

/*!
 * \brief listMode set up for list mode, sets up page and pet gallery
 */
void MyPets::listMode(){
    ui->viewModea->setCurrentIndex(2);
    //go to myPets page (list)
    ui->stackedWidget->setCurrentIndex(4);
    previousPage = 4;


    petgal = PetGallery(false, 8, ui->previousa, ui->nexta, ui->pageLinea,
                        {ui->name1a, ui->name2a, ui->name3a, ui->name4a, ui->name5a, ui->name6a, ui->name7a, ui->name8a},
                        {ui->info1a, ui->info2a, ui->info3a, ui->info4a, ui->info5a, ui->info6a, ui->info7a, ui->info8a},
                        {ui->link1a, ui->link2a, ui->link3a, ui->link4a, ui->link5a, ui->link6a, ui->link7a, ui->link8a},
                       {}, owner->getPets());
    petgal.displayPets(0);

}

/*!
 * \brief toEditPet, set up for edit pet page, load info for given pet
 * \param p pet
 */
void MyPets::toEditPet(Pet p){
    clearAll();
    currentPet = p;
    ui->stackedWidget->setCurrentIndex(2);
    ui->markAsAdopted->setVisible(true);

    ui->title->setText("Edit Pet");
    string name = p.getName();
    ui->name->setText(QString::fromStdString(name).toUpper());

    getIndex(p.getSpecies(), "species");
    getIndex(p.getBreed(), "breed");
    getIndex(p.getAge(), "age");
    getIndex(p.getSize(), "size");
    getIndex(p.getTemperament(), "temperament");
    getIndex(p.getGoodWith(), "goodWith");
    getIndex(p.getGender(), "gender");

    ui->bioBox->setText(QString::fromStdString(p.getBio()));
    string image = "";
    for(int i = 0 ; i < (int)p.getImageFiles().size(); i++){
        image = image +  p.getImageFiles().at(i) + ", ";
    }

    ui->multimediaBox->setPlainText(QString::fromStdString(image));
    if(p.getVideoFiles().size() > 0){
        ui->videoFile->setText(QString::fromStdString(p.getVideoFiles().at(0)));
    }
    ui->errorBarUploadPet->clear();

}


//display the pet info
/*!
 * \brief getIndex given an attribute, set the correct indexes for
 * the combo boxes, loading info for edit pet
 * \param attribute
 * \param type
 */
void MyPets::getIndex(string a, string type){
    if(type == "species"){
        if(a == "dog"){
            ui->speciesComboBox->setCurrentIndex(1);
        } else if (a == "cat"){
            ui->speciesComboBox->setCurrentIndex(2);
        } else if (a == "rabbit") {
            ui->speciesComboBox->setCurrentIndex(3);
        } else if (a == "rodent") {
            ui->speciesComboBox->setCurrentIndex(4);
        } else if (a == "fish") {
            ui->speciesComboBox->setCurrentIndex(5);
        } else if (a == "bird") {
            ui->speciesComboBox->setCurrentIndex(6);
        } else {
            ui->speciesComboBox->setCurrentIndex(7);
            ui->speciesLine->setText(QString::fromStdString(a));
        }

    } else if (type == "breed"){
        if(a == "sporting"){
            ui->breedComboBox->setCurrentIndex(1);
        } else if (a == "hound"){
           ui->breedComboBox->setCurrentIndex(2);
        } else if (a == "working"){
            ui->breedComboBox->setCurrentIndex(3);
         } else if (a == "terrier"){
            ui->breedComboBox->setCurrentIndex(4);
         } else if (a == "toy"){
            ui->breedComboBox->setCurrentIndex(5);
         } else if (a == "non-sporting"){
            ui->breedComboBox->setCurrentIndex(6);
         } else if (a == "herding"){
            ui->breedComboBox->setCurrentIndex(7);
         } else if (a == "siamese"){
            ui->breedComboBox->setCurrentIndex(8);
         } else if (a == "persian"){
            ui->breedComboBox->setCurrentIndex(9);
         } else if (a == "maine coon"){
            ui->breedComboBox->setCurrentIndex(10);
         } else if (a == "ragdoll"){
            ui->breedComboBox->setCurrentIndex(11);
         } else if (a == "rex"){
            ui->breedComboBox->setCurrentIndex(12);
         } else if (a == "lionhead"){
            ui->breedComboBox->setCurrentIndex(13);
         } else if (a == "californian"){
            ui->breedComboBox->setCurrentIndex(14);
         } else if (a == "angora"){
            ui->breedComboBox->setCurrentIndex(15);
         } else if (a == "silver fox"){
            ui->breedComboBox->setCurrentIndex(16);
         } else if (a == "hamster"){
            ui->breedComboBox->setCurrentIndex(17);
         } else if (a == "guinea pig"){
            ui->breedComboBox->setCurrentIndex(18);
         } else if (a == "gerbil"){
            ui->breedComboBox->setCurrentIndex(19);
         } else if (a == "mouse"){
            ui->breedComboBox->setCurrentIndex(20);
         } else if (a == "rat"){
            ui->breedComboBox->setCurrentIndex(21);
         } else if (a == "freshwater"){
            ui->breedComboBox->setCurrentIndex(22);
         } else if (a == "saltwater"){
            ui->breedComboBox->setCurrentIndex(23);
         } else if (a == "parakeet"){
            ui->breedComboBox->setCurrentIndex(24);
         } else if (a == "lovebird"){
            ui->breedComboBox->setCurrentIndex(25);
         } else if (a == "parrot"){
            ui->breedComboBox->setCurrentIndex(26);
         } else {
            ui->breedComboBox->setCurrentIndex(27);
            ui->breedLine->setText(QString::fromStdString(a));
        }
    } else if (type == "age"){
        if(a == "young"){
            ui->ageComboBox->setCurrentIndex(1);
        } else if (a == "adult"){
            ui->ageComboBox->setCurrentIndex(2);
        } else if (a == "senior") {
            ui->ageComboBox->setCurrentIndex(3);
        } else {
            ui->ageComboBox->setCurrentIndex(0);
        }

    } else if (type == "size"){
        if(a == "small"){
            ui->sizeComboBox->setCurrentIndex(1);
        } else if (a == "medium"){
            ui->sizeComboBox->setCurrentIndex(2);
        } else if (a == "large"){
            ui->sizeComboBox->setCurrentIndex(3);
        } else {
            ui->sizeComboBox->setCurrentIndex(0);
        }


    } else if (type == "temperament"){
        if(a == "happy"){
            ui->temperamentComboBox->setCurrentIndex(1);
        } else if (a == "friendly") {
            ui->temperamentComboBox->setCurrentIndex(2);
        } else if (a == "introverted") {
            ui->temperamentComboBox->setCurrentIndex(3);
        } else if (a == "active") {
            ui->temperamentComboBox->setCurrentIndex(4);
        } else if (a == "vigilant") {
            ui->temperamentComboBox->setCurrentIndex(5);
        } else {
            ui->temperamentComboBox->setCurrentIndex(6);
            ui->temperamentLine->setText(QString::fromStdString(a));
        }


    } else if (type == "gender"){
        if(a == "male"){
            ui->genderComboBox->setCurrentIndex(1);
        } else if (a == "female") {
            ui->genderComboBox->setCurrentIndex(2);
        } else {
            ui->genderComboBox->setCurrentIndex(0);
        }

    } else if (type == "goodWith"){
        if (a == "kids"){
            ui->goodWithComboBox->setCurrentIndex(1);
        } else if (a == "animals") {
            ui->goodWithComboBox->setCurrentIndex(2);
        } else {
            ui->goodWithComboBox->setCurrentIndex(3);
            ui->goodWithLine->setText(QString::fromStdString(a));
        }

    }
}

/*!
 * \brief clearAll clear all the relavent labels in the edit pet page
 */
void MyPets::clearAll(){
    ui->speciesComboBox->setCurrentIndex(0);
    ui->breedComboBox->setCurrentIndex(0);
    ui->temperamentComboBox->setCurrentIndex(0);
    ui->goodWithComboBox->setCurrentIndex(0);
    ui->sizeComboBox->setCurrentIndex(0);
    ui->ageComboBox->setCurrentIndex(0);
    ui->genderComboBox->setCurrentIndex(0);

    ui->name->clear();
    ui->speciesLine->clear();
    ui->breedLine->clear();
    ui->temperamentLine->clear();
    ui->goodWithLine->clear();

    ui->bioBox->clear();
    ui->multimediaBox->clear();
    ui->videoFile->clear();
    ui->errorBarUploadPet->clear();
    ui->savedLine->clear();

}


/*!
 * \brief imageProcessor parse image filenames
 * \param s input string
 */
void MyPets::imageProcessor(string s){

    vector<string> words = vector<string>();
    string word = "";
    for(int i = 0; i < (int) s.size(); i++){
        if(s.at(i) == ',' || s.at(i) == ' '){
            if (word.size() > 1)
            {
               words.push_back(word);
            }
            word = ""; //clear the word
        } else {
            word = word + s[i];
        }
    }

    //last word
    if(word.size() > 1){
        words.push_back(word);
    }

    for(int i = 0; i < (int) words.size(); i++){
        int ext = words.at(i).size();
        if(words.at(i).size() > 4){
            if(words.at(i).at(ext-4) == 'j'&& words.at(i).at(ext-3) == 'p'&& words.at(i).at(ext-2) == 'e'&& words.at(i).at(ext-1) == 'g'){
                currentPet.addImageFile(words.at(i));
            }
        }

    }


}

/*!
 * \brief videoProcessor parse video filenames
 * \param s input string
 */
void MyPets::videoProcessor(string s){
    if(s.size() > 3){
        int ext = s.size();
        if(s.at(ext-3) == 'm' && s.at(ext-2) == 'p' && s.at(ext-1) =='4'){
            currentPet.addVideoFile(s);
        }
    }
}

/*!
 * \brief on_markAsAdopted_clicked remove a pet from the database
 */
void MyPets::on_markAsAdopted_clicked()
{
    //QDialog
     petAdopted.setModal(true);
     petAdopted.exec();

}

/*!
 * \brief backToMyPets go back to my pets page after removing a pet
 */
void MyPets::backToMyPets(){

    owner->removePet(currentPet);
    goToMyPets();
}


/*!
 * \brief on_singleUploadButton_clicked got to upload one pet page
 */
void MyPets::on_singleUploadButton_clicked()
{
    //go to edit/upload pet
    ui->stackedWidget->setCurrentIndex(2);
    ui->markAsAdopted->setVisible(false);
    ui->title->setText("Upload Pet");
    mode = "upload";

    clearAll();
}


/*!
 * \brief on_saveChangesButton_clicked uploads changes to pet
 */
void MyPets::on_saveChangesButton_clicked()
{
    //get user input
    string petName = ui->name->text().toLower().toStdString();
    string species = ui->speciesComboBox->currentText().toLower().toStdString();
    string breed = ui->breedComboBox->currentText().toLower().toStdString();
    string age = ui->ageComboBox->currentText().toLower().toStdString();
    string size = ui->sizeComboBox->currentText().toLower().toStdString();
    string temperament = ui->temperamentComboBox->currentText().toLower().toStdString();
    string gender = ui->genderComboBox->currentText().toLower().toStdString();
    string goodWith = ui->goodWithComboBox->currentText().toLower().toStdString();
    string shelter = owner->getName();
    string bio = ui->bioBox->toPlainText().toStdString(); //can be empty
    string media = ui->multimediaBox->toPlainText().toStdString();
    string vid = ui->videoFile->text().toStdString();

    //media
    currentPet.preventDupMedia();
    imageProcessor(media);
    videoProcessor(vid);


    if (species == "other"){
        species = ui->speciesLine->text().toLower().toStdString();
    }
    if (breed == "other"){
        breed = ui->breedLine->text().toLower().toStdString();
    }
    if(temperament == "other"){
        temperament = ui->temperamentLine->text().toLower().toStdString();
    }
    if(goodWith == "other"){
        goodWith = ui->goodWithLine->text().toLower().toStdString();
    }


    if(petName == "" || species == ""|| breed == "" || age == "" || size == "" || temperament== "" ||gender == "" || goodWith == "" ){
        ui->errorBarUploadPet->setText("Missing field(s)");
    } else {
        if(mode == "upload"){
            int petID = owner->getLastPetID() + 1;
            Pet p = Pet(petID, petName, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
            //add pet to the database
            currentPet = p;
            currentPet.preventDupMedia();
            imageProcessor(media);
            videoProcessor(vid);

            owner->uploadPet(currentPet);
            ui->errorBarUploadPet->clear();
            ui->savedLine->setText("Pet uploaded successfully");


            mode = "edit";
        } else if (mode == "edit"){
            ui->errorBarUploadPet->clear();
            ui->savedLine->setText("Your changes have been saved");
            Pet p = Pet(currentPet.getID(), petName, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
            //update pet objects
            petgal.updatePet(p);
            owner->updatePet(p);
        }
    }


}


void MyPets::on_previous_clicked()
{
    petgal.previous();
}

void MyPets::on_next_clicked()
{
    petgal.next();
}

void MyPets::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(previousPage);
}



void MyPets::on_link1_clicked()
{
    whichPet = 0;
    toEditPet(petgal.getPet(0));

}

void MyPets::on_link2_clicked()
{
    whichPet = 1;
    toEditPet(petgal.getPet(1));

}

void MyPets::on_link3_clicked()
{
    whichPet = 2;
    toEditPet(petgal.getPet(2));

}

void MyPets::on_link4_clicked()
{
    whichPet = 3;
    toEditPet(petgal.getPet(3));

}


void MyPets::on_link1a_clicked()
{
    clearAll();
    whichPet = 0;
    toEditPet(petgal.getPet(0));

}

void MyPets::on_link2a_clicked()
{
    clearAll();
    whichPet = 1;
    toEditPet(petgal.getPet(1));

}

void MyPets::on_link3a_clicked()
{
    clearAll();
    whichPet = 2;
    toEditPet(petgal.getPet(2));

}

void MyPets::on_link4a_clicked()
{
    clearAll();
    whichPet = 3;
    toEditPet(petgal.getPet(3));

}
void MyPets::on_link5a_clicked()
{
    clearAll();
    whichPet = 4;
    toEditPet(petgal.getPet(4));

}

void MyPets::on_link6a_clicked()
{
    clearAll();
    whichPet = 5;
    toEditPet(petgal.getPet(5));

}

void MyPets::on_link7a_clicked()
{
    clearAll();
    whichPet = 6;
    toEditPet(petgal.getPet(6));

}

void MyPets::on_link8a_clicked()
{
    clearAll();
    whichPet = 7;
    toEditPet(petgal.getPet(7));

}

void MyPets::on_previousa_clicked()
{
    petgal.previous();
}

void MyPets::on_nexta_clicked()
{
    petgal.next();
}

/*!
 * \brief on_viewMode_currentIndexChanged change view mode, gallery view
 * \param index
 */
void MyPets::on_viewMode_currentIndexChanged(int index)
{
    //go to list mode
    if(index == 2){
        ui->stackedWidget->setCurrentIndex(4);
        listMode();
    }
}

/*!
 * \brief on_viewModea_currentIndexChanged change view mode, list view
 * \param index
 */
void MyPets::on_viewModea_currentIndexChanged(int index)
{
    //go to gallery mode
    if(index == 1){
        ui->stackedWidget->setCurrentIndex(0);
        galleryMode();
    }
}


void MyPets::on_speciesComboBox_currentIndexChanged(int index)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}

void MyPets::on_breedComboBox_currentIndexChanged(int index)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}

void MyPets::on_temperamentComboBox_currentIndexChanged(int index)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}
void MyPets::on_genderComboBox_currentIndexChanged(int index)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}

void MyPets::on_sizeComboBox_currentIndexChanged(int index)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}

void MyPets::on_goodWithComboBox_currentIndexChanged(int index)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}
void MyPets::on_ageComboBox_currentIndexChanged(int index)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}


void MyPets::on_speciesLine_textEdited(const QString &arg1)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}

void MyPets::on_breedLine_textEdited(const QString &arg1)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}
void MyPets::on_temperamentLine_textEdited(const QString &arg1)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}

void MyPets::on_goodWithLine_textEdited(const QString &arg1)
{
    ui->errorBarUploadPet->setText("You have unsaved changes");
}

void MyPets::on_bioBox_textChanged()
{
     ui->errorBarUploadPet->setText("You have unsaved changes");
}

void MyPets::on_multimediaBox_textChanged()
{
     ui->errorBarUploadPet->setText("You have unsaved changes");
}
void MyPets::on_videoFile_textChanged(const QString &arg1)
{
     ui->errorBarUploadPet->setText("You have unsaved changes");
}


/*!
 * \brief on_toBulkUpload_clicked navigate to bulk upload page
 */
void MyPets::on_toBulkUpload_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->fileName->clear();
    ui->uploadMessage->clear();
}


/*!
 * \brief on_pushButton_3_clicked pull up tag guide
 */
void MyPets::on_pushButton_3_clicked()
{
    TagGuide tg;
    tg.setModal(true);
    tg.exec();
}

/*!
 * \brief on_bulkUpload_2_clicked upload the csv and send state message
 */
void MyPets::on_bulkUpload_2_clicked()
{

    QString os = QSysInfo::productVersion();
    cout << os.toStdString() << endl;
    string filename;
    if(os == "10.16"){
        filename = "../../../../../csvs/" + ui->fileName->text().toStdString();
    } else {
        filename = "../../csvs/" + ui->fileName->text().toStdString();

    }
    bool b = owner->uploadPets(filename);

    if(b == true){
        ui->uploadMessage->setText("Pets were successfully uploaded!");
    } else {
        ui->uploadMessage->setText("Oops, there was an error. Please make sure the file format was correct");
    }
}

void MyPets::on_prev1_clicked()
{
    emit goToMeetPet(petgal.getPet(0));
}
void MyPets::on_prev2_clicked()
{
    emit goToMeetPet(petgal.getPet(1));
}
void MyPets::on_prev3_clicked()
{
    emit goToMeetPet(petgal.getPet(2));
}
void MyPets::on_prev4_clicked()
{
    emit goToMeetPet(petgal.getPet(3));
}

void MyPets::on_prev1a_clicked()
{
    emit goToMeetPet(petgal.getPet(0));
}
void MyPets::on_prev2a_clicked()
{
    emit goToMeetPet(petgal.getPet(1));
}
void MyPets::on_prev3a_clicked()
{
    emit goToMeetPet(petgal.getPet(2));
}
void MyPets::on_prev4a_clicked()
{
    emit goToMeetPet(petgal.getPet(3));
}
void MyPets::on_prev5a_clicked()
{
    emit goToMeetPet(petgal.getPet(4));
}
void MyPets::on_prev6a_clicked()
{
    emit goToMeetPet(petgal.getPet(5));
}
void MyPets::on_prev7a_clicked()
{
    emit goToMeetPet(petgal.getPet(6));
}
void MyPets::on_prev8a_clicked()
{
    emit goToMeetPet(petgal.getPet(7));
}

