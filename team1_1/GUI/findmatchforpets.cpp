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

void FindMatchForPets::forOnePet(Owner* owner){

    ui->stackedWidget->setCurrentIndex(1);

    QString os = QSysInfo::productVersion();
    cout << os.toStdString() << endl;

    string dbName;
    if(os == "10.16"){
        dbName = "../../../../../projectDB.sqlite";
    } else {
        dbName = "../../projectDB.sqlite";

    }
    mat = Matchmaking(dbName, "temp username");
    mat.fillPets();
    //load all the choices into the combo box
    owner->fillPets();
    for(int i = 0; i < (int) owner->getPets().size(); i++){
        ui->petComboBox->addItem(QString::fromStdString(owner->getPets().at(i).getName()).toUpper(), owner->getPets().at(i).getID());
    }
    //load all the labels (like a constructor)
    nameLabels = {ui->name1, ui->name2, ui->name3, ui->name4, ui->name5};
    infoLabels = {ui->email1, ui->email2, ui->email3, ui->email4, ui->email5};
    scoreLabels = {ui->match1, ui->match2, ui->match3, ui->match4, ui->match5};

    numToDisplay = 5;


}


void FindMatchForPets::displayPeople(int start){

    int counter = 0;
    ui->previousOne->setVisible(true);
    ui->nextOne->setVisible(true);

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

void FindMatchForPets::next(){
    if(nextStartIndex + 1 < (int) matResults.size()){
        displayPageNumber++;
        nextStartIndex++;
        displayPeople(nextStartIndex);

    }
}

void FindMatchForPets::previous(){
    int startMod =  nextStartIndex % numToDisplay;
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
}

void FindMatchForPets::setPageNum(int p){
    displayPageNumber = p;
}



void FindMatchForPets::on_searchOne_clicked()
{

    displayPageNumber = 1;

    matResults = mat.findMatchesForPet(ui->petComboBox->currentData().toInt());
    cout << matResults.size() << endl;
    displayPeople(0);

}

void FindMatchForPets::on_previousOne_clicked()
{
    previous();
}

void FindMatchForPets::on_nextOne_clicked()
{
    next();
}
