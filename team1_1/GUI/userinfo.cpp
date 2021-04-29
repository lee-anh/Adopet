#include "userinfo.h"
#include "ui_userinfo.h"

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{

    ui->setupUi(this);

    //starts on create account page
    ui->stackedWidget->setCurrentIndex(0);
    firstTime = true;

}

UserInfo::~UserInfo()
{
    delete ui;
}

void UserInfo::setAuth(Authentication *a){
    cout << "uinfo 23" << endl;
    auth = a;
    cout << "uinfo 25" << endl;
    username = a->getAuthenticatedAdopter()->getUsername();
    cout << "uinfo 27" << endl;
}

void UserInfo::setAuth(Authentication *a, string uname){
    auth = a;
    username = uname;
}

void UserInfo::createAccountClikced(){

    //goes to create account page
    clearCreateAccount();
    ui->stackedWidget->setCurrentIndex(0);
    firstTime = true;

    //owner stuff
    ui->shelterName->clear();
    ui->nameOwner->setVisible(true);


}

void UserInfo::adopterMyInfoClicked(){
    ui->stackedWidget->setCurrentIndex(1);
    firstTime = false;

    clearAdopterInfo();

    ui->firstName->setText(QString::fromStdString(auth->getAuthenticatedAdopter()->getFirstName()));
    ui->lastName->setText(QString::fromStdString(auth->getAuthenticatedAdopter()->getLastName()));
    ui->emailAddress->setText(QString::fromStdString(auth->getAuthenticatedAdopter()->getEmailAddress()));
    //will have to check for leading zeros here
    ui->zipCode->setText(QString::fromStdString(to_string(auth->getAuthenticatedAdopter()->getZipCode())));

}


void UserInfo::ownerMyInfoClicked(){
    ui->stackedWidget->setCurrentIndex(2);
    firstTime = false;

    clearOwnerInfo();


    ui->nameOwner->setVisible(false);
    ui->shelterName->setText(QString::fromStdString(auth->getAuthenticatedOwner()->getName()));
    ui->phoneNumberOwner->setText((QString::fromStdString(to_string(auth->getAuthenticatedOwner()->getPhoneNumber()))));
    ui->emailOwner->setText(QString::fromStdString(auth->getAuthenticatedOwner()->getEmail()));
    ui->addressOwner->setText(QString::fromStdString(auth->getAuthenticatedOwner()->getAddress()));;
    ui->zipOwner->setText((QString::fromStdString(to_string(auth->getAuthenticatedOwner()->getZipCode()))));

    // do we really have to select the type of owner?

}

void UserInfo::on_continueButton_clicked()
{

    string uname = ui->username->text().toStdString();
    string pwd = ui->password->text().toStdString();
    string pwdVer = ui->passwordVerification->text().toStdString();
    string type = ui->accountType->currentText().toLower().toStdString();

    if(uname == "" || pwd == "" || pwdVer == ""|| type == "select one"){
        ui->errorLabel->setText("Missing field(s)");
    } else if(pwd != pwdVer){
        ui->errorLabel->setText("Passwords don't match");
    } else {
        bool b = auth->signUp(uname, pwd, type);
        if (b == true){
            //to the my info page
            if(type == "adopter"){
                //go to adopter info page
                clearAdopterInfo();
                ui->stackedWidget->setCurrentIndex(1);


            } else {
                //go to owner info page
                clearOwnerInfo();
                ui->stackedWidget->setCurrentIndex(2);
                ui->nameOwner->setVisible(true);


            }

            username = uname;
            password = pwd;

        } else {
            ui->errorLabel->setText("Username already exists. Pick another please.");
        }
    }


}

void UserInfo::on_saveButton_clicked()
{
    string fname = ui->firstName->text().toStdString();
    string lname = ui->lastName->text().toStdString();
    string email = ui->emailAddress->text().toStdString();
    string zip = ui->zipCode->text().toStdString();


    if(fname == "" || lname == "" || email == "" || zip == ""){
        ui->errorLabel2->setText("Missing field(s)");
    } else {
        if(firstTime == true){
            auth->insertAdopterToDB(username, fname, lname, email, zip);
            emit backClicked(); //back to the login page
        } else {
            auth->updateAdopter(username, fname, lname, email, zip);
            ui->adopterSavedMessage->setText("Your changes have been saved");
        }

    }


}

void UserInfo::on_backButton_clicked()
{
    emit backClicked(); //back to the login page
}

void UserInfo::on_saveOwnerButton_clicked()
{

    if(firstTime == true){
        string name = ui->nameOwner->text().toLower().toStdString();
        string phone = ui->phoneNumberOwner->text().toStdString();
        string email = ui->emailOwner->text().toStdString();
        string address = ui->addressOwner->text().toStdString();
        string zip = ui->zipOwner->text().toStdString();

        if(name == "" || phone == "" || address == "" || email == ""|| zip == ""){
            ui->errorLabelOwner->setText("Missing field(s)");
        } else {

            bool verified = auth->insertOwnerToDB(username, name, phone, email, address, zip);
            if (verified == true){
                emit backClicked(); //back to the login page

            } else {
                ui->errorLabelOwner->setText("Shelter name already taken. Choose another");
            }

        }
    } else {
        string name = ui->shelterName->text().toStdString();
        string phone = ui->phoneNumberOwner->text().toStdString();
        string email = ui->emailOwner->text().toStdString();
        string address = ui->addressOwner->text().toStdString();
        string zip = ui->zipOwner->text().toStdString();

        if( phone == "" || address == "" || email == ""|| zip == ""){
            ui->errorLabelOwner->setText("Missing field(s)");
        } else {

            auth->updateOwner(username, name, phone, email, address, zip);
            ui->ownerSavedMessage->setText("Your changes have been saved");

        }
    }


}

void UserInfo::setFirstTime(bool b){
    firstTime = b;
}

void UserInfo::clearAdopterInfo(){

    ui->firstName->clear();
    ui->lastName->clear();
    ui->emailAddress->clear();
    ui->zipCode->clear();

    ui->adopterSavedMessage->clear();
    ui->errorLabel2->clear();
}

void UserInfo::clearOwnerInfo(){
    ui->nameOwner->clear();
    ui->phoneNumberOwner->clear();
    ui->emailOwner->clear();
    ui->addressOwner->clear();
    ui->zipOwner->clear();

    ui->errorLabelOwner->clear();
    ui->ownerSavedMessage->clear();
}

void UserInfo::clearCreateAccount(){
    ui->username->clear();
    ui->password->clear();
    ui->passwordVerification->clear();
    ui->accountType->setCurrentIndex(0);
}
