#include "findmatchforpets.h"
#include "ui_findmatchforpets.h"

FindMatchForPets::FindMatchForPets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindMatchForPets)
{
    ui->setupUi(this);
}

FindMatchForPets::~FindMatchForPets()
{
    delete ui;
}

void FindMatchForPets::toMainPage(Owner *owner){
    ui->stackedWidget->setCurrentIndex(0);
    currentOwner = owner;
}


void FindMatchForPets::setup(){


    QString os = QSysInfo::productVersion();

    string dbName;
    if(os == "10.16"){
        dbName = "../../../../../projectDB.sqlite";
    } else {
        dbName = "../../projectDB.sqlite";

    }
    mat = Matchmaking(dbName, "temp username");
    mat.fillPets();

}
void FindMatchForPets::forOnePet(Owner* owner){

    ui->stackedWidget->setCurrentIndex(1);
    mode = "one";

    setup();
    //load all the choices into the combo box
    owner->fillPets();

    /*
    for(int i = 0; i < (int) owner->getPets().size(); i++){
        ui->petComboBox->addItem(QString::fromStdString(owner->getPets().at(i).getName()).toUpper(), owner->getPets().at(i).getID());
    }
    */

    QStringList wordList;
    for(int i = 0; i < (int) owner->getPets().size(); i++){
       QString s =  QString::fromStdString(owner->getPets().at(i).getName()).toUpper() + ",  ID:" + QString::number(owner->getPets().at(i).getID());
       wordList << s;
       QString sPlus  = " " + s;
       wordList << sPlus;
    }


    QCompleter* completer = new QCompleter(wordList, ui->petName);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->petName->setCompleter(completer);

    ui->petName->clear();



    //load all the labels (like a constructor)
    nameLabels = {ui->name1, ui->name2, ui->name3, ui->name4, ui->name5};
    infoLabels = {ui->email1, ui->email2, ui->email3, ui->email4, ui->email5};
    scoreLabels = {ui->match1, ui->match2, ui->match3, ui->match4, ui->match5};

    clearAll();
    displayPageNumber = 1;
    numToDisplay = 5;


}

void FindMatchForPets::forMultiPets(Owner *owner){
    ui->stackedWidget->setCurrentIndex(2);
    mode = "all";
    setup();

    nameLabels = {ui->name1a, ui->name2a, ui->name3a, ui->name4a, ui->name5a, ui->name6a, ui->name7a, ui->name8a};
    infoLabels = {ui->email1a, ui->email2a, ui->email3a, ui->email4a, ui->email5a, ui->email6a, ui->email7a, ui->email8a};
    scoreLabels = {ui->match1a, ui->match2a, ui->match3a, ui->match4a, ui->match5a, ui->match6a, ui->match7a, ui->match8a};
    petNameLabels = {ui->pname1, ui->pname2, ui->pname3, ui->pname4, ui->pname5, ui->pname6, ui->pname7, ui->pname8};

    numToDisplay = 8;
    displayPageNumber = 1;
    multiMat = mat.findMatchesForPets(owner->getName());

    displayPeopleMulti(0);
}


void FindMatchForPets::displayPeople(int start){

    int counter = 0;
    ui->previousOne->setVisible(true);
    ui->nextOne->setVisible(true);
    ui->name->setVisible(true);
    ui->email->setVisible(true);
    ui->match->setVisible(true);

    for(int i = 0; i < numToDisplay; i++){
        nameLabels[i]->clear();
        infoLabels[i]->clear();
        scoreLabels[i]->clear();



        if(start < (int) matResults.size()){
            //TODO: first name
            nameLabels[i]->setText(QString::fromStdString(matResults.at(start).first.getUsername()));
            infoLabels[i]->setText(QString::fromStdString(matResults.at(start).first.getEmailAddress()));
            scoreLabels[i]->setText(QString::number(matResults.at(start).second) + "% match");
        }
        start++;
        counter++;
    }

    nextStartIndex = start - 1;

    int numOfPages = ceil(matResults.size()/(numToDisplay*1.0));

    if(counter == 0){
        ui->pageLine->setText("No adopter match your search");
    } else {
        ui->pageLine->setText("Showing page " + QString::number(displayPageNumber) + " out of "
             + QString::number(numOfPages));
    }

}

