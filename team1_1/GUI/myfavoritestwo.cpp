#include "myfavoritestwo.h"
#include "ui_myfavoritestwo.h"

/*!
 * \brief MyFavoritesTwo constructor
 * \param parent
 */
MyFavoritesTwo::MyFavoritesTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyFavoritesTwo)
{
    ui->setupUi(this);
}

/*!
 * \brief MyFavoritesTwo destructor
 */
MyFavoritesTwo::~MyFavoritesTwo()
{
    delete ui;
}

/*!
 * \brief setSavedList, must be called once before any other
 * methods in the class are use
 * \param s, a saved List object
 */
void MyFavoritesTwo::setSavedList(SavedList s){
    sl = s;
}

/*!
 * \brief showGal shows the pet gallery
 * initializes the PetGallery object
 */
void MyFavoritesTwo::showGal(){

    //pet gall must be initalized here b/c need the right saved list
    petgal = PetGallery(true, 8, ui->previous, ui->next, ui->pageLine,
                        {ui->name1, ui->name2, ui->name3, ui->name4, ui->name5, ui->name6, ui->name7, ui->name8},
                        {ui->info1, ui->info2, ui->info3, ui->info4, ui->info5, ui->info6, ui->info7, ui->info8},
                        {ui->link1, ui->link2, ui->link3, ui->link4, ui->link5, ui->link6, ui->link7, ui->link8},
                        {ui->save1, ui->save2, ui->save3, ui->save4, ui->save5, ui->save6, ui->save7, ui->save8},
                        sl.getPetVec());

    petgal.displayPets(0);

    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4, ui->save5, ui->save6, ui->save7, ui->save8});
    ui->viewMode->setCurrentIndex(2);
}

/*!
 * \brief saveButton, processes saved button actions
 * \param saveButton, QPushButton pointer
 * \param index, index to display pet on
 */
void MyFavoritesTwo::saveButton(QPushButton* saveButton, int index){
    if(saveButton->isChecked() == false){
        sl.unsavePet(petgal.getPet(index));
        saveButton->setText("♡");
        saveButton->setStyleSheet("color: black");
        emit heartClicked(petgal.getPet(index), false);

    } else if (saveButton->isChecked() == true){
        sl.savePet(petgal.getPet(index));
        saveButton->setText("♥");
        saveButton->setStyleSheet("color: red; border: none");
        emit heartClicked(petgal.getPet(index), true);
    }
}

/*!
 * \brief loadSaveButtons, renders saved buttons to be checked or unchecked
 * \param saveButtons
 */
void MyFavoritesTwo::loadSaveButtons(vector<QPushButton *> saveButtons){
    for(int i = 0; i < (int) saveButtons.size(); i++){
        if((int) petgal.getPetVec().size() > i){
        if(sl.isSavedPet(petgal.getPet(i)) == true){
            saveButtons[i]->setChecked(true);
            saveButtons[i]->setText("♥");
            saveButtons[i]->setStyleSheet("color: red; border: none");
        } else{
            saveButtons[i]->setChecked(false);
            saveButtons[i]->setText("♡");
            saveButtons[i]->setStyleSheet("color: black");
        }
    }
    }
}

/*!
 * \brief on_previous_clicked, go back on the pet gallery
 */
void MyFavoritesTwo::on_previous_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}

/*!
 * \brief on_next_clicked, advances the pet gallery
 */
void MyFavoritesTwo::on_next_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}






/*!
 * \brief on_link1_clicked, go to meet me for first pet
 */
void MyFavoritesTwo::on_link1_clicked()
{
    emit learnMoreClicked(petgal.getPet(0), ui->save1->isChecked());
}

/*!
 * \brief on_link2_clicked, go to meet me for second pet
 */
void MyFavoritesTwo::on_link2_clicked()
{
    emit learnMoreClicked(petgal.getPet(1), ui->save2->isChecked());
}

/*!
 * \brief on_link3_clicked, go to meet me for third pet
 */
void MyFavoritesTwo::on_link3_clicked()
{
    emit learnMoreClicked(petgal.getPet(2), ui->save3->isChecked());
}

/*!
 * \brief on_link4_clicked, go to meet me for fourth pet
 */
void MyFavoritesTwo::on_link4_clicked()
{
    emit learnMoreClicked(petgal.getPet(3), ui->save4->isChecked());
}

/*!
 * \brief on_link5_clicked, go to meet me for fifth pet
 */
void MyFavoritesTwo::on_link5_clicked()
{
    emit learnMoreClicked(petgal.getPet(4), ui->save5->isChecked());
}

/*!
 * \brief on_link6_clicked, go to meet me for sixth pet
 */
void MyFavoritesTwo::on_link6_clicked()
{
    emit learnMoreClicked(petgal.getPet(5), ui->save6->isChecked());
}

/*!
 * \brief on_link7_clicked, go to meet me for seventh pet
 */
void MyFavoritesTwo::on_link7_clicked()
{
    emit learnMoreClicked(petgal.getPet(6), ui->save7->isChecked());
}

/*!
 * \brief on_link8_clicked, go to meet me for eigth pet
 */
void MyFavoritesTwo::on_link8_clicked()
{
    emit learnMoreClicked(petgal.getPet(7), ui->save8->isChecked());
}

/*!
 * \brief on_save1_clicked, save button for first pet
 */
void MyFavoritesTwo::on_save1_clicked()
{
    saveButton(ui->save1, 0);
}

/*!
 * \brief on_save2_clicked, save button for second pet
 */
void MyFavoritesTwo::on_save2_clicked()
{
    saveButton(ui->save2, 1);
}

/*!
 * \brief on_save3_clicked, save button for third pet
 */
void MyFavoritesTwo::on_save3_clicked()
{
    saveButton(ui->save3, 2);
}

/*!
 * \brief on_save4_clicked, save button for fourth pet
 */
void MyFavoritesTwo::on_save4_clicked()
{
    saveButton(ui->save4, 3);
}

/*!
 * \brief on_save5_clicked, save button for fifth pet
 */
void MyFavoritesTwo::on_save5_clicked()
{
    saveButton(ui->save5, 4);
}
/*!
 * \brief on_save6_clicked, save button for sixth pet
 */
void MyFavoritesTwo::on_save6_clicked()
{
    saveButton(ui->save6, 5);
}

/*!
 * \brief on_save7_clicked, save button for seventh pet
 */
void MyFavoritesTwo::on_save7_clicked()
{
    saveButton(ui->save7, 6);
}

/*!
 * \brief on_save8_clicked, save button for eigth pet
 */
void MyFavoritesTwo::on_save8_clicked()
{
    saveButton(ui->save8, 7);
}

/*!
 * \brief on_viewMode_currentIndexChanged, checks state of combo box
 * if gallery was selected, then switches display to gallery mode
 * \param index
 */
void MyFavoritesTwo::on_viewMode_currentIndexChanged(int index)
{
    //go to gallery mode
    if(index == 1){
        emit goToGallery();
    }
}
