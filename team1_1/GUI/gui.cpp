#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);

    search = new DBSearch("../../../../../projectDB.sqlite");
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
    displayPets(0);



}



void GUI::displayPets(int start){
    clearLabels();
    if(start >= search->getPetVecSize()){
        return;
    }

    QPixmap pixmap("../../../../../pictures/default.png");

    string s = search->getPetVec().at(start).getName();
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    QString qpet1 = QString::fromStdString(s);

    ui->results1->setText(qpet1);
    ui->results1pic->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));

    start++;
    if(start >= search->getPetVecSize()){
        return;
    }

    string s2 = search->getPetVec().at(start).getName();
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    QString qpet2 = QString::fromStdString(s2);

    ui->results2->setText(qpet2);
    ui->results2pic->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));

    start++;
    if(start >= search->getPetVecSize()){
        return;
    }

    string s3 = search->getPetVec().at(start).getName();
    transform(s3.begin(), s3.end(), s3.begin(), ::toupper);
    QString qpet3 = QString::fromStdString(s3);

    ui->results3->setText(qpet3);
    ui->results3pic->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));

    ui->numOfResults->setText("Showing 3 out of " +
                              QString::number(search->getPetVecSize()) +
                              " results");

}

void GUI::checkBoxSearch(string wordToSearch, int arg1){
    if(arg1 == 2){
        search->search(wordToSearch);
        displayPets(0);


    } else {
        clearLabels();
    }

}

void GUI::clearLabels(){
    ui->results1->clear();
    ui->results1pic->clear();
    ui->results2->clear();
    ui->results2pic->clear();
    ui->results3->clear();
    ui->results3pic->clear();
    ui->numOfResults->clear();
}

//right now multiple checks aren't appending
void GUI::on_dogCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("dog", arg1);
}

void GUI::on_catCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("cat", arg1);
}

void GUI::on_rabbitCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("rabbit", arg1);
}

void GUI::on_rodentCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("rodent", arg1);
}


void GUI::on_fishCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("fish", arg1);
}

void GUI::on_birdCheckBox_stateChanged(int arg1)
{
    checkBoxSearch("bird", arg1);
}