void FindMatchForPets::displayPeopleMulti(int start){
    int counter = 0;
    ui->previousAll->setVisible(true);
    ui->previousOne->setVisible(true);


    for(int i = 0; i < numToDisplay; i++){
        nameLabels[i]->clear();
        infoLabels[i]->clear();
        scoreLabels[i]->clear();
        petNameLabels[i]->clear();

        if(start < (int) multiMat.size()){
            petNameLabels[i]->setText(QString::fromStdString(multiMat.at(start).first.getName()).toUpper());
            nameLabels[i]->setText(QString::fromStdString(multiMat.at(start).second.first.getFirstName()));
            infoLabels[i]->setText(QString::fromStdString(multiMat.at(start).second.first.getEmailAddress()));
            scoreLabels[i]->setText(QString::number(multiMat.at(start).second.second) + "% match");

        }
        start++;
        counter++;

    }
    nextStartIndex = start - 1;

    int numOfPages = ceil(multiMat.size()/(numToDisplay*1.0));

    if(counter == 0){
        ui->pageLineAll->setText("No adopter match your search");
    } else {
        ui->pageLineAll->setText("Showing page " + QString::number(displayPageNumber) + " out of "
             + QString::number(numOfPages));
    }
}

void FindMatchForPets::next(){
    if(mode == "one"){
        if(nextStartIndex + 1 < (int) matResults.size()){
            displayPageNumber++;
            nextStartIndex++;
            displayPeople(nextStartIndex);

        }
    } else {
        if(nextStartIndex + 1 < (int) multiMat.size()){
            displayPageNumber++;
            nextStartIndex++;
            displayPeopleMulti(nextStartIndex);
        }
    }
}

void FindMatchForPets::previous(){
    int startMod =  nextStartIndex % numToDisplay;

    if(mode == "one"){

        if(nextStartIndex - numToDisplay < 0){
            displayPageNumber = 1;
            displayPeople(0);

        } else {
            nextStartIndex = nextStartIndex - numToDisplay - startMod;
            if(displayPageNumber - 1 > 0){
                displayPageNumber--;
            } else{
                displayPageNumber = 1;
            }
            displayPeople(nextStartIndex);

        }
    } else {
        if(nextStartIndex - numToDisplay < 0){
            displayPageNumber = 1;
            displayPeopleMulti(0);

        } else {
            nextStartIndex = nextStartIndex - numToDisplay - startMod;
            if(displayPageNumber - 1 > 0){
                displayPageNumber--;
            } else{
                displayPageNumber = 1;
            }
            displayPeopleMulti(nextStartIndex);

        }
    }
}

void FindMatchForPets::setPageNum(int p){
    displayPageNumber = p;
}

void FindMatchForPets::clearAll(){
    for(int i = 0; i < (int) nameLabels.size(); i++){
        nameLabels.at(i)->clear();
    }
    for(int i = 0; i < (int) scoreLabels.size(); i++){
        scoreLabels.at(i)->clear();

    }
    for(int i = 0; i < (int) infoLabels.size(); i++){
        infoLabels.at(i)->clear();
    }

    for(int i = 0; i < (int) petNameLabels.size(); i++){
        petNameLabels.at(i)->clear();
    }

    ui->pageLine->clear();
    ui->pageLineAll->clear();

    ui->previousOne->setVisible(false);
    ui->nextOne->setVisible(false);

    ui->name->setVisible(false);
    ui->email->setVisible(false);
    ui->match->setVisible(false);

}



void FindMatchForPets::on_searchOne_clicked()
{

    displayPageNumber = 1;

    string toParse = ui->petName->text().toStdString();
    string idString;
    int counter = 0;
    for(int i = 0; i < (int)toParse.size(); i++){
        if(counter > 0){
            idString  = idString + toParse[i];
        }
        if(toParse[i] == ':'){
            counter++;
        }

    }

    if (idString.size() > 0){
        int id = stoi(idString);

        matResults = mat.findMatchesForPet(id);
        displayPeople(0);
    } else {
       ui->pageLine->setText("No animal matched your search.");
    }



}

void FindMatchForPets::on_previousOne_clicked()
{
    previous();
}

void FindMatchForPets::on_nextOne_clicked()
{
    next();
}

void FindMatchForPets::on_previousAll_clicked()
{
    previous();
}

void FindMatchForPets::on_nextAll_clicked()
{
    next();
}

void FindMatchForPets::on_toAllPets_clicked()
{
    forMultiPets(currentOwner);
}

void FindMatchForPets::on_toOnePet_clicked()
{
    forOnePet(currentOwner);
}
