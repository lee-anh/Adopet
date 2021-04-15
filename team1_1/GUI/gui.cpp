#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);


    savedList = SavedList("../../../../../projectDB.sqlite", "exampleUser");

    ui->stackedWidget->addWidget(&manSearch); //3
    ui->stackedWidget->addWidget(&myFavs); //4
    ui->stackedWidget->addWidget(&fmForAdopters); //5



    int openingPage = 2; //home page
    ui->stackedWidget->setCurrentIndex(openingPage); //opening page
    previousPage = openingPage;


    //Signals and slots
    connect(&manSearch, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&manSearch, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
    connect(&myFavs, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&myFavs, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
}


GUI::~GUI()
{
    ui->stackedWidget->removeWidget(&manSearch);
    ui->stackedWidget->removeWidget(&myFavs);
    delete ui;

}


void GUI::meetPet(Pet p){
    petToMeet = p;

    //set button
    //update savedList
    if(savedList.isSavedPet(petToMeet) == true){
        ui->saveButton->setChecked(true);
        ui->saveButton->setText("♥");
        ui->saveButton->setStyleSheet("color: red; border: none");
    } else{
        ui->saveButton->setChecked(false);
        ui->saveButton->setText("♡");
        ui->saveButton->setStyleSheet("color: black");
    }

    //set name
    string s = p.getName();
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    QString qs = "Meet " + QString::fromStdString(s);
    ui->petName->setText(qs);

    //set picture CURRENTLY TEMP
     QPixmap pixmap("../../../../../pictures/default.png");
     ui->petPic->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio));

    //set attributes
    string sep = " - ";
    string attributes = p.getSpecies() + sep +  p.getBreed() +
            sep + p.getAge() + sep + p.getTemperament() + "\n" + p.getSize() + sep + p.getGender()
            + sep + "good with " + p.getGoodWith();
    QString qattributes = QString::fromStdString(attributes);
    ui->petAttributes->setText(qattributes);

    //set bio
    string bio = p.getBio();
    QString qbio = QString::fromStdString(bio);
    ui->petBio->setText(qbio);

    //TODO - shelter info and link to shelter bio



}


void GUI::on_saveButton_clicked()
{
    if(ui->saveButton->isChecked() == false){
        savedList.unsavePet(petToMeet);
        ui->saveButton->setText("♡");
        ui->saveButton->setStyleSheet("color: black");
    } else if (ui->saveButton->isChecked() == true){
        savedList.savePet(petToMeet);
        ui->saveButton->setText("♥");
        ui->saveButton->setStyleSheet("color: red; border: none");
    }
}

void GUI::on_exit_clicked()
{
    this->close();

}

//slots for signals

void GUI::moveToMeetMe(Pet sendPet){
    ui->stackedWidget->setCurrentIndex(1);
    meetPet(sendPet);
}

void GUI::moveToMeetMe(Pet sendPet, bool b){
    ui->stackedWidget->setCurrentIndex(1);

    if(b == true){
        savedList.unsavePet(sendPet); //prevents dupliates
        savedList.savePet(sendPet);
    } else {
        savedList.unsavePet(sendPet);
    }

    meetPet(sendPet);
}

void GUI::heartPet(Pet p, bool b){
    if(b == true){
        savedList.unsavePet(p); //prevents dupliates
        savedList.savePet(p);
    } else {
        savedList.unsavePet(p);
    }

}


void GUI::on_backButton_clicked()
{
    //reset heart button
    ui->saveButton->setChecked(false);
    ui->saveButton->setText("♡");
    ui->saveButton->setStyleSheet("color: black");


    //unsaves pet if you unsaved it (should we keep it until you navigate away?)
    if(previousPage == 4){
        myFavs.setSavedList(savedList);
        myFavs.showGal();
    } else if (previousPage == 3){
        manSearch.setSavedList(savedList);
    }

    //back to last page
    ui->stackedWidget->setCurrentIndex(previousPage);
}

void GUI::on_navHomeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void GUI::on_navFindMatchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void GUI::on_navMyFavoritesButton_clicked()
{
    myFavs.setSavedList(savedList);
    myFavs.showGal();


    ui->stackedWidget->setCurrentIndex(4);
    previousPage = 4;

}

void GUI::on_navManualSearchButton_clicked()
{
    manSearch.setSavedList(savedList);
    ui->stackedWidget->setCurrentIndex(3);
    previousPage = 3;

}

void GUI::on_findMatchFromHome_clicked()
{

}

void GUI::on_manualSearchFromHome_clicked()
{
    on_navManualSearchButton_clicked();
}

void GUI::on_myFavoritesFromHome_clicked()
{
    on_navMyFavoritesButton_clicked();
}


