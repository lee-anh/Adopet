#include "gui.h"
#include "ui_gui.h"


/*!
 * \brief GUI constructor
 * \param parent
 */
GUI::GUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);

    //DIFFERENT OS

    QString os = QSysInfo::productVersion();

    if(os == "10.16"){
        dbName = "../../../../../projectDB.sqlite";
        QPixmap pixmap("../../../../../pictures/default.png");
        ui->logo->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio));
        ui->logoAdopter->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
        ui->logoOwner->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
    } else {
        //default picture
        dbName = "../../projectDB.sqlite";
        QPixmap pixmap("../../pictures/default.png");
        ui->logo->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio));
        ui->logoAdopter->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
        ui->logoOwner->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));

    }


    //dbName = "../../../../../projectDB.sqlite";

    auth = Authentication(dbName);

    //dynamically add widgets to the stackedWidget
    ui->stackedWidget->addWidget(&manSearch); //3
    ui->stackedWidget->addWidget(&myFavs); //4
    ui->stackedWidget->addWidget(&fmForAdopters); //5
    ui->stackedWidget->addWidget(&uinfo);//6
    ui->stackedWidget->addWidget(&pform); //7
    ui->stackedWidget->addWidget(&myPets);//8
    ui->stackedWidget->addWidget(&myFavsList); //9
    ui->stackedWidget->addWidget(&qz); //10
    ui->stackedWidget->addWidget(&fmForPets); //11
    ui->stackedWidget->addWidget(&zp); //12


    //Set the opening page
    int openingPage = 0; //login
    hideNavAdopter();
    hideNavOwner();
    ui->stackedWidget->setCurrentIndex(openingPage); //opening page
    previousPage = openingPage;


    //Signals and slots
    connect(&uinfo, SIGNAL(backClicked()), this, SLOT(backToLogin()));
    connect(&manSearch, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&manSearch, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
    connect(&myFavs, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&myFavs, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
    connect(&fmForAdopters, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&fmForAdopters, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
    connect(&pform, SIGNAL(adopterChanged(Adopter*)), this, SLOT(updateAdopter(Adopter*)));
    connect(&myFavs, SIGNAL(toListMode()), this, SLOT(toListMyFavorites()));
    connect(&myFavsList, SIGNAL(learnMoreClicked(Pet, bool)), this, SLOT(moveToMeetMe(Pet, bool)));
    connect(&myFavsList, SIGNAL(heartClicked(Pet, bool)), this, SLOT(heartPet(Pet, bool)));
    connect(&myFavsList, SIGNAL(goToGallery()), this, SLOT(toGalleryMyFavorites()));
    connect(&lg, SIGNAL(timeToLogout()), this, SLOT(logOut()));
    connect(&pform, SIGNAL(toQuiz()), this, SLOT(goToQuiz()));
    connect(&unsave, SIGNAL(unsavePet()), this, SLOT(unheartPet()));
    connect(&myPets, SIGNAL(goToMeetPet(Pet)), this, SLOT(goToMeetMe(Pet)));
    connect(&qz, SIGNAL(backToPreference(Preferences)), this, SLOT(quizToPreference(Preferences)));

}


GUI::~GUI()
{
    //dynamically remove stackedWidgets
    ui->stackedWidget->removeWidget(&manSearch);
    ui->stackedWidget->removeWidget(&myFavs);
    ui->stackedWidget->removeWidget(&fmForAdopters);
    ui->stackedWidget->removeWidget(&uinfo);
    ui->stackedWidget->removeWidget(&pform);
    ui->stackedWidget->removeWidget(&myPets);
    ui->stackedWidget->removeWidget(&myFavsList);
    ui->stackedWidget->removeWidget(&qz);
    ui->stackedWidget->removeWidget(&fmForPets);

    delete ui;

}


/*!
 * \brief meetPet displays more info about a pet, bio info
 * allows users to get to know pet more
 * \param p pet to meet
 */
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

    //images
     if(p.getImageFiles().size() == 0){

         //DIFFERENT OS
         QString os = QSysInfo::productVersion();
           
         if(os == "10.16"){
             QPixmap pixmap("../../../../../pictures/default.png");
             ui->petPic->setPixmap(pixmap.scaled(300, 300, Qt::KeepAspectRatio));
         } else {
             //default picture
             QPixmap pixmap("../../pictures/default.png");
             ui->petPic->setPixmap(pixmap.scaled(300, 300, Qt::KeepAspectRatio));

         }

     } else {
         mediaCarosel = 0;
         displayPicture(0);
     }



     //video
/*
     if(petToMeet.getVideoFiles().size() > 0){
         //default picture
         vp = new VideoPlayer;
         cout << petToMeet.getVideoFiles().size() << endl;
         string videoFile = "/Users/claireliu/CS250/project/team_1_1/videos/" + petToMeet.getVideoFiles().at(0);

         vp->setUrl(QUrl::fromLocalFile(QString::fromStdString(videoFile)));
         vp->show();


     }
*/
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

    //shelter info
    QString shelInfo = "INTERESTED? Contact " + QString::fromStdString(petToMeet.getOwner(dbName).getName()).toUpper() +
            "\nEmail:" + QString::fromStdString(petToMeet.getOwner(dbName).getEmail()) +
            "\nPhone: " + QString::number(petToMeet.getOwner(dbName).getPhoneNumber()) +
            "\nAddress: " + QString::fromStdString(petToMeet.getOwner(dbName).getAddress());

    ui->shelterInfo->setText(shelInfo);
}

/*!
 * \brief displayPicture, displays the pictures for a pet
 * in the pet's meet me page
 * \param i which pet
 */
void GUI::displayPicture(int i){
    QString os = QSysInfo::productVersion();
    string photo;
    if(os == "10.16"){
        photo =  "../../../../../pictures/" + petToMeet.getImageFiles().at(i);
    } else {
        photo =  "../../pictures/" + petToMeet.getImageFiles().at(i);

    }

    QPixmap pix(QString::fromStdString(photo));
    ui->petPic->setPixmap(pix.scaled(300, 300, Qt::KeepAspectRatio));
}

/*!
 * \brief on_right_clicked advance media carousel
 */
void GUI::on_right_clicked()
{
    if(mediaCarosel+1 < (int) petToMeet.getImageFiles().size()){
        mediaCarosel++;
        displayPicture(mediaCarosel);
    }
}

/*!
 * \brief on_left_clicked go back on media carousel
 */
void GUI::on_left_clicked()
{
    if(petToMeet.getImageFiles().size() > 0){
        if(mediaCarosel-1 >= 0){
            mediaCarosel--;
            displayPicture(mediaCarosel);
        }
    }
}



/*!
 * \brief hideNavAdopter hide adopter's navigation bar
 */
void GUI::hideNavAdopter(){
    ui->logoAdopter->setVisible(false);
    ui->titleAdopter->setVisible(false);
    ui->navFindMatchButton->setVisible(false);
    ui->navHomeButton->setVisible(false);
    ui->navManualSearchButton->setVisible(false);
    ui->navMyFavoritesButton->setVisible(false);
    ui->navMyPreferences->setVisible(false);
    ui->navHelpButton->setVisible(false);
    ui->exit->setVisible(false);
    ui->navMyInfoButton->setVisible(false);
}

/*!
 * \brief showNavAdopter show adopter's navigation bar
 */
void GUI::showNavAdopter(){
    ui->logoAdopter->setVisible(true);
    ui->titleAdopter->setVisible(true);
    ui->navFindMatchButton->setVisible(true);
    ui->navHomeButton->setVisible(true);
    ui->navManualSearchButton->setVisible(true);
    ui->navMyFavoritesButton->setVisible(true);
    ui->navMyPreferences->setVisible(true);
    ui->navHelpButton->setVisible(true);
    ui->exit->setVisible(true);
    ui->navMyInfoButton->setVisible(true);

    ui->preferenceFromHome->setText("My Preferences");
    ui->label1->setText("Set your preferences using a form or our fun quiz!");
    ui->findMatchFromHome->setText("Find Match");
    ui->label2->setText("Use our advanced matchmaking algorithm to find the pet that's perfect for you");
    ui->manualSearchFromHome->setText("Manual Search");
    ui->label3->setText("Take the wheel and manually search through our extensive pet database");
    ui->myFavoritesFromHome->setText("My Favorites");
    ui->label4->setText("View your favorite pets");
}

/*!
 * \brief hideNavOwner hide the owner's navigation bar
 */
void GUI::hideNavOwner(){
    ui->titleOwner->setVisible(false);
    ui->logoOwner->setVisible(false);
    ui->ownerHome->setVisible(false);
    ui->ownerMyInfo->setVisible(false);
    ui->ownerMyPets->setVisible(false);
    ui->ownerFindMatch->setVisible(false);
    ui->ownerHelp->setVisible(false);
    ui->ownerLogout->setVisible(false);
    ui->ownerUploadPet->setVisible(false);



}

/*!
 * \brief showNavOwner shows the owner's navigation bar
 */
void GUI::showNavOwner(){
    ui->titleOwner->setVisible(true);
    ui->logoOwner->setVisible(true);
    ui->ownerHome->setVisible(true);
    ui->ownerMyInfo->setVisible(true);
    ui->ownerMyPets->setVisible(true);
    ui->ownerFindMatch->setVisible(true);
    ui->ownerHelp->setVisible(true);
    ui->ownerLogout->setVisible(true);
    ui->ownerUploadPet->setVisible(true);


    ui->preferenceFromHome->setText("My Info");
    ui->label1->setText("View and edit the information that potential adopters will see about your shelter!");
    ui->findMatchFromHome->setText("Upload Pets");
    ui->label2->setText("Upload pets in bulk or one by one!");
    ui->manualSearchFromHome->setText("My Pets");
    ui->label3->setText("View and edit the pets that you've uploaded!");
    ui->myFavoritesFromHome->setText("Find Match");
    ui->label4->setText("Use our advanced matchmaking algorithm to adopters that are perfect for your pets");
}

/*!
 * \brief on_exit_clicked displays a warning before logging out of system
 */
void GUI::on_exit_clicked()
{

    //QDialog
    lg.setModal(true);
    lg.exec();



}



//slots for signals

/*!
 * \brief moveToMeetMe send user to meet me page
 * \param sendPet pet to display
 * \param b if the pet is saved or not
 */
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

/*!
 * \brief heartPet heart info for a pet to meet
 * \param p pet
 * \param b if the pet is saved or not
 */
void GUI::heartPet(Pet p, bool b){
    if(b == true){
        savedList.unsavePet(p); //prevents dupliates
        savedList.savePet(p);
    } else {
        savedList.unsavePet(p);
    }

}

/*!
 * \brief backToLogin bring user back to login page
 */
void GUI::backToLogin(){
    ui->stackedWidget->setCurrentIndex(0);
}

/*!
 * \brief updateAdopter object
 * \param a new adopter
 */
void GUI::updateAdopter(Adopter *a){
    adopter = a;
}

/*!
 * \brief toListMyFavorites to my favorites, list mode
 */
void GUI::toListMyFavorites(){

    myFavsList.setSavedList(savedList);
    myFavsList.showGal();
    //navigate to my favorites list screen
    ui->stackedWidget->setCurrentIndex(9);
    previousPage = 9;
}

/*!
 * \brief toGalleryMyFavorites to my favorites, gallery mode
 */
void GUI::toGalleryMyFavorites(){
    on_navMyFavoritesButton_clicked();
}
/*!
 * \brief logOut of system
 */
void GUI::logOut(){
    //back to login page
    hideNavAdopter();
    hideNavOwner();
    ui->stackedWidget->setCurrentIndex(0);
    previousPage = 0;
    uinfo.setFirstTime(true);
}

/*!
 * \brief goToQuiz (preference quiz)
 */
void GUI::goToQuiz(){
    ui->stackedWidget->setCurrentIndex(10);
    qz.startQuiz();
}

/*!
 * \brief unheartPet unsave a pet, updates the database
 * and updates the buttons
 */
void GUI::unheartPet(){
    savedList.unsavePet(petToMeet); //update database
    ui->saveButton->setText("♡");
    ui->saveButton->setStyleSheet("color: black");
}
/*!
 * \brief goToMeetMe for owners, owner preview
 * \param p pet to meet
 */
void GUI::goToMeetMe(Pet p){
    ui->stackedWidget->setCurrentIndex(1);
    meetPet(p);
    previousPage = 8;
}

/*!
 * \brief quizToPreference back to preference from quiz
 * updates the preferences object
 * \param pf
 */
void GUI::quizToPreference(Preferences pf){
    adopter->setPreference(pf);
    ui->stackedWidget->setCurrentIndex(7);
    on_navMyPreferences_clicked();
}

/*!
 * \brief on_saveButton_clicked save a pet
 */
void GUI::on_saveButton_clicked()
{
    if(ui->saveButton->isChecked() == false){
        unsave.setModal(true);
        unsave.exec();
        /*
        savedList.unsavePet(petToMeet); //update database
        ui->saveButton->setText("♡");
        ui->saveButton->setStyleSheet("color: black");
        */
    } else if (ui->saveButton->isChecked() == true){
        savedList.savePet(petToMeet); //update database
        ui->saveButton->setText("♥");
        ui->saveButton->setStyleSheet("color: red; border: none");
    }
}

/*!
 * \brief on_navHomeButton_clicked back to home page
 * for Adopters
 */
void GUI::on_navHomeButton_clicked()
{
    //navigate to home screen
    ui->stackedWidget->setCurrentIndex(2);
}

/*!
 * \brief on_navFindMatchButton_clicked to Find Match page
 * for Adopters
 */
void GUI::on_navFindMatchButton_clicked()
{
    //navigate to find match screen
    ui->stackedWidget->setCurrentIndex(5);
    fmForAdopters.setSavedList(savedList);
    fmForAdopters.setUser(username, to_string(adopter->getZipCode()));
    previousPage = 5;
}

/*!
 * \brief on_navMyFavoritesButton_clicked to My Favorites page
 * for Adopters
 */
void GUI::on_navMyFavoritesButton_clicked()
{
    //pass vital information to myFavs
    myFavs.setSavedList(savedList);
    myFavs.showGal();

    //navigate to my favorites screen
    ui->stackedWidget->setCurrentIndex(4);
    previousPage = 4;

}

/*!
 * \brief on_navManualSearchButton_clicked to Manual Search page
 * for Adopters
 */
void GUI::on_navManualSearchButton_clicked()
{
    //pass vital information to manSearch
    manSearch.setSavedList(savedList, to_string(adopter->getZipCode()));

    //navigate to manual search
    ui->stackedWidget->setCurrentIndex(3);
    previousPage = 3;

}

/*!
 * \brief on_navMyInfoButton_clicked to My Info page
 * for Adopters
 */
void GUI::on_navMyInfoButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    uinfo.adopterMyInfoClicked();
}

