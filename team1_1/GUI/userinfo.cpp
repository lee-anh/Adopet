#include "userinfo.h"
#include "ui_userinfo.h"

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{

    ui->setupUi(this);

    //auth = Authentication("../../../../../projectDB.sqlite");

    //starts on create account page
    ui->stackedWidget->setCurrentIndex(0);
    firstTime = true;

}

UserInfo::~UserInfo()
{
    delete ui;
}

void UserInfo::setAuth(Authentication a){
    auth = a;
    username = a.getAuthenticatedAdopter().getUsername();
}

void UserInfo::adopterMyInfoClicked(){
    ui->stackedWidget->setCurrentIndex(1);
    firstTime = false;

    ui->usernameLabel->setText("Username (unchangeable): " + QString::fromStdString(auth.getAuthenticatedAdopter().getUsername()));
    ui->passwordLabel->setText("Password (unchangeable): " + QString::fromStdString(auth.getAuthenticatedAdopter().getPassword()));
    ui->firstName->setText(QString::fromStdString(auth.getAuthenticatedAdopter().getFirstName()));
    ui->lastName->setText(QString::fromStdString(auth.getAuthenticatedAdopter().getLastName()));
    ui->emailAddress->setText(QString::fromStdString(auth.getAuthenticatedAdopter().getEmailAddress()));
    //will have to check for leading zeros here
    ui->zipCode->setText(QString::fromStdString(to_string(auth.getAuthenticatedAdopter().getZipCode())));


}

void UserInfo::on_continueButton_clicked()
{

    string uname = ui->username->text().toStdString();
    string pwd = ui->password->text().toStdString();
    string pwdVer = ui->passwordVerification->text().toStdString();
    string type = ui->accountType->currentText().toStdString();
    transform(type.begin(), type.end(), type.begin(), ::tolower);
    if(uname == "" || pwd == "" || pwdVer == ""|| type == "select one"){
        ui->errorLabel->setText("Missing field(s)");
    } else if(pwd != pwdVer){
        ui->errorLabel->setText("Passwords don't match");
    } else {
        bool b = auth.signUp(uname, pwd, type);
        if (b == true){
            //to the my info page
            if(type == "adopter"){
                ui->stackedWidget->setCurrentIndex(1);
                ui->usernameLabel->setText("Username (unchangeable): " + QString::fromStdString(username));
                ui->passwordLabel->setText("Password (unchangeable): " + QString::fromStdString(password));

            } else {
                //TODO: go to the owner's info page
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
        auth.insertAdopterToDB(username, fname, lname, email, zip);
        } else {
            Adopter a =  auth.updateAdopter(username, fname, lname, email, zip);
            emit updatedAdopter(a);
        }

    }


}

void UserInfo::on_backButton_clicked()
{
    emit backClicked();
}
