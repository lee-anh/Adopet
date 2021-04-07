#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);
    ui->linkToResult1->setVisible(false);
    ui->linkToResult2->setVisible(false);
    ui->linkToResult3->setVisible(false);
    search = new DBSearch("../../../../../projectDB.sqlite");

    //JUST FOR NOW
    ui->stackedWidget->setCurrentIndex(1);
    previousPage = 1;


}

GUI::~GUI()
{
    delete ui;
    delete search;
}

void GUI::on_searchButton_clicked()
{

    QString searchInput = ui->searchBar->text();
    string searchString = searchInput.toStdString();
    search->search(searchString);
    search->runNewQuery();

    nextDisplayPetsStartIndex = 0;
    displayPetsPageNumber = 1;

    displayPets(0);



}



void GUI::displayPets(int start){
    clearLabels();
    int counter = 0;

    QPixmap pixmap("../../../../../pictures/default.png");


    //displayedPet1
    if(start < search->getPetVecSize()){
        displayedPet1 = search->getPetVec().at(start);
        string s = displayedPet1.getName();
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        QString qpet1 = QString::fromStdString(s);

        ui->results1->setText(qpet1);
        ui->results1pic->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        ui->linkToResult1->setVisible(true);
        counter++;
        start++;

    }


    //displayedPet2

    if(start < search->getPetVecSize()){
        displayedPet2 = search->getPetVec().at(start);
        string s2 = displayedPet2.getName();
        transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
        QString qpet2 = QString::fromStdString(s2);

        ui->results2->setText(qpet2);
        ui->results2pic->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        ui->linkToResult2->setVisible(true);
        counter++;
        start++;

    }



    //displayedPet3

    if(start < search->getPetVecSize()){
        displayedPet3 = search->getPetVec().at(start);
        string s3 = displayedPet3.getName();
        transform(s3.begin(), s3.end(), s3.begin(), ::toupper);
        QString qpet3 = QString::fromStdString(s3);

        ui->results3->setText(qpet3);
        ui->results3pic->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        ui->linkToResult3->setVisible(true);
        counter++;
    }

    nextDisplayPetsStartIndex = start;


    int numOfPages = ceil(search->getPetVecSize()/3.0);
    if(counter == 0){
        ui->numOfResults->setText("No animals match your search");
    } else {

        ui->numOfResults->setText("Showing page " +
             QString::number(displayPetsPageNumber) + " out of "
             + QString::number(numOfPages));
    }
}

void GUI::meetPet(Pet p){
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
            sep + p.getAge() + "\n" + p.getSize() + sep + p.getGender()
            + sep + "good with " + p.getGoodWith();
    QString qattributes = QString::fromStdString(attributes);
    ui->petAttributes->setText(qattributes);

    //set bio
    string bio = p.getBio();
    QString qbio = QString::fromStdString(bio);
    ui->petBio->setText(qbio);

    //TODO - shelter info and link to shelter bio



}

//blind clearing right now
void GUI::clearLabels(){
    ui->results1->clear();
    ui->results1pic->clear();
    ui->results2->clear();
    ui->results2pic->clear();
    ui->results3->clear();
    ui->results3pic->clear();
    ui->numOfResults->clear();
    ui->linkToResult1->setVisible(false);
    ui->linkToResult2->setVisible(false);
    ui->linkToResult3->setVisible(false);

    ui->numOfResults->setText("No animals match your search");
}


void GUI::checkBoxSearch(string wordToSearch, string category, int arg1){
    // 0 unchecked
    // 1 partially checked
    // 2 checked
    if(arg1 == 2){
        search->addToAttributes(wordToSearch, category);


    } else if (arg1 == 0){
        search->removeFromAttributes(wordToSearch, category);
    }


    search->runNewQuery();

    nextDisplayPetsStartIndex = 0;
    displayPetsPageNumber = 1;

    displayPets(0);

}



void GUI::on_dogCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("dog", "species", arg1);
}

void GUI::on_catCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("cat", "species", arg1);
}

void GUI::on_rabbitCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("rabbit","species", arg1);
}

void GUI::on_rodentCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("rodent", "species", arg1);
}


void GUI::on_fishCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("fish", "species", arg1);
}

void GUI::on_birdCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("bird", "species", arg1);
}



void GUI::on_linkToResult1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    meetPet(displayedPet1);
    previousPage = 1;

}

void GUI::on_linkToResult2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    meetPet(displayedPet2);
    previousPage = 1;

}

void GUI::on_linkToResult3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    meetPet(displayedPet3);
    previousPage = 1;
}



void GUI::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(previousPage);
}

void GUI::on_loadNext_clicked()
{

    if(nextDisplayPetsStartIndex+1 < (int) search->getPetVecSize()){
        displayPetsPageNumber++;
        nextDisplayPetsStartIndex++;
        displayPets(nextDisplayPetsStartIndex);
    }
}

void GUI::on_loadPrevious_clicked()
{

    int startMod =  nextDisplayPetsStartIndex % 3;
    if(nextDisplayPetsStartIndex - 3 < 0){
        displayPetsPageNumber = 1;
        displayPets(0);
    } else {
        nextDisplayPetsStartIndex = nextDisplayPetsStartIndex- 3 - startMod;
        if(displayPetsPageNumber - 1 > 0)
            displayPetsPageNumber--;
        else
            displayPetsPageNumber = 1;
        displayPets(nextDisplayPetsStartIndex);
    }
}
