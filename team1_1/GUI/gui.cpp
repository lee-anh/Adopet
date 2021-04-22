#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);

    dbName = "../../../../../projectDB.sqlite";
    auth = Authentication(dbName);



    //will need to change the constructor later
    //FILEPATH may be different on lab server ... maybe ../../projectDB.sqlite instead?
   // savedList = SavedList("../../../../../projectDB.sqlite", "exampleUser");

    //dynamically add widgets to the stackedWidget
    ui->stackedWidget->addWidget(&manSearch); //3
    ui->stackedWidget->addWidget(&myFavs); //4
    ui->stackedWidget->addWidget(&fmForAdopters); //5
    ui->stackedWidget->addWidget(&uinfo);//6

    //Set the opening page
    int openingPage = 0; //login
    hideNav();
    ui->stackedWidget->setCurrentIndex(openingPage); //opening page
    previousPage = openingPage;


    //Signals and slots
    connect(&uinfo, SIGNAL(backClicked()), this, SLOT(backToLogin()));
    connect(&uinfo, SIGNAL(updatedAdopter(Adopter)), this, SLOT(updateAdopter(Adopter)));
    connect(&manSearch, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&manSearch, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
    connect(&myFavs, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&myFavs, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
    connect(&fmForAdopters, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&fmForAdopters, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
}


GUI::~GUI()
{
    //dynamically remove stackedWidgets
    ui->stackedWidget->removeWidget(&manSearch);
    ui->stackedWidget->removeWidget(&myFavs);
    ui->stackedWidget->removeWidget(&fmForAdopters);
    delete ui;

}


void GUI::meetPet(Pet p){
    petToMeet = p;


    //set button correctly
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



void GUI::hideNav(){
    ui->navFindMatchButton->setVisible(false);
    ui->navHomeButton->setVisible(false);
    ui->navManualSearchButton->setVisible(false);
    ui->navMyFavoritesButton->setVisible(false);
    ui->navMyPreferences->setVisible(false);
    ui->navHelpButton->setVisible(false);
    ui->exit->setVisible(false);
    ui->navMyInfoButton->setVisible(false);
}

void GUI::showNav(){
    ui->navFindMatchButton->setVisible(true);
    ui->navHomeButton->setVisible(true);
    ui->navManualSearchButton->setVisible(true);
    ui->navMyFavoritesButton->setVisible(true);
    ui->navMyPreferences->setVisible(true);
    ui->navHelpButton->setVisible(true);
    ui->exit->setVisible(true);
    ui->navMyInfoButton->setVisible(true);
}

void GUI::on_saveButton_clicked()
{
    if(ui->saveButton->isChecked() == false){
        savedList.unsavePet(petToMeet); //update database
        ui->saveButton->setText("♡");
        ui->saveButton->setStyleSheet("color: black");
    } else if (ui->saveButton->isChecked() == true){
        savedList.savePet(petToMeet); //update database
        ui->saveButton->setText("♥");
        ui->saveButton->setStyleSheet("color: red; border: none");
    }
}

void GUI::on_exit_clicked()
{
    this->close();

}



//slots for signals

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


void GUI::backToLogin(){
    ui->stackedWidget->setCurrentIndex(0);
}

void GUI::updateAdopter(Adopter a){
    adopter = a;
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
    //navigate to home screen
    ui->stackedWidget->setCurrentIndex(2);
}


void GUI::on_navFindMatchButton_clicked()
{
    //navigate to find match screen
    ui->stackedWidget->setCurrentIndex(5);
    fmForAdopters.setSavedList(savedList);
    fmForAdopters.setUser("user1");
    previousPage = 5;
}

void GUI::on_navMyFavoritesButton_clicked()
{
    //pass vital information to myFavs
    myFavs.setSavedList(savedList);
    myFavs.showGal();

    //navigate to my favorites screen
    ui->stackedWidget->setCurrentIndex(4);
    previousPage = 4;

}

void GUI::on_navManualSearchButton_clicked()
{
    //pass vital information to manSearch
    manSearch.setSavedList(savedList);

    //navigate to manual search
    ui->stackedWidget->setCurrentIndex(3);
    previousPage = 3;

}

void GUI::on_navMyInfoButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    uinfo.adopterMyInfoClicked();
}


void GUI::on_findMatchFromHome_clicked()
{
    on_navFindMatchButton_clicked();
}

void GUI::on_manualSearchFromHome_clicked()
{
    on_navManualSearchButton_clicked();
}

void GUI::on_myFavoritesFromHome_clicked()
{
    on_navMyFavoritesButton_clicked();
}



void GUI::on_loginButton_clicked()
{

    string uname = ui->username->text().toStdString();
    string pwd = ui->password->text().toStdString();
    cout << uname << endl;
    cout << pwd << endl;
    //int i = auth.logIn("user1", "password1"); //why is this giving me -1 here but not in the main of auth
    //cout << i << endl;
    // 0 = adopter
    // 1 = owner
    // -1 = auth fail

    if(auth.logIn(uname, pwd) == 0){
        uinfo.setAuth(auth);
        adopter = auth.getAuthenticatedAdopter();
        savedList = SavedList(dbName, uname);
        ui->stackedWidget->setCurrentIndex(2); //go to home screen
        previousPage = 0;
        showNav();
    } else if (auth.logIn(uname, pwd) == 1){
        //WILL NEED TO REVISE?
        uinfo.setAuth(auth);
        owner = auth.getAuthenticatedOwner();
        ui->stackedWidget->setCurrentIndex(2); //go to home screen
        previousPage = 0;
        showNav();
    } else {
        ui->errorLine->setText("Username or password is not correct");
    }
}

void GUI::on_createAccountButton_clicked()
{
    //to create account page (userinfo.ui)
    ui->stackedWidget->setCurrentIndex(6);
    uinfo.setAuth(auth);
}

