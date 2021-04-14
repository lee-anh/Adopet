#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);


    savedList = SavedList("../../../../../projectDB.sqlite", "exampleUser");
    ui->stackedWidget->addWidget(&manSearch); //2
    ui->stackedWidget->addWidget(&myFavs); //3

    //JUST FOR NOW

    int openingPage = 2;
    ui->stackedWidget->setCurrentIndex(openingPage); //opening page
    previousPage = openingPage;


    //Signals and slots
    connect(&manSearch, SIGNAL(learnMoreClicked(Pet)), this, SLOT(moveToMeetMe(Pet)));
    connect(&myFavs, SIGNAL(learnMoreClicked(Pet)), this, SLOT(moveToMeetMe(Pet)));
}


GUI::~GUI()
{
    ui->stackedWidget->removeWidget(&manSearch);
    delete ui;

}


void GUI::meetPet(Pet p){
    petToMeet = p;

    //set button
    //update savedList
    if(savedList.isSavedPet(petToMeet) == true){
        ui->saveButton->setChecked(true);
        ui->saveButton->setText("♥");
        ui->saveButton->setStyleSheet("color: red");
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
        ui->saveButton->setStyleSheet("color: red");
    }
}

void GUI::on_exit_clicked()
{
    this->close();

}


void GUI::moveToMeetMe(Pet sendPet){
    ui->stackedWidget->setCurrentIndex(1);
    meetPet(sendPet);
}

void GUI::on_backButton_clicked()
{
    //reset heart button
    ui->saveButton->setChecked(false);
    ui->saveButton->setText("♡");
    ui->saveButton->setStyleSheet("color: black");

    //back to last page
    ui->stackedWidget->setCurrentIndex(previousPage);
}

void GUI::on_navMyFavoritesButton_clicked()
{
    myFavs.setSavedList(savedList);
    myFavs.showGal();
    ui->stackedWidget->setCurrentIndex(3);
    previousPage = 3;

}

void GUI::on_navManualSearchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    previousPage = 2;

}
