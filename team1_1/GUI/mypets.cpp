
#include "mypets.h"
#include "ui_mypets.h"

MyPets::MyPets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPets)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    previousPage = 0;
}

MyPets::~MyPets()
{
    delete ui;
}

void MyPets::setOwner(Owner *o){
    owner = o;
}

void MyPets::goToUploadPet(){
    //go to uploadPet page
    ui->stackedWidget->setCurrentIndex(1);
    previousPage = 1;
    //update pets from database
    owner->fillPets();

}


void MyPets::goToMyPets(){
    //go to myPets page
    ui->stackedWidget->setCurrentIndex(0);
    previousPage = 0;


    //update pets from database
    owner->fillPets();

    petgal = PetGallery(4, ui->previous, ui->next, ui->pageLine,
                        {ui->name1, ui->name2, ui->name3, ui->name4},
                        {ui->pic1, ui->pic2, ui->pic3, ui->pic4},
                        {ui->link1, ui->link2, ui->link3, ui->link4},
                        owner->getPets());

    petgal.displayPets(0);

}
void MyPets::on_markAsAdopted_clicked()
{
    //QDialog Experiment
    // PetAdopted petAdopted;
    // petAdopted.setModal(true);
    // petAdopted.exec();
}

void MyPets::on_singleUploadButton_clicked()
{
    //go to edit/upload pet
    ui->stackedWidget->setCurrentIndex(2);
    ui->markAsAdopted->setVisible(false);
    ui->title->setText("Upload Pet");
}

void MyPets::on_saveChangesButton_clicked()
{

    int petID = owner->getLastPetID();
    string petName = ui->name->text().toStdString(); //must remember to lowercase!
    transform(petName.begin(), petName.end(), petName.begin(), ::tolower);
    string species = ui->speciesComboBox->currentText().toStdString();
    string breed = ui->breedComboBox->currentText().toStdString();
    string age = ui->ageComboBox->currentText().toStdString();
    string size = ui->sizeComboBox->currentText().toStdString();
    string temperament = ui->temperamentComboBox->currentText().toStdString();
    string gender = ui->genderComboBox->currentText().toStdString();
    string goodWith = ui->goodWithComboBox->currentText().toStdString();
    string shelter = owner->getName();
    string bio = ui->bioBox->toPlainText().toStdString(); //can be empty

    //what if we are editing the pet? Different screen?
    //check for any empty variables
    if(petName == "" || species == ""|| breed == "" || age == "" || size == "" || temperament== "" ||gender == "" || goodWith == "" ||shelter== "" ){
        ui->errorBarUploadPet->setText("Missing field(s)");
    } else {
        Pet p = Pet(petID, petName, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
        //add pet to the database
        owner->uploadPet(p);
    }

    //TODO: check for other!!!

    //other will need to add to the different attribute tables of the database




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

//still need to load the pets and link them
