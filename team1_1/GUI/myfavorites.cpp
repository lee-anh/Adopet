#include "myfavorites.h"
#include "ui_myfavorites.h"

/*!
 * \brief MyFavorites constructor
 * \param parent
 */
MyFavorites::MyFavorites(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyFavorites)
{
    ui->setupUi(this);




}

/*!
 * \brief MyFavorites destructor
 */
MyFavorites::~MyFavorites()
{
    delete ui;
}


/*!
 * \brief setSavedList, must be used before other methods are called
 * \param s
 */
void MyFavorites::setSavedList(SavedList s){
    sl = s;
}


/*!
 * \brief showGal initalizes the pet gallery and shows it
 */
void MyFavorites::showGal(){
    //pet gall must be initalized here b/c need the right saved list
    petgal = PetGallery(4, ui->previous, ui->next, ui->pageLine, {ui->name1, ui->name2, ui->name3, ui->name4},
                        {ui->pic1, ui->pic2, ui->pic3, ui->pic4},
                        {ui->link1, ui->link2, ui->link3, ui->link4},
                        {ui->save1, ui->save2, ui->save3, ui->save4},
                        sl.getPetVec(), true);
    petgal.displayPets(0);
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});

    ui->viewModeComboBox->setCurrentIndex(1);
}


/*!
 * \brief saveButton, processes saved button actions
 * Styles saved buttons accordingly
 * \param saveButton
 * \param index
 */
void MyFavorites::saveButton(QPushButton* saveButton, int index){
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
 * \brief loadSaveButtons, renders saved buttons to be displayed
 * \param saveButtons
 */
void MyFavorites::loadSaveButtons(vector<QPushButton *> saveButtons){
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
 * \brief on_previous_clicked goes back on the pet gallery
 */
void MyFavorites::on_previous_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}

/*!
 * \brief on_next_clicked advances the pet gallery
 */
void MyFavorites::on_next_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}


/*!
 * \brief on_link1_clicked, go to meet me for first pet
 */
void MyFavorites::on_link1_clicked()
{
    emit learnMoreClicked(petgal.getPet(0), ui->save1->isChecked());
}


/*!
 * \brief on_link2_clicked, go to meet me for second pet
 */
void MyFavorites::on_link2_clicked()
{
    emit learnMoreClicked(petgal.getPet(1), ui->save2->isChecked());
}

/*!
 * \brief on_link3_clicked, go to meet me for third pet
 */
void MyFavorites::on_link3_clicked()
{
    emit learnMoreClicked(petgal.getPet(2), ui->save3->isChecked());
}


/*!
 * \brief on_link4_clicked, go to meet me for fourth pet
 */
void MyFavorites::on_link4_clicked()
{
    emit learnMoreClicked(petgal.getPet(3), ui->save4->isChecked());
}


/*!
 * \brief on_save1_clicked, save button for first pet
 */
void MyFavorites::on_save1_clicked()
{
    saveButton(ui->save1, 0);
}


/*!
 * \brief on_save2_clicked, save button for second pet
 */
void MyFavorites::on_save2_clicked()
{
    saveButton(ui->save2, 1);
}

/*!
 * \brief on_save3_clicked, save button for third pet
 */
void MyFavorites::on_save3_clicked()
{
    saveButton(ui->save3, 2);
}

/*!
 * \brief on_save4_clicked, save button for fourth pet
 */
void MyFavorites::on_save4_clicked()
{
    saveButton(ui->save4, 3);
}

/*!
 * \brief on_viewModeComboBox_currentIndexChanged
 * checks status of the combo box
 * goes to list mode if list mode is selected
 * \param index
 */
void MyFavorites::on_viewModeComboBox_currentIndexChanged(int index)
{
    //go to list mode
    if(index == 2){

        emit toListMode();
    }
}