/*!
 * \brief on_navMyPreferences_clicked to My Preferences page
 * for Adopters
 */
void GUI::on_navMyPreferences_clicked()
{
    //to preferences form
    ui->stackedWidget->setCurrentIndex(7);
    pform.setAdopter(adopter);

    pform.clearCheckBoxes(); //clear
    pform.loadPreferences(); //reload
}

/*!
 * \brief on_preferenceFromHome_clicked to my preferences page
 * for Adopters
 */
void GUI::on_preferenceFromHome_clicked()
{
    if(userType == "adopter"){
         on_navMyPreferences_clicked();
    } else {
        on_ownerMyInfo_clicked();
    }

}
/*!
 * \brief on_navHelpButton_clicked to help page
 * for Adopters
 */
void GUI::on_navHelpButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    uinfo.helpAdopter();
}

/*!
 * \brief on_findMatchFromHome_clicked to find Match page
 * for Adopters
 */
void GUI::on_findMatchFromHome_clicked()
{
    if(userType == "adopter"){
        on_navFindMatchButton_clicked();
    } else {
        on_ownerUploadPet_clicked();
    }

}

/*!
 * \brief on_manualSearchFromHome_clicked to manual search page
 * for Adopters
 */
void GUI::on_manualSearchFromHome_clicked()
{
    if(userType == "adopter"){
       on_navManualSearchButton_clicked();
    } else {
        on_ownerMyPets_clicked();
    }

}

/*!
 * \brief on_myFavoritesFromHome_clicked to my favorites page
 * for Adopters
 */
void GUI::on_myFavoritesFromHome_clicked()
{
    if(userType == "adopter"){
        on_navMyFavoritesButton_clicked();
    } else {
        on_ownerFindMatch_clicked();
    }

}

/*!
 * \brief on_backButton_clicked go back to previous page
 * back button is on the meetMe page
 */
void GUI::on_backButton_clicked()
{
  
    //TODO: check if active before closing?
    //vp->pause();
    //vp->close();

    //reset heart button
    ui->saveButton->setChecked(false);
    ui->saveButton->setText("♡");
    ui->saveButton->setStyleSheet("color: black");


    //unsaves pet if you unsaved it (should we keep it until you navigate away?)
    if(previousPage == 4){
        myFavs.setSavedList(savedList);
        myFavs.showGal();
    } else if (previousPage == 3){
        manSearch.setSavedList(savedList, to_string(adopter->getZipCode()));
    }

    //back to last page
    ui->stackedWidget->setCurrentIndex(previousPage);
}

/*!
 * \brief on_loginButton_clicked login to system
 */
void GUI::on_loginButton_clicked()
{

    string uname = ui->username->text().toStdString();
    string pwd = ui->password->text().toStdString();
    cout << uname << endl;
    cout << pwd << endl;

    // 0 = adopter
    // 1 = owner
    // -1 = auth fail

    if(auth.logIn(uname, pwd) == 0){
        uinfo.setAuth(&auth);

        adopter = auth.getAuthenticatedAdopter();
        savedList = SavedList(dbName, uname);
        username = uname;
        ui->stackedWidget->setCurrentIndex(2); //go to home screen
        previousPage = 0;
        userType = "adopter";
        showNavAdopter();

    } else if (auth.logIn(uname, pwd) == 1){
        //OWNER
        cout << "Line 451" << endl;
        uinfo.setAuth(&auth, uname);
        cout << "Line 453" << endl;
        username = uname;
        owner = auth.getAuthenticatedOwner();

        cout << "Line 456" << endl;
        ui->stackedWidget->setCurrentIndex(2); //go to home screen
        previousPage = 0;
        userType = "owner";
        showNavOwner();
    } else {
        ui->errorLine->setText("Username or password is not correct");
    }

    //clear the line edits
    ui->username->clear();
    ui->password->clear();
}

/*!
 * \brief on_password_returnPressed login to system,
 * same functionality as login button, just with enter/return key instead
 */
void GUI::on_password_returnPressed()
{
    on_loginButton_clicked();
}

/*!
 * \brief on_createAccountButton_clicked to create account page
 */
void GUI::on_createAccountButton_clicked()
{
    //to create account page (userinfo.ui)
    uinfo.createAccountClicked();
    ui->stackedWidget->setCurrentIndex(6);
    uinfo.setAuth(&auth, true);
}


/*!
 * \brief on_ownerMyPets_clicked to My Pets page
 * for Owners
 */
void GUI::on_ownerMyPets_clicked()
{
    //go to MyPets Page
    ui->stackedWidget->setCurrentIndex(8);
    myPets.setOwner(owner);
    myPets.goToMyPets();
}

/*!
 * \brief on_ownerLogout_clicked logout of system
 * for Owners
 */
void GUI::on_ownerLogout_clicked()
{
    on_exit_clicked();
}


/*!
 * \brief on_ownerUploadPet_clicked to upload pet page
 * for Owners
 */
void GUI::on_ownerUploadPet_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    myPets.setOwner(owner);
    myPets.goToUploadPet();
}
/*!
 * \brief on_ownerMyInfo_clicked to my info page
 * for Owners
 */
void GUI::on_ownerMyInfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    uinfo.ownerMyInfoClicked();
}

/*!
 * \brief on_ownerFindMatch_clicked to find match page
 * for Owners
 */
void GUI::on_ownerFindMatch_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    fmForPets.toMainPage(owner);
}

/*!
 * \brief on_ownerHome_clicked to home page
 * for Owners
 */
void GUI::on_ownerHome_clicked()
{
    on_navHomeButton_clicked();
}





/*!
 * \brief on_ownerHelp_clicked to help page
 * for Owners
 */
void GUI::on_ownerHelp_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    uinfo.helpOwner();
}




